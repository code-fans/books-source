//递归求年龄
#include <bits/stdc++.h>
using namespace std;

int age(int n)
{
  if(n==1)  //递归结束的条件
    return 10;
  else
    return age(n-1)+2; //调用自身
}

int main()
{
  printf("%d\n",age(5));
  return 0;
}

