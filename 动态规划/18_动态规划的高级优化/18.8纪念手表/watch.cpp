//纪念手表
#include <bits/stdc++.h>
using namespace std;

bool dp[100005];
int ans,n,m;
int a[150],c[150],que[100005];

inline int Read(int x=0)                 //以字符串形式读入数字可提速
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
  return x;
}

void Dp()
{
  dp[0] = true;
  for(int i = 1; i <= n ; i ++)
  {
    if(c[i] == 1)                               //01背包
    {
      for(int s = m ; s>=a[i]; s-- )
        if(!dp[s] && dp[s-a[i]])
          dp[s] = true;
    }
    else if(a[i]*c[i]>=m)                       //完全背包，加速
    {
      for(int s = a[i]; s<=m ; s++)
        if(!dp[s] && dp[s-a[i]])
          dp[s] = true;
    }
    else
      for(int b = 0 ; b < a[i]; b++)            //队列优化,枚举余数
      {
        int head = 1,tail = 1;
        for(int t=0; t*a[i]+b<=m; t++)          //枚举硬币个数
        {
          while(head<tail && t-que[head]>c[i])  //第i个硬币全用了也无法转移到t 
            head++;                             //队首弹出不符合的元素
          if(dp[t*a[i]+b])                      //DP值为真,可以优化后面的值 
            que[tail++]=t;                      //所以硬币个数入队
          else if(head<tail)                    //单调队列里有元素 
            dp[t*a[i]+b] = true;                //可以转移
        }
      }
  }
}

int main()
{
  freopen("watch.in","r",stdin);
  freopen("watch.out","w",stdout);
  while(cin>>n>>m && n>0)
  {
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n ; i ++)  //读入面值
      a[i] = Read();
    for(int i = 1; i <= n ; i ++)  //读入数量
      c[i] = Read();
    Dp();
    ans=0;
    for(int i = 1; i <= m ; i ++)
      if(dp[i])
        ans++;
    printf("%d\n",ans);
  }
  return 0;
}

