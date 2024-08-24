#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
template<typename T>inline void read(T &x)
{
  x=0;
  T f=1,ch=getchar();
  while (!isdigit(ch)) ch=getchar();
  if (ch=='-') f=-1, ch=getchar();
  while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
  x*=f;
}
int p[1010],c[210][210],f[2][210][201];
int main()
{
  //freopen("service.in","r",stdin);
  //freopen("service.out","w",stdout);

  int l,n;
  read(l);
  read(n);
  for (int i=1; i<=l; ++i)
    for (int j=1; j<=l; ++j)
      read(c[i][j]);
  p[0]=3;
  for (int i=1; i<=n; ++i)
    read(p[i]);
  memset(f,0x3f,sizeof(f));
  f[0][1][2]=0;
  for (int i=0; i<n; ++i)
    for (int x=1; x<=l; ++x)
      for (int y=1; y<=l; ++y)
        if (f[i&1][x][y]!=inf)
        {
          if (x!=p[i+1] && y!=p[i+1])
            f[i+1&1][x][y]=min(f[i+1&1][x][y],f[i&1][x][y]+c[p[i]][p[i+1]]);
          if (p[i]!=p[i+1] && y!=p[i+1])
            f[i+1&1][p[i]][y]=min(f[i+1&1][p[i]][y],f[i&1][x][y]+c[x][p[i+1]]);
          if (x!=p[i+1] && p[i]!=p[i+1])
            f[i+1&1][x][p[i]]=min(f[i+1&1][x][p[i]],f[i&1][x][y]+c[y][p[i+1]]);
          f[i&1][x][y]=inf;
        }
  int ans=inf;
  for (int i=1; i<=l; ++i)
    for (int j=1; j<=l; ++j)
      ans=min(ans,f[n&1][i][j]);
  printf("%d\n",ans);
  return 0;
}

