#include <bits/stdc++.h>
using namespace std;

int f[205][205];
int len[205];

int main()
{
  //freopen("demon.in","r",stdin);
  //freopen("demon.out","w",stdout);
  int n,k;
  cin>>n>>k;
  if(k>=2*n-1)
  {
    cout<<0<<endl;
    return 0;
  }
  for(int i=1; i<n; i++)
    len[2*i-1]=len[2*i]=2*i-1;  //设置每一列的长度
  len[2*n-1]=2*n-1;
  for(int i=0; i<=2*n-1; i++)//给每一个f的第一个值赋初值1
    f[i][0]=1;
  for(int i=1; i<=2*n-1; i++)
    for(int j=1; j<=len[i]; j++)
    {
      f[i][j]=f[i-1][j]+f[i-1][j-1]*(len[i]-(j-1));
      f[i][j]%=504;
    }
  cout<<f[2*n-1][k]<<endl;
  return 0;
}

