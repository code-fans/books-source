//相遇问题 - 递归算法优化
#include <bits/stdc++.h>
using namespace std;
const int MAXN=312;

int n;
int Dir[MAXN][MAXN];
double c[MAXN][MAXN][MAXN];

double F(int day,int x,int y,double p)//p为概率
{
  if(day>n || Dir[x][y]==0)    //如超时或者坐标超范围
    c[day][x][y]=-1;           //标记为-1
  if(c[day][x][y]==-1)         //如果已被标记过不能遇到王子
    return 0;                  //返回0
  if(c[day][x][y]!=0)          //如果已经求过从day时(x,y)出发遇到王子的概率
    return c[day][x][y];       //直接返回值
  if(day==x && y==(n>>1)+1)    //如果公主与王子相遇,返回概率
  {
    c[day][x][y]=p;
    return p;
  }
  double t=F(day+1,x+1,y,p)+F(day+1,x-1,y,p)+F(day+1,x,y+1,p)+F(day+1,x,y-1,p);
  if(t==0)                     //如果没有遇到王子,标记并退出
  {
    c[day][x][y]=-1;
    return 0;
  }
  c[day][x][y]=t/Dir[x][y];    //否则,求出从day时(x,y)出发碰到王子的概率
  return c[day][x][y];
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);
  scanf("%d",&n);
  if(n%4==1)
    puts("0");
  else
  {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        Dir[i][j]=2+(i>1 && i<n)+(j>1 && j<n);
    printf("%.4f\n",F(0,(n/2)+1,((n/2)+1),1));
  }
  return 0;
}

