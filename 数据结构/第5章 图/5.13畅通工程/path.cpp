//畅通工程-spfa优化
#include <bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;

int  dis[201], w[201][201], b[201][201];

void SPFA(int s)
{
  for(int i=1; i<=b[s][0]; i++)
    if (dis[b[s][i]]>dis[s]+w[s][b[s][i]])
    {
      dis[b[s][i]]=dis[s]+w[s][b[s][i]];
      SPFA(b[s][i]);
    }
}

int main()
{
  //freopen("path.in","r",stdin);
  //freopen("path.out","w",stdout);
  int n,m,s,t,x,y,z;
  cin>>n>>m;
  for(int i=0; i<m; i++)
  {
    cin>>x>>y>>z;
    if(w[x][y]!=0 && z>w[x][y])
      continue;
    b[x][++b[x][0]]=y;                     //b[x][0]统计个数
    b[y][++b[y][0]]=x;                     //b[y][0]统计个数
    w[x][y]=w[y][x]=z;
  }
  cin>>s>>t;
  for(int i=1; i<=n; i++)
    dis[i]=MAX;
  dis[s]=0;
  SPFA(s);
  printf("%d\n",dis[t]==MAX?-1:dis[t]);
  return 0;
}

