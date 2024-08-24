//判断素数函数
#include <bits/stdc++.h>
using namespace std;
void prime(int number);//对子函数的声明

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  int num;
  scanf("%d",&num);
  prime(num);
  return 0;
}

void prime(int number)  //无需返回值时，需在前面加上void
{
  int flag=1,k=sqrt(number);//flag为是否素数的标记
  for(int n=2; n<=k; ++n)
    if(number%n==0)
    {
      flag=0;
      break;
    }
  flag?printf("1\n"):printf("0\n");
}

