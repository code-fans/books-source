//����Ƹ߾��ȳ���
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5100
#define limit 5000

struct BigNum
{
  int data[MAXN/4+1];
  int frac[MAXN/4+1];
  int &operator[](int n)                //����[]
  {
    return data[n];
  }
  int &operator()(int n)                //����()
  {
    return frac[n];
  }
  BigNum()
  {
    memset(data,0,sizeof(data));
    data[0]=1;
    data[1]=0;
    frac[0]=0;
  }
};

void Output(BigNum x)                   //����߾�����
{
  int t=x[x[0]],s=0;
  if(t/1000!=0)
    s=4;
  else if(t/100!=0)
    s=3;
  else if(t/10!=0)
    s=2;
  else
    s=1;
  printf("%d",x[x[0]]);
  for(int i=x[0]-1; i>0; i--)
    printf("%04d",x[i]),s+=4;

  if(x(0)!=0)                            //���С��
  {
    printf(".");
    for(int i=1; i<=x(0); i++)
    {
      if(limit-s<5 || i==x(0))
      {
        int t=1000,k=1;
        for(int j=s+1; j<=limit && (i!=x(0) || x(i)%t!=0); j++)
          t/=10,k++;
        printf("%0*d",k,x(i)/t);
        break;
      }
      else
        printf("%04d",x(i)),s+=4;
    }
  }
}

BigNum Init(string n)                    //���ַ���ת��Ϊ�߾�����
{
  BigNum x;
  int len=n.size(),t=1;
  for(int i=len-1; i>=0; i--)
  {
    if(t==10000)
    {
      t=1;
      x[0]++;
    }
    x[x[0]]+=(n[i]-'0')*t;
    t*=10;
  }
  return x;
}

BigNum Sub(BigNum &a,BigNum &b)          //����,�˴�Ĭ��a>b,��Ҫ��������
{
  BigNum c;
  int i;
  for(i=1; i<=a[0]; i++)
  {
    c[i]+=a[i]-b[i];
    c[i+1]=0;
    if(c[i]<0)
    {
      c[i]+=10000;
      c[i+1]--;
    }
    if(c[i]!=0)
      c[0]=i;
  }
  return c;
}

BigNum Mul(BigNum &a,int &b)              //�߾���*�;���
{
  BigNum c;
  for(int i=1; i<=a[0]; i++)
  {
    c[i]+=a[i]*b;
    c[i+1]=c[i]/10000;
    c[i]%=10000;
  }
  c[0]=a[0]+(c[a[0]+1]!=0);
  return c;
}

BigNum result[10000];
bool saved[10000];

BigNum Dichotomy(BigNum &a,BigNum &b,int &k)//�����Գ�,ֱ�ӷ�������
{
  int L=1,R=9999;
  while(L<=R)
  {
    int m=(L+R)/2;
    if(saved[m]==0)                         //��b*m��ֵ���������Ա��´�����
    {
      saved[m]=1;
      result[m]=Mul(b,m);
    }
    /*����Ϊ�Ƚ�b*m��a  ��b*m>a��t=1����b*m<a��t=-1����b*m==a��t=0*/
    int t=0;
    if(result[m][0]>a[0])
      t=1;
    else if(result[m][0]<a[0])
      t=-1;
    else
    {
      for(int i=result[m][0]; t==0 && i>0; i--)
        if(result[m][i]>a[i])
          t=1;
        else if(result[m][i]<a[i])
          t=-1;
    }
    t>0?R=m-1:L=m+1;
  }
  k=L-1;
  return Sub(a,result[k]);              //����Ϊa-b*k
}

BigNum Div(BigNum &a,BigNum &b)
{
  BigNum c,t;                            //cΪa/b�Ľ��,tΪ��ʱ����,���ڴ洢����
  int i,j;

  /*��������*/
  if(a[0]>=b[0])
  {
    for(i=a[0]-b[0]+1; i<=a[0]; i++)    //ȡaǰb[0]λ��t
      t[i-a[0]+b[0]]=a[i];
    t[0]=b[0];
    i=a[0]-b[0]+1;
    c[0]=i;
    do
    {
      t=Dichotomy(t,b,c[i]);
      if(i==c[0] && c[i]==0)           //�������aȡǰb[0]λ����С��b�����
        c[0]--;
      i--;
      if(i<1)
        break;
      for(j=++t[0]; j>1; j--)
        t[j]=t[j-1];
      t[1]=a[i];
      if(t[t[0]]==0)
        t[0]--;
    }
    while(1);
    if(c[0]==0)
      c[0]=1;
  }
  else
    t=a;

  /*С������*/
  for(c(0)=1; c(0)<MAXN/4+1 && !(t[0]==1 && t[1]==0); ++c(0))
  {
    for(j=++t[0]; j>1; j--)
      t[j]=t[j-1];
    t[1]=0;
    t=Dichotomy(t,b,c(c(0)));
  }
  c(0)--;
  return c;
}

int main()
{
  freopen("div.in","r",stdin);
  freopen("div.out","w",stdout);
  string a,b;
  cin>>a>>b;
  BigNum m,n;
  m=Init(a);
  n=Init(b);
  if(n[0]==1 && n[1]==0)
    cout<<"Divisor is 0";
  else
    Output(Div(m,n));
  cout<<'\n';
  return 0;
}

