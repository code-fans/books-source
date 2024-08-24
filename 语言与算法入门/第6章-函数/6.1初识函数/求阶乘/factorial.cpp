//n的阶乘
#include <bits/stdc++.h>
//typedef为unsigned long long创建别名为ULL
typedef unsigned long long ULL;
using namespace std;

ULL Factorial(int n)                //此处的ULL即为unsigned long long
{
  if(n<0)
    exit(0);                        //退出程序
  else if(n==0 || n==1)
    return 1;
  else
    return Factorial(n-1)*n;
}

main()
{
  //freopen("factorial.in","r",stdin);
  //freopen("factorial.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%d!=%llu\n",n,Factorial(n));//注意unsigned long long的输出格式
  return 0;
}

