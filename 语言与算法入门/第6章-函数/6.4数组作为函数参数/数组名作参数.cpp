//数组名作参数
#include <bits/stdc++.h>
using namespace std;

void change(int x[],int y[])
{
  for(int i=0; i<8; i++)
    swap(x[i],y[i]);
}

int main()
{
  int a[]= {1,2,3,4,5,6,7,8};
  int b[]= {-1,-2,-3,-4,-5,-6,-7,-8};
  change(a,b);//数组名a,b作参数
  for(int i=0; i<8; i++)
    printf("%d %d\n",a[i],b[i]);
  return 0;
}

