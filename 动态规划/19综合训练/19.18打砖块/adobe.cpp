#include <bits/stdc++.h>
using namespace std;
const int maxn=255;
#define M(a) memset(a,0,sizeof a)
const int mxn = 205;
int n, m, p, ans;
char ch;
int a[mxn][mxn], whe[mxn], res[mxn][mxn];
int dp[mxn][mxn][2], ci[mxn][mxn], now[mxn][mxn];  //0:不需要借，1:需要借
bool b[mxn][mxn];
int main()
{
  freopen("adobe.in","r",stdin);
  freopen("adobe.ans","w",stdout);

  int i, j, k;
  cin>>n>>m>>p;
  //子弹为0，直接输出
  if (p == 0)
  {
    cout<<"0\n";
    return 0;
  }
  //a[i][j]表示打掉第i行j列位置的砖块的得分
  //b[i][j] = 1表示打掉第i行j列位置的砖块可以奖励一颗子弹
  //读数据的时候按行翻转了，就是上下翻转了
  for (i = n; i >= 1; i--)
    for(j=1; j<=m; j++)
    {
      cin>>a[i][j]>>ch;
      b[i][j]= ch == 'Y' ? 1:0;
    }
  //贪心打掉最下层的Y ,因为这里上下翻转了，所以打掉的是上层的
  for(j=1; j<=m; j++) //j列
  {
    for(i=1; i<=n; i++) //i行
    {
      if (!b[i][j])
        break;
      ans += a[i][j];
    }
    //因为上下翻转了，whe[j]=i表示第j列第一个N的位置为i
    //其实也就是贪心打掉最下层的Y之后剩下的N
    whe[j] = i;
  }
  //now[j][i]代表第j列我们要打第i个砖块可以得到的分数，注意，如果第i个砖块上有Y，要把Y也加到now里面
  //res[j][i]，这个是个前缀和，表示第j列我们要打第i个砖块的得分(这个和now的区别在于如果i砖块上面有Y也不加进去)
  for(j=1; j<=m; j++)
    for(i=whe[j]; i<=n; i++)
      res[j][i] = res[j][i - 1] + a[i][j];
  for(j=1; j<=m; j++)
    for(i=whe[j]; i<=n; i++)
      now[j][i] = res[j][i];
  //ci[j][i]表示第j列我们要打第i个砖块需要多少子弹
  //修正now[j][i]数组和填充ci[j][i]数组
  for(j=1; j<=m; j++)
  {
    ci[j][whe[j]] = 1;//每列的第一个N肯定要打掉
    for(i=whe[j]; i<=n; i++)
    {
      int tmp = i;
      //b[i + 1][j]对应的为Y
      //这部分理解可以画个小图
      while (b[i + 1][j])
        i++;
      now[j][tmp] = res[j][i];
      ci[j][i + 1] = ci[j][tmp] + 1;
    }
  }
  //初始值 前j列在不借子弹的情况下用0发子弹打
  for(j=0; j<=m; j++)
    dp[j][0][0] = -1e8;

  for(j=1; j<=m; j++)
    for(k=1; k<=p; k++)
    {
      dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k][0]);
      dp[j][k][1] = max(dp[j][k][1], dp[j - 1][k][1]);
      for(i=whe[j]; i<=n; i++)
        if (!b[i][j] && k >= ci[j][i])//没奖励子弹并且没超过子弹数
        {
          dp[j][k][0] = max(dp[j][k][0], max(dp[j - 1][k - ci[j][i]][1], dp[j - 1][k - ci[j][i]][0]) + res[j][i]);
          dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k - ci[j][i]][0] + now[j][i]);
          dp[j][k][1] = max(dp[j][k][1], dp[j - 1][k - ci[j][i]][1] + now[j][i]);
        }
    }
  printf("%d\n", dp[m][p][0] + ans);//最后输出的是不欠子弹的，所以欠子弹的情况无视了
  return 0;
}

