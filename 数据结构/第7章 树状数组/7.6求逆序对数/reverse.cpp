//��״�����������
#include <bits/stdc++.h>
using namespace std;

int t[10000000];
int n,ans=0;

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

struct node
{
  int id,val,p;                      //��ţ���ʼֵ����ɢ�������ֵ
} a[1001];

bool Cmp1(node a,node b)
{
  return a.val<b.val;
}

bool Cmp2(node a,node b)
{
  return a.id<b.id;
}

inline void Modify(int k)           //inline��ʾ��������,������
{
  for(; k<=n; k+=(-k)&k)
    t[k]++;                         //������һ
}

int GetSum(int k)                   //���
{
  int sum=0;
  for(; k>0; k-=(-k)&k)
    sum+=t[k];
  return sum;
}

int main()
{
  //freopen("reverse.in","r",stdin);
  //freopen("reverse.out","w",stdout);
  n=Read();
  for(int i=1; i<=n; ++i)
  {
    a[i].val=Read();
    a[i].id=i;                      //���
  }
  sort(a+1,a+n+1,Cmp1);             //��ֵ����
  a[0].val=-9999999;
  for(int i=1; i<=n; i++)
  {
    if(a[i].val==a[i-1].val)
      a[i].p=a[i-1].p;              //��ͬ��ʼֵ�Ĵ���
    else
      a[i].p=i;                     //�Գ�ʼֵ��ɢ��
  }
  sort(a+1,a+n+1,Cmp2);             //���������
  for(int i=1; i<=n ; ++i)
  {
    Modify(a[i].p);
    ans+=i-GetSum(a[i].p);
  }
  printf("%d\n",ans);
  return 0;
}

