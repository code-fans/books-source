//逆序输出数组元素值
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("AntiArr.in","r",stdin);
  //freopen("AntiArr.out","w",stdout);
  int a[1001];
  int n=0;
  for(int i=0; cin>>a[i]; i++)
    n++;
  cout<<a[n-1];
  for(int i=n-2; i>=0; i--)
    cout<<' '<<a[i];
  cout<<endl;
  return 0;
}
