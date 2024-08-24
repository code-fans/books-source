//确定基因功能
#include <bits/stdc++.h>
using namespace std;
#define N 105

const int tab[5][5]=
{
  {5,-1,-2,-1,-3},
  {-1,5,-3,-2,-4},
  {-2,-3,5,-2,-2},
  {-1,-2,-2,5,-1},
  {-3,-4,-2,-1,0}
};
int dp[N][N],a[N],b[N],la,lb,T;
string s1,s2;

void Init(string s,int len,int a[])
{
  for(int i=1; i<=len; i++)
  {
    if(s[i-1]=='A') a[i]=0;
    if(s[i-1]=='C') a[i]=1;
    if(s[i-1]=='G') a[i]=2;
    if(s[i-1]=='T') a[i]=3;
  }
}

int main()
{
  //freopen("gene.in","r",stdin);
  //freopen("gene.out","w",stdout);
  cin>>T;
  while(T--)
  {
    cin>>la>>s1>>lb>>s2;
    for(int i=1; i<=la; i++)
      for(int j=1; j<=lb; j++)
        dp[i][j]=-0x7fffffff;
    Init(s1,la,a);
    Init(s2,lb,b);
    for(int i=1; i<=la; i++)
      dp[i][0]=dp[i-1][0]+tab[a[i]][4];
    for(int i=1; i<=lb; i++)
      dp[0][i]=dp[0][i-1]+tab[b[i]][4];
    for(int i=1; i<=la; i++)
      for(int j=1; j<=lb; j++)
      {
        dp[i][j]=max(dp[i][j],dp[i][j-1]+tab[b[j]][4]);
        dp[i][j]=max(dp[i][j],dp[i-1][j]+tab[a[i]][4]);
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+tab[a[i]][b[j]]);
      }
    printf("%d\n",dp[la][lb]);
  }
  return 0;
}
