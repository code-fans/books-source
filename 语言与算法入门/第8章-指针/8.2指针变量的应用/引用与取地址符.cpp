//引用与取地址操作
#include <bits/stdc++.h>
using namespace std;

void swap1(int *x,int *y)//取地址
{
  int z=*x;
  *x=*y;
  *y=z;
}

void swap2(int &x,int &y)//引用
{
  int z=x;
  x=y;
  y=z;
}

int main()
{
  int a=1,b=-1;
  swap1(&a,&b);//函数要求输入为指针，需要取地址符
  printf("   a=%d,b=%d\n",a,b);
  swap2(a,b);//引用不需要取地址符
  printf("   a=%d,b=%d\n",a,b);
  return 0;
}
