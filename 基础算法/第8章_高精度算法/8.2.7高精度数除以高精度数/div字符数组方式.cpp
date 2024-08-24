//�߾��������߾����������ö�������
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5500

int a[MAXN],b[MAXN],ans[MAXN];          //a[]������,b[]����,ans[]��
int now[MAXN];                        //now[]���������ڱ�������
int dot=0;                           //С����λ��

int Bigger(int x[],int y[])          //�Ƚ�x[]��y[]��С,����ֵΪ1,-1,0
{
  if(x[0]>y[0])                      //��x[]λ����y[]λ���࣬����1
    return 1;
  if(x[0]<y[0])                      //��x[]λ����y[]λ���٣�����-1
    return -1;
  for(int i=x[0]; i>=1; i--)         //���λ����ȣ��������ֱȽ�
    if(x[i]!=y[i])
      return x[i]>y[i]?1:-1;
  return 0;                          //�����ȣ�����0
}

void Copy(int x[],int y[])           //��x[]���Ƹ�y[]
{
  memcpy(y,x,sizeof(int)*MAXN);
}

void Mul(int x[],int k)              //����߾���x[]�˵;���k������0<=k<=9
{
  for(int i=1; i<=x[0]; i++)         //�˷�����
    x[i]*=k;
  for(int i=1; i<=x[0]; i++)           //�Դ��ڵ���10������Ԫ�ؽ�������
    if(x[i]>=10)
      x[i+1]+=x[i]/10,x[i]%=10;
  for(x[0]++; x[x[0]]==0; x[0]--); //����ȷ��λ��
}

void Sub(int x[],int y[])            //����x[]��y[]�Ĳ�
{
  for(int i=1; i<=y[0]; i++)
    x[i]-=y[i];
  for(int i=1; i<x[0]; i++)
    if(x[i]<0)
    {
      x[i]+=10;
      x[i+1]--;
    }
  for(; x[x[0]]==0 && x[0]>=1; x[0]--); //����ȷ��λ��
}

void Div()
{
  int tmp[MAXN];
  int point=min(b[0],a[0]);              //point��ʾ�������Ѿ������ڼ�λ
  for(int k=a[0]-point+1,i=1; i<=point; i++,k++)
    now[i]=a[k];                     //���׼��Ҫ��������
  now[0]=point;
  while(ans[0]<5050 && !(now[0]==1 && now[1]==0 && point>=a[0]))//���ַ�
  {
    int mid,l=0,r=9,k;
    while(l<=r)
    {
      mid=(l+r)>>1;
      Copy(b,tmp);                   //�˴��Ϻ�ʱ
      Mul(tmp,mid);                  //����tmp[]*mid��ֵ
      int g=Bigger(now,tmp);         //�Ƚ��Գ���Ĵ�С
      if(g==1)
      {
        k=mid;
        l=mid+1;
      }
      else if(g==-1)
        r=mid-1;
      else
      {
        k=mid;
        break;
      }
    }
    Copy(b,tmp);
    Mul(tmp,k);   //�ҵ�Kֵ�󣬼����̣����õ�������
    Sub(now,tmp);                    //��������
    ans[++ans[0]]=k;                 //������

    //����������10��
    ++now[0];                        //λ����1
    for(int i=now[0]; i>=2; i--)     //����ǰ��һλ��������10��
      now[i]=now[i-1];
    if( point<a[0] )                 //�������绹����û��ȡ�꣬�����ȡ��һλ��
      now[1]=a[a[0]-point],point++;
    else
    {
      now[1]=0;
      if(dot==0 && !(now[0]==1 && now[1]==0))//����������������һ�������
        dot=ans[0];                  //ȷ��С����
    }
  }
}

void Output()                        //������
{
  int k=1,i;
   if(dot!=0)                         //��С��
  {
    for(; ans[k]==0 && dot>k; k++);  //ɾȥǰ����
    for(i=k; i<=dot; i++)
      cout<<ans[i];
    for(cout<<"."; i<=ans[0] && i-k+1<=5000; i++) //�������λ��Ϊ5000
      cout<<ans[i];
  }
  else                               //û��С��
  {
    for(; ans[k]==0 && ans[0]>k; k++);//ɾȥǰ����
    for(; k<=ans[0]; k++)
      cout<<ans[k];
  }
  cout<<endl;
}

void CheckZero()                     //�������߱�����Ϊ�㵥������
{
  if(b[0]==1 && b[1]==0)
  {
    cout<<"Divisor is 0"<<endl;
    exit(0);
  }
  if(a[0]==1 && a[1]==0)
  {
    cout<<0<<endl;
    exit(0);
  }
}

void Init(string tmp,int a[])        //�ַ���תΪ��������
{
  a[0]=tmp.size();                   //��0λԪ�ر���λ��
  for(int i=a[0]-1; i>=0; i--)
    a[a[0]-i]=tmp[i]-'0';            //��1234560��7λ��������Ϊ70654321000...000
}

int main()
{
  //freopen("div.in","r",stdin);
  //freopen("div.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  Init(s1,a);                        //�ַ���ת����
  Init(s2,b);
  CheckZero();                       //����Ƿ�����򱻳���Ϊ0
  Div();                             //��������
  Output();
  return 0;
}

