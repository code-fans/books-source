//炮兵阵地
#include<bits/stdc++.h>
using namespace std;

struct st
{
  int state, num;
} s[105];
int Line[105], dp[105][105][105];

inline int Getnum(int x,int t=0)       //计算x转二进制数后有多少1
{
  for(; x>0; t++)
    x=x&(x-1);
  return t;
}

int main()
{
  freopen("cannon.in","r",stdin);
  freopen("cannon.out","w",stdout);
  int n, m, cnt=0,ans=0;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      char c;
      cin>>c;
      Line[i]=(Line[i]<<1)+(c=='P');   //该行地形存为二进制，即平原为1，山地为0
    }
  for(int i=0; i<(1<<m); i++)          //枚举000...000~111...111所有可能方案
  {
    if(i&(i<<1) || i&(i<<2) || i&(i>>1) || i&(i>>2))//判断一行是否左右冲突
      continue;
    s[++cnt].state = i;             //依次存可行状态,即离散化后可不用滚动数组优化
    s[cnt].num=Getnum(i);              //统计该状态的炮兵部队数
    if((i & Line[1]) == i)             //如果该状态可放在第一行
      dp[1][0][cnt] = s[cnt].num;      //第一行动规初始化
  }
  for(int i = 1; i <= cnt; i++)        //第二行动规初始化
    for(int j = 1; j <= cnt; j++)
      if(!(s[i].state & s[j].state) && (Line[2] & s[j].state)==s[j].state)
        dp[2][i][j] = dp[1][0][i]+s[j].num;
  for(int i = 3; i <= n; i++)          //从第三行开始动规
    for(int a = 1; a <= cnt; a++)
      if((Line[i] & s[a].state) == s[a].state)//a状态可放在第i行
        for(int b = 1; b <= cnt; b++)
          if(!(s[a].state & s[b].state))//a,b状态不冲突
            for(int c = 1; c <= cnt; c++)
              if(!(s[b].state & s[c].state) && !(s[a].state & s[c].state))
                dp[i][b][a]=max(dp[i][b][a], dp[i-1][c][b]+s[a].num);
  for(int i=1; i<=cnt; i++)
    for(int j=1; j<=cnt; j++)
      ans=max(ans, dp[n][i][j]);
  printf("%d\n", ans);
  return 0;
}

