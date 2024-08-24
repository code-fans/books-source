//确定基因功能
#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int tab[5][5]= {{5,-1,-2,-1,-3},
  {-1,5,-3,-2,-4},
  {-2,-3,5,-2,-2},
  {-1,-2,-2,5,-1},
  {-3,-4,-2,-1,0}
};

int dp[N][N],la,lb,T;

int main()
{
  freopen("gene.in","r",stdin);
  freopen("gene.out","w",stdout);
  map<char,int>m;
  m['A']=0;
  m['C']=1;
  m['G']=2;
  m['T']=3;
  cin>>T;
  while(T--)
  {
    string a,b;
    cin>>la>>a>>lb>>b;
    for(int i=1; i<=la; i++)
      for(int j=1; j<=lb; j++)
        dp[i][j]=-0x7fffffff;
    for(int i=1; i<=la; i++)
      dp[i][0]=dp[i-1][0]+tab[m[a[i-1]]][4];
    for(int i=1; i<=lb; i++)
      dp[0][i]=dp[0][i-1]+tab[m[b[i-1]]][4];
    for(int i=1; i<=la; i++)
      for(int j=1; j<=lb; j++)
      {
        dp[i][j]=max(dp[i][j],dp[i][j-1]+tab[m[b[j-1]]][4]);
        dp[i][j]=max(dp[i][j],dp[i-1][j]+tab[m[a[i-1]]][4]);
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+tab[m[a[i-1]]][m[b[j-1]]]);
      }
    cout<<dp[la][lb]<<endl;
  }
  return 0;
}

