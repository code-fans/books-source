//求两数中的最大数
#include <bits/stdc++.h>
using namespace std;

int Max(int a,int b)      //Max为一个子函数
{
  return (a>b?a:b);       //返回值为a,b中的最大值
}

int main()
{
  int x,y;
  scanf("%d %d",&x,&y);
  printf("%d\n",Max(x,y));//调用Max函数，并将x,y值传递给Max函数
  return 0;
}

