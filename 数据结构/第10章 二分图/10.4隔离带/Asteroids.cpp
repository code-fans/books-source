//¸ôÀë´ø
#include <bits/stdc++.h>
using namespace std;
const int N=1001;

int Map[N][N],vis[N],Link[N];
int n,k;

int Dfs(int x)
{
  for(int i=1; i<=n; i++)
    if(Map[x][i]&&!vis[i])
    {
      vis[i]=1;
      if(Link[i]==0 || Dfs(Link[i]))
      {
        Link[i]=x;
        return 1;
      }
    }
  return 0;
}

int main()
{
  freopen("Asteroids.in","r",stdin);
  freopen("Asteroids.out","w",stdout);
  int x,y,Ans=0;
  scanf("%d%d",&n,&k);
  for(int i=0; i<k; i++)
  {
    scanf("%d%d",&x,&y);
    Map[x][y]=1;
  }
  for(int i=1; i<=n; i++)
  {
    memset(vis,0,sizeof(vis));
    Ans+=Dfs(i);
  }
  printf("%d\n",Ans);
  return 0;
}
