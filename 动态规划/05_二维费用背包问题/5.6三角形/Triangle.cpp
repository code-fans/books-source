//三角形
//所有边都用上，可知周长,所以只需要知道两条边即可
//三角形每条边长不会超过周长一半，所以边枚举一半就行
//dp[i][j][k]表示前i个木棒能否组成第一条边为长度j，第二条长度为k的三角形
// 
#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005],l[1005];

int  Area(int a,int b,int c)//计算三角形面积
{
  double p=(a+b+c)*0.5;
  return int (sqrt(p*(p-a)*(p-b)*(p-c))*100);
}

int main()
{
  freopen("Triangle.in","r",stdin);
  freopen("Triangle.out","w",stdout);
  int n;
  while(~scanf("%d",&n))
  {
    int sum=0, ans=-1;
    for(int i=1; i<=n; i++)
    {
      scanf("%d",&l[i]);
      sum+=l[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;                                //所有边的长度是周长
    int longest=sum/2-(sum/2==0);

    for(int k=1; k<=n; k++)                    //枚举n条边
      for(int i=longest; i>=0; i--)
        for(int j=i; j>=0; j--)
          if(dp[i][j])
            dp[i][j+l[k]]=dp[i+l[k]][j]=1;

    for(int i=longest; i>=1; i--)
      for(int j=i; j>=1; j--)
        if(dp[i][j])
          ans=max(ans,Area(i,j,sum-i-j));
    printf("%d\n",ans);
  }
  return 0;
}
