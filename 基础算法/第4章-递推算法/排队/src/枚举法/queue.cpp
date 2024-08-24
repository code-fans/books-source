//排队 - 枚举法
#include <bits/stdc++.h>
using namespace std;
int a[30001],n,num;

int main()
{
  //freopen("queue.in","r",stdin);
  //freopen("queue.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&num);
    a[i]=a[i-1]+num-1;                    //a[i]表示从第1到第i编号为2的顾客数
  }
  int minx=n;
  for(int i=0; i<=n; i++)                 //穷举i的位置
    if(minx>a[i]+n-i-(a[n]-a[i]))         //前i个顾客全变为1,后i+1~n个全变为2
      minx=a[i]+n-i-(a[n]-a[i]);
  printf("%d\n",minx);
  return 0;
}

