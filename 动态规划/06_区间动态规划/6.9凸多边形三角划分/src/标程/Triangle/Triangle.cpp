//凸多边形三角划分
#include <bits/stdc++.h>
using namespace std;

int p[51],f[51][51],mid[51][51];  //mid[][]保存切割点
int n, cnt;

struct node
{
  int x, y, z;
} t[51];                          //保存切割好的三角形

bool Cmp(node a, node b)
{
  return a.x==b.x? (a.y==b.y?a.z<b.z:a.y<b.y) : (a.x<b.x);
}

int Dp(int i, int j)              //递归求动态转移方程值
{
  if (f[i][j] != 2139062143)      //已求出值，直接返回
    return f[i][j];
  if (j-i<=1)                     //只有两个点
    return 0;
  if (j-i==2)                     //正好三个点
  {
    f[i][j]=p[i]*p[i+1]*p[i+2];
    mid[i][j]=i+1;                //标记切割点
    return f[i][j];
  }
  for (int k=i+1; k<=j-1; k++)    //枚举切割点
    if (f[i][j]>(Dp(i,k)+Dp(k,j)+p[i]*p[k]*p[j]))
    {
      f[i][j]=Dp(i,k)+Dp(k,j)+p[i]*p[k]*p[j];
      mid[i][j]=k;                //标记切割点
    }
  return f[i][j];
}

void GetTriangle(int l, int r)
{
  if (r-l<2)
    return;
  t[++cnt].x=l;
  t[cnt].y=mid[l][r];
  t[cnt].z=r;
  GetTriangle(l,mid[l][r]);
  GetTriangle(mid[l][r],r);
}

int main()
{
  freopen("Triangle.in", "r", stdin);
  freopen("Triangle.out", "w", stdout);
  scanf("%d", &n);
  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);
  memset(f,127,sizeof(f));        //初始值设为最大值2139062143
  printf("%d\n", Dp(1, n));
  GetTriangle(1, n);              //保存切割出来的三角形
  sort(t+1, t+cnt+1, Cmp);        //排序切割出来的三角形
  for (int i=1; i<=cnt; i++)
    printf("%d %d %d%c", t[i].x, t[i].y, t[i].z,i==cnt?'\n':',');
  return 0;
}
