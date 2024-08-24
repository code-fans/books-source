//这其实就是完全背包问题的方案总数，不过要加多一个筛素数的过程
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("prime.in","r",stdin);
  //freopen("prime.out","w",stdout);
  int n=0,m,prime[300],f[300];
  bool b[300];
  memset(b,1,sizeof(b));
  for (int i=2; i<=200; i++)       //先将素数存入数组
    if (b[i])
    {
      prime[++n]=i;
      for ( int j = i*i; j<=200; j+=i)
        b[j] = 0;
    }
  cin>>m;
  memset(f,0,sizeof(f));
  f[0]=1;
  for (int i=1; i<=n; i++)         //枚举每一个物品即素数
    for (int j=prime[i]; j<=m; j++)//枚举背包容量 
      f[j]+=f[j-prime[i]];
  cout<<f[m]<<endl;
  return 0;
}





