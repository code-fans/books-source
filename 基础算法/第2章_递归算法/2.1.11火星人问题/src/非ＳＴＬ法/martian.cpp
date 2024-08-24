//火星人问题
#include <bits/stdc++.h>
using namespace std;

int n,m,j,k,a[10010];

int main()
{
  //freopen("martian.in","r",stdin);
  //freopen("martian.out","w",stdout);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  while(m--)
  {
    for(j=n-1; a[j]>a[j+1]; j--);
    for(k=j; a[k+1]>a[j]; k++);
    swap(a[k],a[j]);
    reverse(a+j+1, a+n+1);//后面是从大到小排列的，翻转就可以了
  }
  for(int i=1; i<=n; i++)
    cout<<a[i]<<(i==n?'\n': ' ');
  return 0;
}
