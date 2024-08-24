//通信服务
#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;            //2e4即20000
const int M=50000;
int n,tim=0;
int DfsNode[N],Father[N];
vector<int>edg[N];
bool s[N],Set[N];              //s[]为覆盖点,Set[]为支配集，注意Set不能小写

void Dfs(int u,int father)
{
  DfsNode[tim++]=u;
  for(int i=0; i<edg[u].size(); i++)
  {
    int v=edg[u][i];
    if(v!=father)
    {
      Father[v]=u;
      Dfs(v,u);
    }
  }
}

int Greedy()
{
  int ans=0;
  for(int i=n-1; i>=0; i--)       //反序DFS
  {
    int t=DfsNode[i];
    if(!s[t])//当前点未被覆盖，既它不属于支配集，也不与支配集中的点相连
    {
      if(!Set[Father[t]])         //当前点的父亲结点不属于支配集
      {
        Set[Father[t]]=true;      //将父结点加入支配集
        ans++;                    //支配集数目加一
      }
      s[t]=true;                  //标记当前结点被覆盖
      s[Father[t]]=true;          //标记当前结点的父结点被覆盖
      s[Father[Father[t]]]=true;  //标记当前结点的父结点的父结点被覆盖
    }
  }
  return ans;
}

int main()
{
  freopen("comm6.in","r",stdin);
  freopen("comm6.ans","w",stdout);
  scanf("%d",&n);
  int u,v;
  for(int i=1; i<n; i++)
  {
    scanf("%d%d",&u,&v);
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  Dfs(1,0);
  printf("%d\n",Greedy());
  return 0;
}

