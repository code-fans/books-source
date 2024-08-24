//机器人搬重物
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int dx[] = {0,0,-1,1};//face=0(西),1(东),2(北),3(南)时的方向值,左右和上下
const int dy[] = {-1,1,0,0};
const int turnLeft[] =  {3,2,0,1};//face=0,1,2,3时，左转即为3,2,0,1
const int turnRight[] = {2,3,1,0};

struct node
{
  int x,y,face,step;//位置 面对的方向，步数
} st,en,now,nx; //起点 终点 当前点 下一点
bool Map[N][N],vis[N][N][4];//迷宫地图,状态标记数组(位置和4个面对的方向)
int n,m,ans=-1;

void BFS()
{
  queue<node> q;
  vis[st.x][st.y][st.face] = 1;
  q.push(st);
  while(!q.empty())
  {
    now = q.front(),q.pop();
    if(now.x==en.x&&now.y==en.y)//走到终点
    {
      ans = now.step;
      return;
    }
    nx=now;//准备直走
    for(int i = 1; i <= 3; i++) //沿着当前方向走i步
    {
      nx.x += dx[now.face],nx.y += dy[now.face];
      if(nx.x<1||nx.y<1||nx.x>=n||nx.y>=m||Map[nx.x][nx.y])//边界处不可走(0~n行 0~m列)...
        break;
      if(vis[nx.x][nx.y][nx.face]) continue;//该状态扩展过了
      vis[nx.x][nx.y][nx.face] = 1;
      nx.step = now.step + 1;//走一步
      q.push(nx);
    }
    nx=now, nx.step = now.step + 1;//准备转换方向
    nx.face = turnLeft[now.face];//左转
    if(!vis[nx.x][nx.y][nx.face])
    {
      vis[nx.x][nx.y][nx.face] = 1;
      q.push(nx);
    }
    nx.face = turnRight[now.face];//右转
    if(!vis[nx.x][nx.y][nx.face])
    {
      vis[nx.x][nx.y][nx.face] = 1;
      q.push(nx);
    }
  }
}

int main()
{
  //freopen("robot.in","r",stdin);
  //freopen("robot.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i = 1,a; i <= n; i++)//读入格子的值
    for(int j = 1; j <= m; j++)
    {
      scanf("%d",&a);
      if(a) //如为障碍(i,j视为格子右下角坐标)，则障碍的四个点均不可走
        Map[i][j]=Map[i-1][j-1]=Map[i-1][j]=Map[i][j-1] = 1;
    }
  scanf("%d%d%d%d %c",&st.x,&st.y,&en.x,&en.y,&st.face);
  st.face = (st.face=='W'?0:(st.face=='E'?1:(st.face=='N'?2:3)));
  st.step =0;
  BFS();
  printf("%d\n",ans==-1?-1:ans);
  return 0;
}
