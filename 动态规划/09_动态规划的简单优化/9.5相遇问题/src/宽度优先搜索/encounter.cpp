//相遇问题 - BFS
#include <bits/stdc++.h>
using namespace std;

int Dir[101][101];
int n;
double ans;
struct Node
{
  int day,x,y;
  double p;
} o;
queue <Node> q;

void Push(int day,int x,int y,double p)      //入队列
{
  if(x==day && y==(n>>1)+1)                  //如相遇，累加概率，但不入队列
    ans+=p;
  else
    q.push(Node {day,x,y,p});                //入队列,语法为c++11标准
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);
  cin>>n;
  if(!(n%4==1))
  {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        Dir[i][j]=2+(i>1 && i<n)+(j>1 && j<n);
    q.push(Node {0,(n>>1)+1,(n>>1)+1,1});      //语法为c++11标准
    while(!q.empty())
    {
      o=q.front();
      q.pop();
      if(o.day>n||o.x-abs(o.y-((n>>1)+1))<o.day)//剪枝,可考虑进一步优化
        continue;
      double t=o.p/Dir[o.x][o.y];              //计算向四周移动的概率
      if(Dir[o.x+1][o.y])
        Push(o.day+1,o.x+1,o.y,t);
      if(Dir[o.x-1][o.y])
        Push(o.day+1,o.x-1,o.y,t);
      if(Dir[o.x][o.y+1])
        Push(o.day+1,o.x,o.y+1,t);
      if(Dir[o.x][o.y-1])
        Push(o.day+1,o.x,o.y-1,t);
    }
  }
  cout<<setprecision(ans==0?0:4)<<fixed<<ans<<endl;
  return 0;
}

