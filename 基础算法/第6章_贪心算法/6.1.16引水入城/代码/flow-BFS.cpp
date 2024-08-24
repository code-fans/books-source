//引水入城 —BFS
#include<bits/stdc++.h>
using namespace std;
const int maxn=510;

int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int N,M,sum;
int h[maxn][maxn],vis[maxn][maxn],use[maxn][maxn];
pair<int,int> pos[maxn];        //pos[i]表示第一行第i列的城市能送到水的左右边界

void BFS(int x,int y)
{
  memset(vis,0,sizeof(vis));
  queue<pair<int,int> > q;
  q.push(make_pair(x,y));
  while(!q.empty())
  {
    pair<int,int> p=q.front();
    q.pop();
    if(vis[p.first][p.second])
      continue;
    vis[p.first][p.second]=1;      //vis标记从(x,y)出发，能遍历到的城市
    use[p.first][p.second]=1;      //use标记该城市是否有解
    for(int i=0; i<=3; i++)
    {
      int X=p.first+dx[i];
      int Y=p.second+dy[i];
      if(X && Y && X<=N && Y<=M && h[X][Y]<h[p.first][p.second] && !vis[X][Y])
      {
        q.push(make_pair(X,Y));
        if(X==N)
          pos[y]= {min(pos[y].first,Y),max(pos[y].second,Y)};//更新左右边界
      }
    }
  }
}

int main()
{
  freopen("flow.in","r",stdin);
  freopen("flow.out","w",stdout);
  cin>>N>>M;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
      cin>>h[i][j];
  for(int i=1; i<=M; i++)
  {
    pos[i]= {i,i};
    if(!use[1][i])                             //不能只用最高城市出发的剪枝
      BFS(1,i);
  }
  for(int i=1; i<=M; i++)
    if(!use[N][i])
      sum++;
  if(sum)
    printf("0\n%d\n",sum);
  else
  {
    for(int L=1,R=pos[1].second; L<=M; L=R+1) //区间选点
    {
      for (int i=L; i<=M; i++)
        if (pos[i].first<=L)
          R=pos[i].second;                  //无均用max比较最小值
      sum++;
    }
    printf("1\n%d\n",sum);
  }
  return 0;
}
