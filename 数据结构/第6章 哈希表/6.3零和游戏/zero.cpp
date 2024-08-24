//ÁãºÍÓÎÏ·2
#include <bits/stdc++.h>
using namespace std;
#define maxn 4004
int f1[maxn * maxn],f2[maxn * maxn];
int a[maxn], b[maxn], c[maxn], d[maxn];

int main()
{
  freopen("zero.in","r",stdin);
  freopen("zero.out","w",stdout);
  int n;
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      f1[i * n + j] = a[i] + b[j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      f2[i * n + j] = c[i] + d[j];
  sort(f1, f1 + n * n);
  sort(f2, f2 + n * n);
  int r = n * n - 1;
  int ans = 0;
  for (int i = 0; i < n * n; i++)         //f1[]´Ó×óÍùÓÒÉ¨Ãè
  {
    while (r >= 0 && f1[i] + f2[r] > 0)   //f2[]´ÓÓÒÍù×óÉ¨Ãè
      r--;
    if (r < 0)  break;
    int temp = r;
    while (temp >= 0 && f1[i] + f2[temp] == 0)
      ans++, temp--;
  }
  cout<<ans<<endl;
  return 0;
}

