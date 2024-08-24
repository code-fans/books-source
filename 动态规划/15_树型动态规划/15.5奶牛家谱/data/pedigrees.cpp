#include <bits/stdc++.h>
using namespace std;

const int N = 1010 , mod = 9901;

int n , m;
int f[N][N];//f[i][j]表示，当前深度≤i，节点数为j的树的方案数

int main()
{
  //freopen("pedigrees.in","r",stdin);
  //freopen("pedigrees.out","w",stdout);

  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++)//因为深度是≤i，因此f[i][1]都包含f[1][1]这种情况
    f[i][1] = 1;
  for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= n ; j += 2)//因为加的节点数是0或2，因此递增2
      for(int k = 1 ; k < j ; k += 2)
        f[i][j] = (f[i][j] + f[i - 1][k] * f[i - 1][j - k - 1]) % mod;

  cout << (f[m][n] - f[m - 1][n] + mod) % mod << endl;
}

