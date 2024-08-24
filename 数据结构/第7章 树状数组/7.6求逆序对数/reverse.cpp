//树状数组求逆序对
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
  int id,val,p;                      //编号，初始值，离散化后的新值
} a[1001];

bool Cmp1(node a,node b)
{
  return a.val<b.val;
}

bool Cmp2(node a,node b)
{
  return a.id<b.id;
}

inline void Modify(int k)           //inline表示内联函数,可提速
{
  for(; k<=n; k+=(-k)&k)
    t[k]++;                         //个数加一
}

int GetSum(int k)                   //求和
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
    a[i].id=i;                      //编号
  }
  sort(a+1,a+n+1,Cmp1);             //按值排序
  a[0].val=-9999999;
  for(int i=1; i<=n; i++)
  {
    if(a[i].val==a[i-1].val)
      a[i].p=a[i-1].p;              //相同初始值的处理
    else
      a[i].p=i;                     //对初始值离散化
  }
  sort(a+1,a+n+1,Cmp2);             //按编号排序
  for(int i=1; i<=n ; ++i)
  {
    Modify(a[i].p);
    ans+=i-GetSum(a[i].p);
  }
  printf("%d\n",ans);
  return 0;
}

