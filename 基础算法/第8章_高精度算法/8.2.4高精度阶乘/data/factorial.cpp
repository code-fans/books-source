/*
程序名称：高精度阶乘优化算法1
程序备注：可在1250范围内三三相乘，但优化效果不大
*/
#include <bits/stdc++.h>
using namespace std;
int a[40000]= {0,1},len=1;

void Mul(int i)
{
  int p=0;
  for(int j=1; j<=len; j++)
  {
    a[j]=a[j]*i+p;
    if(a[j]>=10)
    {
      p=a[j]/10;                      //保存进位值
      a[j]%=10;
    }
    else
      p=0;
  }
  while(p>0)                          //对进位值进行处理
  {
    a[++len]=p;
    p=a[len]/10;
    a[len]%=10;
  }
}

int main()
{
  //freopen("factorial.in","r",stdin);
  //freopen("factorial.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n-1; i+=2)
    Mul(i*(i+1));
  if(n&1)                     //如果为奇数
    Mul(n);
  printf("%d!=",n);
  for(int i=len; i>=1; --i)
    printf("%d",a[i]);
  printf("\n");
  return 0;
}

