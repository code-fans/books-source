//输出等边三角形的递归解决
#include <bits/stdc++.h>
using namespace std;

void trangle(char c,int n)
{
  if(n>0)
  {
    printf("%c",c);
    trangle(c,n-1);
  }
}

int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=1; i<=n; ++i)
  {
    trangle(' ',n-i);//输出空格
    trangle('*',2*i-1);//输出星号
    printf("\n");
  }
  return 0;
}

