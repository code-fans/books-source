//���ѩ��
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;
vector<pair<int,int>>G[MAXN];        //�ڽӱ�1st���㣬2nd���Ȩ
int inDegree[MAXN];                  //ͳ��ÿ��������
int dp[MAXN];                        //�ӳ�ʼ��㵽��i�������·����
int n,m;

void TopSort()
{
  queue<int>q;
  while(!q.empty())
    q.pop();                         //��ն���
  for(int i=1; i<=n; i++)            //ɨ����
    if(inDegree[i]==0)
      q.push(i);                     //�����Ϊ0�Ľ���ӽ�����

  while(!q.empty())
  {
    int u=q.front();                 //ȡ�����׽��
    q.pop();                         //ɾ���õ�
    for(int i=0; i<G[u].size(); i++) //�������u���ڵı߲�ɾ��
    {
      int v=G[u][i].first;
      inDegree[v]--;
      if(inDegree[v]==0)
        q.push(v);                   //���Ϊ0�ĵ�������
      dp[v]=max(dp[v],dp[u]+G[u][i].second);
    }
  }
}

int main()
{
  freopen("skiing.in","r",stdin);
  freopen("skiing.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    memset(inDegree,0,sizeof(inDegree));
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
      G[i].clear();
    scanf("%d %d",&n,&m);
    int u,v,w;
    for(int i=0; i<m; i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      G[u].push_back(make_pair(v,w));
      inDegree[v]++;
    }
    TopSort();
    int ans=-1;
    for(int i=1; i<=n; i++)
      ans=max(ans,dp[i]);
    printf("%d\n",ans);
  }
  return 0;
}

