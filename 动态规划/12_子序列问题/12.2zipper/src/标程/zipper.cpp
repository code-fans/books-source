//zipper
#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3;
int Dp[201][201];

void Work(int n,int l1,int l2,int l3)
{
  for(int i=1; i<=l1; ++i)                         //边界条件
    Dp[i][0]=Dp[i-1][0]+(s1[i-1]==s3[i-1]);
  for(int i=1; i<=l2; ++i)                         //边界条件
    Dp[0][i]=Dp[0][i-1]+(s2[i-1]==s3[i-1]);
  for(int i=1; i<=l1; ++i)
    for(int j=1; j<=l2; ++j)
      Dp[i][j]=max(Dp[i-1][j]+(s1[i-1]==s3[i+j-1]),
                   Dp[i][j-1]+(s2[j-1]==s3[i+j-1]));
  cout<<"Data set "<<n<<':'<<(Dp[l1][l2]==l3?"yes":"no")<<endl;
}

int main()
{
  //freopen("zipper.in","r",stdin);
  //freopen("zipper.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; ++i)
  {
    cin>>s1>>s2>>s3;
    Work(i,s1.size(),s2.size(),s3.size());
  }
  return 0;
}

