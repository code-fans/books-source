//购物问题
#include <bits/stdc++.h>
#define N 110
#define M 1100
#define INY 1E100
using namespace std;

int sum1[N],sum2[M];
double price[M],opt[M][N];

int main()
{
  //freopen("shopping.in","r",stdin);
  //freopen("shopping.out","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {
    cin>>sum1[i];
    opt[0][i]=INY;                               //初始化
  }
  for(int i=1; i<=m; i++)
    cin>>sum2[i]>>price[i];
  for(int i=1; i<=m; i++)
    for(int j=0; j<=n; j++)
    {
      opt[i][j]=opt[i-1][j];
      if(j>0 && sum1[j]==sum2[i] && opt[i-1][j-1]+price[i]<opt[i][j])
        opt[i][j]=opt[i-1][j-1]+price[i];
    }
  opt[m][n]>1E99?printf("Impossible\n"):printf("%0.2lf\n",opt[m][n]);
  return 0;
}

