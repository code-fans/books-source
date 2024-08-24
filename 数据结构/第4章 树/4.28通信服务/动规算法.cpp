//通信服务 -DP 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define INF 0x3f3f3f3f
vector <int> Edg[MAXN];
int dp[MAXN][MAXN];   
int vis[MAXN];

void dfs(int u)
{
  vis[u]=1;                                //标记已访问 
  int flag=1,tmp=INF;
  for(int i=0; i<Edg[u].size(); i++)
  {
    int v=Edg[u][i];
    if(!vis[v])  
    {
      dfs(v);
      dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
      dp[u][2]+=min(dp[v][0],dp[v][1]);   //不取i，则没有父结点选项  
      if(dp[v][0]<=dp[v][1])   //儿子可能有多个,可取所有儿子，但必选一个儿子 
      {
        dp[u][1]+=dp[v][0];
        flag=0;                //选了一个儿子就要做标记
      }
      else                     //如果没有儿子被取，维护dp[v][0]-dp[v][1] 
      {
        dp[u][1]+=dp[v][1];
        tmp=min(tmp,dp[v][0]-dp[v][1]);//tmp表示它们差值最小的那个差值
      }
    }
  }
  if(flag)                    //还没有选儿子,那么必须强制换一个儿子加入 
    dp[u][1]+=tmp;            //加上这个差值
  return ;
}

int main()
{
  int n;
  scanf("%d",&n);
  int u,v;
  for(int i=1; i<n; i++)
  {
    scanf("%d%d",&u,&v);
    Edg[u].push_back(v);
    Edg[v].push_back(u);
  }
  for(int i=0; i<=n; i++)    //dp[i][0]的i从0开始，因为存在下标为0的结点
  {
    dp[i][0]=1;
    dp[i][1]=0;
    dp[i][2]=0;
  }
  if(n==1)
    printf("1\n");
  else
  {
    dfs(1);
    printf("%d\n",min(dp[1][0],dp[1][1]));//树上01背包,选或不选 
  }
  return 0;
}

