//merge����
#include <bits/stdc++.h>
using namespace std;

int a[10001],b[10001];

int main()
{
  int n,m;
  cin>>n;
  for(int i=0; i<n; i++)      //�������ź��������a 
    cin>>a[i];
  cin>>m;
  for(int i=0; i<m; i++)      //�������ź��������b 
    cin>>b[i];
  int result[n+m];
  merge(a,a+n,b,b+m,result);  //����鲢
  //merge(a,a+n,b,b+m,result,greater<int>());//����鲢
  for(int i=0; i<n+m; i++)
    cout<<result[i]<<' ';
  return 0;
}

