//开公司
#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
const int DAY=5e4;
#define ls (pos<<1)
#define rs (pos<<1|1)

double B[N+10],K[N+10];                    //B是与y轴交点,K是斜率
int Lazy[N*4+10];                          //标记用于保存直线编号

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

bool Check(int a,int b,int x)              //比较两直线在第x天的y值
{
  return K[a]*(x-1)+B[a]>K[b]*(x-1)+B[b];
}

void Update(int pos,int l,int r,int index)
{
  if (l==r)                               //如果为叶子结点
  {
    if (Check(index,Lazy[pos],l))         //如果新插入的直线更优
      Lazy[pos]=index;                    //更新lazy为新直线
    return;
  }
  int mid=(l+r)>>1;
  if (K[index]>K[Lazy[pos]])              //新插入直线斜率大于原先标记
    if (Check(index,Lazy[pos],mid))       //新插入直线在mid更优
    {
      Update(ls,l,mid,Lazy[pos]);         //原来的lazy继续更新左区间
      Lazy[pos]=index;                    //更新当前lazy为新直线
    }
    else
      Update(rs,mid+1,r,index);           //右区间用新直线更新
  if (K[index]<K[Lazy[pos]])              //新插入直线斜率小于原先标记
    if (Check(index,Lazy[pos],mid))       //原理同上，略
    {
      Update(rs,mid+1,r,Lazy[pos]);
      Lazy[pos]=index;
    }
    else
      Update(ls,l,mid,index);
}

double GetY(int a,int x)                  //获取第x天的获益值
{
  return K[a]*(x-1)+B[a];
}

double Query(int pos,int l,int r,int T)
{
  if (l==r)
    return GetY(Lazy[pos],T);
  int mid=(l+r)>>1;
  double ans=GetY(Lazy[pos],T);           //一路更新答案
  if (T<=mid)
    ans=max(ans,Query(ls,l,mid,T));
  else
    ans=max(ans,Query(rs,mid+1,r,T));
  return ans;
}

int main()
{
  freopen("company.in","r",stdin);
  freopen("company.out","w",stdout);
  int n=Read(),index=1;
  char s[10];
  for (int i=1; i<=n; i++)
  {
    scanf("%s",s+1);
    if (s[1]=='P')
    {
      scanf("%lf%lf",&B[index],&K[index]);
      Update(1,1,DAY,index++);
    }
    else
      printf("%d\n",int(Query(1,1,DAY,Read()))/100);
  }
  return 0;
}
