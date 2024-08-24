#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
#define ll long long

int n;
ll P[MAXN], X[MAXN], C[MAXN], sumd[MAXN], sumn[MAXN], dp[MAXN];
int q[MAXN<<1];

int Readint()
{
  int ans=0, f=1;
  char ch=getchar();
  while (ch<'0' || ch>'9')
  {
    if (ch=='-')
      f=-1;
    ch=getchar();
  }
  while (ch>='0' && ch<='9')
  {
    ans=(ans<<1)+(ans<<3)+ch-'0';
    ch=getchar();
  }
  return ans*f;
}

ll Readll()
{
  ll ans=0, f=1;
  char ch=getchar();
  while (ch<'0' || ch>'9')
  {
    if (ch=='-')
      f=-1;
    ch=getchar();
  }
  while (ch>='0' && ch<='9')
  {
    ans=(ans<<1)+(ans<<3)+ch-'0';
    ch=getchar();
  }
  return ans*f;
}

double Slope(int k, int j)
{
  return 1.0*(dp[k]+sumd[k]-dp[j]-sumd[j])/ (1.0*sumn[k]-sumn[j]);
}

int main()
{
  freopen("Warehouse.in","r",stdin);
  freopen("Warehouse.out","w",stdout);
  n=Readint();
  for (int i=1; i<=n; i++)
  {
    X[i]=Readll();
    P[i]=Readll();
    C[i]=Readll();
  }
  for (int i=1; i<=n; i++)
  {
    sumn[i]=sumn[i-1]+P[i];     //数量的前缀和 
    sumd[i]=sumd[i-1]+P[i]*X[i];//运费的前缀和 
  }
  int head=1, tail=0;
  q[++tail]=0;
  for (int i = 1; i <= n; i++)
  {
    while (head<tail && Slope(q[head], q[head+1])<1.0*X[i])
      head++;
    dp[i] = dp[q[head]]+X[i]*(sumn[i]-sumn[q[head]])-sumd[i]+sumd[q[head]]+C[i];
    while (head < tail && Slope(q[tail-1], q[tail])>Slope(q[tail], i))
      tail--;
    q[++tail]=i;
  }
  printf("%lld\n", dp[n]);
  return 0;
}

