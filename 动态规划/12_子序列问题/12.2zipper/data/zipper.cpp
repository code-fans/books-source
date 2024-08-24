//zipper
#include <bits/stdc++.h>
using namespace std;

string A,B,C;
int Dp[201][201];

void Work(int n,int l1,int l2,int l3)
{
  for(int i=1; i<=l1; ++i)                         //边界条件
    Dp[i][0]=Dp[i-1][0]+(A[i-1]==C[i-1]);
  for(int i=1; i<=l2; ++i)                         //边界条件
    Dp[0][i]=Dp[0][i-1]+(B[i-1]==C[i-1]);
  for(int i=1; i<=l1; ++i)
    for(int j=1; j<=l2; ++j)
      Dp[i][j]=max(Dp[i-1][j]+(A[i-1]==C[i+j-1]),
                   Dp[i][j-1]+(B[j-1]==C[i+j-1]));
  cout<<"Data set "<<n<<':'<<(Dp[l1][l2]==l3?" yes":" no")<<endl;
}

int main()
{
  //freopen("zipper.in","r",stdin);
  //freopen("zipper.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; ++i)
  {
    cin>>A>>B>>C;
    Work(i,A.size(),B.size(),C.size());
  }
  return 0;
}

