//通过指针变量输出数组元素，这是一个错误的程序
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int *p,i,a[10];
  p=a;
  for(i=0; i<10; i++)
  {
    scanf("%d",p);//注意此处写法
    p++;
  }
  printf("\n");
  for(i=0; i<10; i++,p++)
    printf("%d ",*p);
  return 0;
}

