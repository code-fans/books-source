//最长公共子序列问题 - 算法3
#include <bits/stdc++.h>
using namespace std;
#define M 501

int n1,n2;
char s1[M],s2[M];
int b[M],a[M];

void init()
{
  cin>>n1;
  for(int i=1; i<=n1; i++)
    cin>>s1[i];
  cin>>n2;
  for(int i=1; i<=n2; i++)
    cin>>s2[i];
}

void dp()
{
  for(int i=1; i<=n1; ++i)
  {
    for(int j=1; j<=n2; ++j)
      if(s1[i]==s2[j])
        a[j]=b[j-1]+1;
      else
        a[j]=max(a[j-1],b[j]);
    memcpy(b,a,sizeof(a));
  }
  cout<<a[n2]<<endl;
}

int main()
{
  //freopen("LCS.in","r",stdin);
  //freopen("LCS.out","w",stdout);
  init();
  dp();
  return 0;
}

