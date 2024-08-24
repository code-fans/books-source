//方格取数
#include <bits/stdc++.h>
using namespace std;

int a[22][22];
int dp[22][20000], sum[22][20000];  //表示第i行使用第j种方法得到的最大值,和
int state[20000];                   //表示可行的状态，即可行的取数方法
int len, n;

int GetSum(int pos, int x)          //求第pos行，使用x方法能取得的和
{
  int sum=0;
  for(int cnt=n-1; x; x>>=1)
    sum+=(x&1)*a[pos][cnt--];       //要或者不要以01表示，所以按原值求和
  return sum;
}

void Init(int m)
{
  len=0;
  for(int i=0; i<(1<<m); i++)        //预处理出一行的所有方案
    if((i&(i<<1))==0)
      state[len++]=i;
  for(int i=0; i<n; i++)
    for(int j=0; j<len; j++)
      sum[i][j]=GetSum(i, state[j]);//第i行，方案j的总和
  memset(dp, 0, sizeof(dp));
  for(int i=0; i<len; i++)
    dp[0][i]=sum[0][i];
}

int main()
{
  freopen("num.in","r",stdin);
  freopen("num.out","w",stdout);
  while(cin>>n)
  {
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    Init(n);
    for(int i=1; i<n; i++)            //处理第i行
      for(int j=0; j<len; j++)        //采取第j种方法
        for(int k=0; k<len; k++)      //枚举上一行所采取的方法k
          if((state[j] & state[k])==0)//上下方法不冲突
            dp[i][j]=max(dp[i][j], dp[i-1][k]+sum[i][j]);//状态转移方程
    int ans = 0;
    for(int i = 0; i < len; i++)      //找出最大值
      if(dp[n-1][i]>ans)
        ans = dp[n-1][i];
    cout<<ans<<endl;
  }
  return 0;
}
