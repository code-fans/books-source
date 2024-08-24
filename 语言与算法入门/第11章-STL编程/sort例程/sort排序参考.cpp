//sort排序参考
#include <bits/stdc++.h>//使用万能头文件，故无需写#include <algorithm>
using namespace std;

void print(int a[],int n)
{
  for(int i=0; i<n; i++)
    cout<<a[i]<<' ';
  cout<<endl;
}

int main()
{
  int a[]= {-1,9,-34,100,45,2,98,32};
  const int len=sizeof(a)/sizeof(int);
  sort(a,a+len);//由小到大排序
  //sort(a,a+len,less<int>());//这也可以实现由小到大排序
  print(a,len);

  sort(a,a+len,greater<int>());//由大到小排序
  print(a,len);
  return 0;
}

