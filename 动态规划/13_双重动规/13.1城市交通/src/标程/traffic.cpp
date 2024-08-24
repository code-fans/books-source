//城市交通
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const int U = 1061109567;

double f[11][MAXN][MAXN];
int d[11][MAXN][MAXN],l[11][MAXN][MAXN],r[11][MAXN][MAXN];

struct Que
{
  int x, y, t;
} q[MAXN];
int cnt;

void PushQue(int x, int y, int t)        //线路存入结构体数组
{
  q[++cnt]= {x,y,t};                     //c++11支持的语法
  if(q[cnt].x>q[cnt].y)
    swap(q[cnt].x,q[cnt].y);
}

int Cmp (struct Que a, struct Que b)     //线路按先后顺序排序
{
  return a.x == b.x? a.y<b.y : a.x<b.x;
}

bool Dfs(const int &m,const int &i, const int &j)//DFS找出增加的线路
{
  if (d[m][i][j])                        //如i,j间有结点，则添加
  {
    // 返回值表示是否能连成一条固有线段，只有能才添加
    if (l[m][i][j] && Dfs(l[m][i][j], i, d[m][i][j]))
      PushQue(i,d[m][i][j],l[m][i][j]);
    if (r[m][i][j] && Dfs(r[m][i][j], d[m][i][j], j))
      PushQue(d[m][i][j],j,r[m][i][j]);
    return 0;
  }
  return 1;
}

int main()
{
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  memset(f,0x7f,sizeof(f));              //浮点数组不能用0x3f赋最大值
  int n,M,x, y,w;
  scanf("%d %d", &n, &M);
  while (scanf("%d%d%d", &x,&y,&w)==3 && x|y|w!=0)
    f[0][x][y]=f[0][y][x]=w;
  for (int i=1; i<=n; ++i)               //初始化
    for (int j=1; j<=n; ++j)
      if (f[0][i][j]<=U)                 //如果有路
        for (int m=1; m<=M; ++m)
          f[m][i][j]=f[m][j][i]=f[m-1][i][j]/2;
  if (M==0)                              //针对0的特判，即floyd
  {
    for (int k=1; k<=n; ++k)             //k要放在最外层循环
      for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
          if(f[0][i][k]!=U && f[0][k][j]!=U && f[0][i][j]>f[0][i][k]+f[0][k][j])
            f[0][i][j]=min(f[0][i][j],f[0][i][k]+f[0][k][j]);
  }
  else
    for (int m=1; m<=M; ++m)             //添加M条公交路线
      for (int t=1; t<=m; ++t)           //添加的公交线路分割成两块
        for (int k=1; k<=n; ++k)         //枚举中间节点k
          for (int i=1; i<=n; ++i)       //枚举街区i
            for (int j=1; j<=n; ++j)     //枚举街区j
              if(f[m-t][i][k]!=U && f[t][k][j]!=U)
                if(f[m][i][j]>f[m-t][i][k]+f[t][k][j])//更新最优值
                {
                  f[m][i][j]=min(f[m][i][j],f[m-t][i][k]+f[t][k][j]);
                  d[m][i][j]=k;//d[m][i][j]保存i到j间添加m条路的中间结点k
                  l[m][i][j]=m-t;        //l[m][i][j]:i到k所添加的路条数
                  r[m][i][j]=t;          //r[m][i][j]:k到j所添加的路条数
                }
  printf("%.2f\n", f[M][1][n]);
  if (M)
  {
    Dfs(M, 1, n);                        //M>1时，深搜找所添加的路径
    sort(q+1, q+1+cnt,Cmp);
    for (int i=1; i<=cnt; ++i)
      for (int j=1; j<=q[i].t; ++j)      //可能添加不止1条路径
        printf("%d %d\n", q[i].x, q[i].y);
  }
  return 0;
}

