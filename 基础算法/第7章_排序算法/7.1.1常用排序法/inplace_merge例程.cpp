//inplace_merge例程
#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main()
{
  int n,m;
  cin>>n;
  for(int i=0; i<n; i++)//升序归并输入升序序列，降序归并输入降序序列
    cin>>a[i];
  cin>>m;
  for(int i=n; i<n+m; i++)
    cin>>a[i];
  inplace_merge(a,a+n,a+n+m);//升序内部归并
  //inplace_merge(b,b+6,b+len,greater<int>());//降序内部归并
  for(int i=0; i<n+m; i++)
    cout<<a[i]<<' ';
  return 0;
}

