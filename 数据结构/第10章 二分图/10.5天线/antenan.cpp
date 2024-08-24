//天线
#include <bits/stdc++.h>
using namespace std;
const int MAXN=405;
char s[MAXN][MAXN];
vector<int> G[MAXN*MAXN];
int match[MAXN],visit[MAXN];
int dx[]= {1,0,-1,0},dy[]= {0,1,0,-1};     //方向的增量数组

bool dfs(int u)
{
  for(int i=0; i<G[u].size(); i++)
  {
    int v=G[u][i];
    if(!visit[v])
    {
      visit[v]=1;
      if(match[v]<0||dfs(match[v]))
      {
        match[v]=u;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  freopen("antenan.in","r",stdin);
  freopen("antenan.out","w",stdout);
  int Case,h,w;
  scanf("%d",&Case);
  while(Case--)
  {
    memset(match,-1,sizeof(match));
    for(int i=0; i<MAXN; i++)
      G[i].clear();
    scanf("%d%d",&h,&w);
    int V=0;
    for(int i=1; i<=h; i++)
    {
      scanf("%s",s[i]+1);                 //一次读一行字符串
      for(int j=1; j<=w; j++)
        if(s[i][j]=='*') V++;             //统计顶点数
    }
    for(int i=1; i<=h; i++)
      for(int j=1; j<=w; j++)
        if(s[i][j]=='*')                  //以城市为顶点构图
          for(int k=0; k<4; k++)
          {
            int x=i+dx[k],y=j+dy[k];
            if(1<=x && x<=h && 1<=y && y<=w)
              if(s[x][y]=='*')
                G[w*(i-1)+j].push_back(w*(x-1)+y);
          }
    int ans=0;
    for(int i=1; i<=h; i++)
      for(int j=1; j<=w; j++)
      {
        int u=w*(i-1)+j;
        memset(visit,0,sizeof(visit));
        ans+=dfs(u);
      }
    printf("%d\n",V-ans/2);
  }
  return 0;
}

