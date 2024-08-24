//高精度分数优化算法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int Delay(int x)                          //计算延迟数的位数
{
  int n2=0,n5=0;
  while(x%2==0)
  {
    n2++;
    x/=2;
  }
  while(x%5==0)
  {
    n5++;
    x/=5;
  }
  return n2>n5?n2:n5;
}

int Gcd(int a, int b)                     //欧几里得迭代求最大公约数
{
  return a%b?Gcd(b,a%b):b;
}

int Repetend(int x)                       //计算循环节位数
{
  int digit,k=9;
  while(x%2==0)                           //质因数中除去所有2和5
    x/=2;
  while(x%5==0)
    x/=5;
  for(digit=1; digit<=MAXN; ++digit)      //查找最小的k值，满足10^k－1被x整除
  {
    if(k%x==0)
      break;
    k=k%x*10+9;
  }
  return digit;
}

void compute(int m,int n,int delay,int repetend)
{
  int digit=delay+repetend;
  for(int i=1; i<=digit; ++i)
  {
    m*=10;                               //余数扩大10位
    cout<<m/n;
    m%=n;                                //求下一个余数
    if(m==0)                             //余数为0,则为有限小数
    {
      printf("\n");
      return;                           //退出循环
    }
  }
  printf("\n");
  cout<<"from "<<delay+1<<" to "<<digit<<"\n";
}

int main()
{
  //freopen("fraction.in","r",stdin);
  //freopen("fraction.out","w",stdout);
  int m,n;
  scanf("%d/%d",&m,&n);
  printf("%d/%d=0.",m,n);
  int gcd=Gcd(m,n);                           //求最大公约数
  m/=gcd;
  n/=gcd;
  compute(m,n,Delay(n),Repetend(n));
  return 0;
}

