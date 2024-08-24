//merge例程
#include <bits/stdc++.h>
using namespace std;

int a[10001],b[10001];

int main()
{
  int n,m;
  cin>>n;
  for(int i=0; i<n; i++)      //输入已排好序的序列a 
    cin>>a[i];
  cin>>m;
  for(int i=0; i<m; i++)      //输入已排好序的序列b 
    cin>>b[i];
  int result[n+m];
  merge(a,a+n,b,b+m,result);  //升序归并
  //merge(a,a+n,b,b+m,result,greater<int>());//降序归并
  for(int i=0; i<n+m; i++)
    cout<<result[i]<<' ';
  return 0;
}

