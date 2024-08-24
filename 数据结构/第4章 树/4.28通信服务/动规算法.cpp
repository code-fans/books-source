//ͨ�ŷ��� -DP 
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define INF 0x3f3f3f3f
vector <int> Edg[MAXN];
int dp[MAXN][MAXN];   
int vis[MAXN];

void dfs(int u)
{
  vis[u]=1;                                //����ѷ��� 
  int flag=1,tmp=INF;
  for(int i=0; i<Edg[u].size(); i++)
  {
    int v=Edg[u][i];
    if(!vis[v])  
    {
      dfs(v);
      dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
      dp[u][2]+=min(dp[v][0],dp[v][1]);   //��ȡi����û�и����ѡ��  
      if(dp[v][0]<=dp[v][1])   //���ӿ����ж��,��ȡ���ж��ӣ�����ѡһ������ 
      {
        dp[u][1]+=dp[v][0];
        flag=0;                //ѡ��һ�����Ӿ�Ҫ�����
      }
      else                     //���û�ж��ӱ�ȡ��ά��dp[v][0]-dp[v][1] 
      {
        dp[u][1]+=dp[v][1];
        tmp=min(tmp,dp[v][0]-dp[v][1]);//tmp��ʾ���ǲ�ֵ��С���Ǹ���ֵ
      }
    }
  }
  if(flag)                    //��û��ѡ����,��ô����ǿ�ƻ�һ�����Ӽ��� 
    dp[u][1]+=tmp;            //���������ֵ
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
  for(int i=0; i<=n; i++)    //dp[i][0]��i��0��ʼ����Ϊ�����±�Ϊ0�Ľ��
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
    printf("%d\n",min(dp[1][0],dp[1][1]));//����01����,ѡ��ѡ 
  }
  return 0;
}

