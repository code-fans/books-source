//inplace_merge����
#include <bits/stdc++.h>
using namespace std;

int a[10001];

int main()
{
  int n,m;
  cin>>n;
  for(int i=0; i<n; i++)//����鲢�����������У�����鲢���뽵������
    cin>>a[i];
  cin>>m;
  for(int i=n; i<n+m; i++)
    cin>>a[i];
  inplace_merge(a,a+n,a+n+m);//�����ڲ��鲢
  //inplace_merge(b,b+6,b+len,greater<int>());//�����ڲ��鲢
  for(int i=0; i<n+m; i++)
    cout<<a[i]<<' ';
  return 0;
}

