//写作业
#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int a[N],q[N],f[N],n,t;

int Judge(int lim)
{
  int head=0,tail=0;
  for(int i=1; i<=n; i++)
  {
    for(; head<=tail && q[head]<i-lim-1; head++);//维护区间长度
    f[i]=f[q[head]]+a[i];
    for(; head<=tail && f[q[tail]]>=f[i]; tail--);//维护单调性
    q[++tail]=i;
  }
  for(int i=n-lim; i<=n; i++)
    if(f[i]<=t)
      return 1;
  return 0;
}

int main()
{
  freopen("homework.in","r",stdin);
  freopen("homework.out","w",stdout);
  cin>>n>>t;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  int l=0,r=n;
  while(l<r)
  {
    int mid=(l+r)>>1;
    Judge(mid)?r=mid:l=mid+1;
  }
  cout<<l<<endl;
}
