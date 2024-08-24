#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
inline int read()
{
  register int x=0,f=0,ch=getchar();
  while('0'>ch||ch>'9')f^=ch=='-',ch=getchar();
  while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=getchar();
  return f?-x:x;
}
const int MAX=200005;
const int INF=0x3f3f3f3f;
int res,ans,sum,f[MAX],g[MAX],h[MAX],n,a[MAX];
signed main()
{
  n=read();
  for(register int i=1; i<=n; ++i)a[i]=read(),sum+=a[i];

  ans=-INF;
  f[0]=h[0]=-INF;
  for(register int i=1; i<=n; ++i)h[i]=max(h[i-1]+a[i],a[i]),f[i]=max(f[i-1],h[i]);
  g[n+1]=h[n+1]=-INF;
  for(register int i=n; i; --i)h[i]=max(h[i+1]+a[i],a[i]),g[i]=max(g[i+1],h[i]);
  for(register int i=1; i<=n; ++i)ans=max(ans,f[i]+g[i+1]);

  res=INF;
  f[0]=h[0]=INF;
  for(register int i=1; i<=n; ++i)h[i]=min(h[i-1]+a[i],a[i]),f[i]=min(f[i-1],h[i]);
  g[n+1]=h[n+1]=INF;
  for(register int i=n; i; --i)h[i]=min(h[i+1]+a[i],a[i]),g[i]=min(g[i+1],h[i]);
  for(register int i=1; i<=n; ++i)res=min(res,f[i]+g[i+1]);

  printf("%d\n",max(ans,sum-res));
  return 0;
}


