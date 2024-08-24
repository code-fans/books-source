//数组元素作函数实参
# include <bits/stdc++.h>
using namespace std;

void change(int a,int b)
{
  swap(a,b); //a与b的值互换
}

int main()
{
  int a[]= {1,2,3,4,5,6,7,8};
  int b[]= {-1,-2,-3,-4,-5,-6,-7,-8};
  int i;
  for(i=0; i<8; i++)
    change(a[i],b[i]);
  for(i=0; i<8; i++)
    printf("%d %d\n",a[i],b[i]);
  return 0;
}

