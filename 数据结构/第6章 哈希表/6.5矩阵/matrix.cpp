#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=1010;
const int pc=131;
const int ppc=13331;
const int mod=10100;

unsigned int a[maxn][maxn],p1[maxn],p2[maxn],sum[maxn][maxn];
int fa,adj[mod];
char b[maxn][maxn];

struct my
{
  unsigned int zhi;
  int next;
} bian[maxn*maxn+5];

void Hash(unsigned int u)
{
  int x=u%mod;
  bian[++fa].zhi=u;
  bian[fa].next=adj[x];
  adj[x]=fa;
}

bool ask(unsigned int u)
{
  int x=u%mod;
  for (int i=adj[x]; i; i=bian[i].next)
  {
    if(bian[i].zhi==u) return true;
  }
  return false;
}

int main()
{
  //freopen("matrix.in","r",stdin);
  //freopen("matrix.out","w",stdout);
  int n,m,r,c,q;
  cin>>m>>n>>r>>c;
  for (int i=1; i<=m; i++) scanf("%s",b[i]+1);
  cin>>q;
  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      sum[i][j]=b[i][j]-'0';
  for (int i=1; i<=m; i++)
  {
    for (int j=1; j<=n; j++)
    {
      sum[i][j]+=sum[i-1][j]*pc;
    }
  }
  for (int i=1; i<=m; i++)
  {
    for (int j=1; j<=n; j++)
    {
      sum[i][j]+=sum[i][j-1]*ppc;
    }
  }
  p1[0]=p2[0]=1;
  for (int i=1; i<=r; i++) p1[i]=p1[i-1]*pc;
  for (int j=1; j<=c; j++) p2[j]=p2[j-1]*ppc;
  for (int i=r; i<=m; i++)
  {
    for (int j=c; j<=n; j++)
    {
      unsigned int temp=sum[i][j]-sum[i-r][j]*p1[r]-sum[i][j-c]*p2[c]+sum[i-r][j-c]*p1[r]*p2[c];
      Hash(temp);
    }
  }
  while(q--)
  {
    memset(sum,0,sizeof(sum));
    memset(b,0,sizeof(b));
    for (int i=1; i<=r; i++)
      scanf("%s",b[i]+1);
    for (int i=1; i<=r; i++)
    {
      for (int j=1; j<=c; j++)
      {
        sum[i][j]=b[i][j]-'0';
      }
    }
    for (int i=1; i<=r; i++)
      for (int j=1; j<=c; j++) sum[i][j]+=sum[i-1][j]*pc;
    for (int i=1; i<=r; i++)
      for (int j=1; j<=c; j++) sum[i][j]+=sum[i][j-1]*ppc;
    unsigned int temp=sum[r][c];
    if(ask(temp)) puts("1");
    else puts("0");
  }
  return 0;
}
