//求组合问题c(m,n)的递归解决
#include <bits/stdc++.h>
using namespace std;

int combin(int m,int n)
{
  int com;
  if (n<2*m)//优化
    m=n-m;
  if (m==0) /*终止递归调用的条件*/
    com=1;
  else if (m==1)
    com=n;
  else
    com=combin(m,n-1)+combin(m-1,n-1);
  return com;
}

int main()
{
  int m,n;
  scanf("%d %d",&m,&n);//输入4 7 结果为35
  printf("%d\n",combin(m,n));
  return 0;
}

