//哥德巴赫猜想
#include<bits/stdc++.h>
using namespace std;

int fflag(int i)           //判断是否为素数
{
  if(i==2)
    return 1;
  if(!(i%2))               //如果是偶数,return 0
    return 0;
  int k=sqrt(i);
  for(int j=3; j<=k; j+=2)
    if(!(i%j))
      return 0;
  return 1;                //如果是素数,return 1
}

int main()
{
  //freopen("Goldbach.in","r",stdin);
  //freopen("Goldbach.out","w",stdout);
  for(int i=4; i<=2000; i+=2)
    for(int n=2; n<i; n++) //将偶数i分解为两个整数
      if(fflag(n) && fflag(i-n))     //分别判断两个整数是否均为素数
      {
        printf("%d=%d+%d\n",i,n,i-n);//若均是素数则输出
        break;
      }
  return 0;
}

