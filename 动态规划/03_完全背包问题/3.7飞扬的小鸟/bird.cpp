//飞扬的小鸟
#include<bits/stdc++.h>
using namespace std;
#define N 10005

int n,m,k,x[N],y[N],low[N],high[N],f[N][2005];
bool flag[N];

int main()
{
  freopen("bird.in","r",stdin);
  freopen("bird.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  for (int i=1; i<=n; i++)
    scanf("%d%d",&x[i],&y[i]);
  for (int i=1; i<=n; i++)
  {
    high[i]=m;    //初始最高能到m
    low[i]=1;     //初始最低能到1
  }
  for (int i=1,P,L,H; i<=k; i++)
  {
    scanf("%d%d%d",&P,&L,&H);
    flag[P]=1;
    low[P]=L+1;   //注意下沿高度要加1
    high[P]=H-1;  //注意上沿高度要减1
  }
  memset(f,0x3f3f3f,sizeof(f));
  for (int i=1; i<=m; i++)
    f[0][i]=0;
  for (int i=1; i<=n; i++)            //向右出发
  {
    for (int j=x[i]+1; j<=x[i]+m; j++)//上升这一段,完全背包
      f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);//前一单位跳或现在跳
    for (int j=m+1; j<=x[i]+m; j++)   //飞出了天花板的特殊情况
      f[i][m]=min(f[i][m],f[i][j]);
    for (int j=1; j<=m-y[i]; j++)     //下降这一段
      f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
    for (int j=1; j<low[i]; j++)      //处理无法通过的地方
      f[i][j]=0x3f3f3f;
    for (int j=high[i]+1; j<=m; j++)
      f[i][j]=0x3f3f3f;
  }
  int ans=0x3f3f3f;
  for (int i=1; i<=m; i++)
    ans=min(ans,f[n][i]);
  if (ans<0x3f3f3f)                   //若能通过，直接输出答案
    printf("1\n%d\n",ans);
  else
  {
    ans=0;
    for(int i = 1 ; i <= n ; ++ i)
      for(int j = 1 ; j <= m ; ++ j)
        if(flag[i] && f[i][j] < 0x3f3f3f )
        {
          ans++;
          break;
        }
    printf("0\n%d\n",ans);
  }
  return 0;
}
//用f[i][j]表示横坐标为i时高度为j的最少点击次数。
//用正无穷来表示不可能达到这个状态。
//于是我们可以分析出状态转移的方式：
//上升——完全背包转移方式
//下降——01背包转移方式
//超过m变为m——特判
//此题也可以用搜索来做，优化后可过全部数据
