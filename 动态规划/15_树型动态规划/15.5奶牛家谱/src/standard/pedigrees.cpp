#include <bits/stdc++.h>
using namespace std;

const int N = 1010 , mod = 9901;

int n , m;
int f[N][N];//f[i][j]��ʾ����ǰ��ȡ�i���ڵ���Ϊj�����ķ�����

int main()
{
  //freopen("pedigrees.in","r",stdin);
  //freopen("pedigrees.out","w",stdout);

  cin >> n >> m;
  for(int i = 1 ; i <= m ; i++)//��Ϊ����ǡ�i�����f[i][1]������f[1][1]�������
    f[i][1] = 1;
  for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= n ; j += 2)//��Ϊ�ӵĽڵ�����0��2����˵���2
      for(int k = 1 ; k < j ; k += 2)
        f[i][j] = (f[i][j] + f[i - 1][k] * f[i - 1][j - k - 1]) % mod;

  cout << (f[m][n] - f[m - 1][n] + mod) % mod << endl;
}

