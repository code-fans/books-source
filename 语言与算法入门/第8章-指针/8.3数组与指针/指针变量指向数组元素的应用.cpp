//指针变量指向数组元素的应用
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[10]= {1,2,3,4,5,6,7,8,9,10};
  int *p=a;               //可以在定义指针变量的同时赋初值
  for(int i=0; i<10; i++) //以下标方式输出a[]中所有元素
    printf("%d ",p[i]);   //相当于定义了数组p[]，p[]和a[]在内存中重叠
  for(; p<(a+10); p++)    //以指针方式输出，p++指向下一元素而非加1
    printf("%d ",*p);
  return 0;
}

