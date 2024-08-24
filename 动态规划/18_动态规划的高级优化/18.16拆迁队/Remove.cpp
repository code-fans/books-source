#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;

long long d[MAXN],g[MAXN];
int tmp[MAXN],f[MAXN],a[MAXN],b[MAXN],c[MAXN];
struct node
{
  long long ci, di_gi;                //ci:c[i],di_gi:d[i]+g[i]
  bool operator>(const node b) const  //�Ƚ�б��
  {
    return di_gi*b.ci>ci*b.di_gi;
  }
};

node Slope(node a,node b)             //б��
{
  return node {a.ci-b.ci,a.di_gi-b.di_gi};
}

bool Cmp(int x,int y)
{
  return c[x]^c[y]?c[x]<c[y]:x<y;
}

void Cdq(int l,int r)
{
  if(l==r)
    return;
  int mid=l+r>>1;
  Cdq(l,mid);                 //ǰ�벿���ȵݹ�
  int cnt=0,FMaxDP=-1;
  for(int i=l; i<=r; ++i)
    tmp[++cnt]=i;
  sort(tmp+1,tmp+cnt+1,Cmp);  //��c[]����,����ߵ�б���Ż��ǽ�����c[k]<c[j]
  vector<node>v;
  for(int i=1,j; i<=cnt; ++i)
  {
    j=tmp[i];
    if(j<=mid)                //����c[k]<c[j]�����Խ���б���Ż�
    {
      if(f[j]<FMaxDP || (j && f[j]==0))//�����޷�����������
        continue;
      if(f[j]>FMaxDP)         //�ҵ����ŵ�f[i]
      {
        FMaxDP=f[j];          //f[i]�ҵ����ŵ�
        v.clear();            //����ĳЩ���ӵ�״̬������,����Ҫά��ȫ�µ���͹��
      }
      node p= {c[j],d[j]+g[j]};
      while(v.size()>=2 && Slope(v[v.size()-1],v[v.size()-2])>Slope(p,v[v.size()-1]))
        v.pop_back();        //����ǰ���б��ʽɾ����
      v.push_back(p);
    }
    else    //ǰ�벿�ֶԺ�벿�ֱ���j<i��c[j]<=c[i]����������DPת��
    {
      if(f[j]<FMaxDP+1)  //���f[i]�и���ֵ����ǰ���ת����Ч
      {
        f[j]=FMaxDP+1;   //f[i]ֱ������ǰ���Maxfdp,ǿ����f[i]=f[j]+1
        g[j]=5e18;
      }
      else if(f[j]>FMaxDP+1)         //�������ֵ���Ͳ�ת����
        continue;
      int L=0,R=v.size()-1,k1,k2;
      while(L+2<R)        //����ά��������͹������������ȷ�����ž��ߵ㷶Χ
      {
        k1=L+(R-L+1)/3;
        k2=R-(R-L+1)/3;
        v[k1].ci*j+v[k1].di_gi<=v[k2].ci*j+v[k2].di_gi ? R=k2 : L=k1;
      }
      for(; L<=R; ++L)               //���ҵ��������и��¸��Ŵ�
        g[j]=min(g[j],v[L].ci*j+v[L].di_gi+j*1ll*(j-1)/2+a[j]+b[j]);
    }
  }
  Cdq(mid+1,r);                      //�ݹ����
}

int main()
{
  long long n,F=0,G=0;
  scanf("%lld",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);               //���뷿�ӵ����۳̶�
  for(int i=1; i<=n; ++i)
  {
    scanf("%d",&b[i]);               //���뷿�ӵ��⳥��
    c[i]=a[i]-i;                     //����c[i]
    d[i]=i*(i+1)/2-a[i]*i-a[i];      //����d[i]
    g[i]=5e18;                       //��С������Ϊ���ֵ
  }
  Cdq(0,n);                          //CDQ����
  for(int i=1; i<=n; ++i)            //�����
    if(f[i]>F)                       //��ԭ���Ĵ��Ҫ�������Ž�
      F=f[i],G=g[i]+(n-i)*(n-i+1ll)/2+(n-i)*1ll*a[i];
    else if(f[i]==F)                 //��ͬ�Ľ����Ҹ���
      G=min(G, g[i]+(n-i)*(n-i+1ll)/2+(n-i)*1ll*a[i]);
  printf("%lld %lld\n",F,G);
  return 0;
}

