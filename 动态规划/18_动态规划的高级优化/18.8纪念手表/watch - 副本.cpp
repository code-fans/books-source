#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn = 110;
const int maxm = 1e5+10;
int a[maxn],num[maxn],dp[maxm],ds[maxm];//dp[v]:装了v体积得东西了

void init()
{
  for(int i = 1; i <= n ; i++)
  {
    scanf("%d",&a[i]);//体积
  }
  for(int i = 1; i <= n ; i++)
  {
    scanf("%d",&num[i]);//数量
  }
  for(int i = 1 ; i <= m ; i++)
    dp[i] = 0;
  dp[0] = 1;
}

void get1(int i)
{
  for(int l = m ; l >= a[i] ; l--)
  {
    if(dp[l-a[i]])
    {
      dp[l] = 1;
    }
  }
}

void getfull(int i)
{
  for(int l = a[i] ; l <= m ; l++)
  {
    if(dp[l-a[i]])
    {
      dp[l] = 1;
    }
  }
}

void sov()
{
  for(int i = 1; i <= n ; i++)
  {
    if(num[i] == 1)  get1(i);
    else if(num[i] * a[i] >= m)  getfull(i);
    else
    {
      for(int d = 0 ; d < a[i] ; d++)
      {
        int sum = 0,st = 0,en = -1;
        for(int v = d,cnt = 0; v <= m ; v += a[i],cnt++)
        {
          //printf("num[%d] = %d  cnt = %d\n",i,num[i],cnt);
          if(cnt == num[i]+1)
          {
            sum -= ds[st++];
            //printf("vvvv = %d\n",v-cnt*a[i]);
            cnt--;
          }
          // printf("sum[%d] = %d\n",v,sum);
          sum += dp[v];
          ds[++en] = dp[v];
          // printf("dp[%d] = %d\n",v,dp[v]);
          if(sum)
          {
            dp[v] = 1;
            // printf("v = %d\n",v);
          }
        }
      }
    }
  }
  int cnt = 0;
  for(int i = 1; i <= m ; i++)
    cnt += dp[i];
  printf("%d\n",cnt);
}

int main()
{
  //freopen("watch.in","r",stdin);
  //freopen("watch.out","w",stdout);

  while(~scanf("%d%d",&n,&m) && n)
  {
    if(m == 0)
    {
      printf("0\n");
      continue;
    }
    init();
    sov();
  }

}

