//最长公共子序列问题 - 算法2
#include <bits/stdc++.h>
using namespace std;
#define M 501

char s1[M],s2[M];
int a[M][M];
int n1,n2;

void Dp()
{
  for(int i=1; i<=n1; ++i)
    for(int j=1; j<=n2; ++j)
      if(s1[i]==s2[j])
        a[i][j]=a[i-1][j-1]+1;
      else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
  cout<<a[n1][n2]<<endl;
}

void Init()
{
  cin>>n1;
  for(int i=1; i<=n1; ++i)
    cin>>s1[i];
  cin>>n2;
  for(int i=1; i<=n2; ++i)
    cin>>s2[i];
}

int main()
{
  //freopen("LCS.in","r",stdin);
  //freopen("LCS.out","w",stdout);
  Init();
  Dp();
  return 0;
}

