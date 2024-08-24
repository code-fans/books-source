//双塔问题 - 数学归纳+高精度
#include <bits/stdc++.h>
using namespace std;

const int one=10000;
int a[31]= {1,1};               //a[0]存储最高位的下标，a[1]=1即初始值为1

void time()                     //万进制高精度运算
{
  int x=0;
  for(int i=1; i<=a[0]; i++)
  {
    x+=a[i]*2;
    a[i]=x%one;
    x=x/one;
  }
  while(x>0)                    //整理进位
  {
    a[0]++;
    a[a[0]]=x%one;
    x/=one;
  }
}

int main()
{
  freopen("hanoi2.in","r",stdin);
  freopen("hanoi2.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n+1; i++)
    time();
  a[1]-=2;
  printf("%d",a[a[0]]);         //a[0]保存最高位的下标
  for(int i=a[0]-1; i>=1; i--)
  {
    printf("%d",a[i]/1000);
    printf("%d",a[i]/100%10);
    printf("%d",a[i]/10%10);
    printf("%d",a[i]%10);
  }
  return 0;
}

