//优化算法3：万进制阶乘
#include <bits/stdc++.h>
using namespace std;
#define MAXN 40000
#define BASE 10000

int a[MAXN+1],len=1;

void mul(int i)
{
  int p=0;
  for(int j=MAXN; j>=MAXN-len+1; j--)
  {
    a[j]=a[j]*i+p;
    if(a[j]>=BASE)
    {
      p=a[j]/BASE;
      a[j]%=BASE;
    }
    else
      p=0;
  }
  while(p>0)
  {
    ++len;
    a[MAXN-len+1]=p;
    p=a[MAXN-len]/BASE;
    a[MAXN-len+1]%=BASE;
  }
}

int main()
{
  //freopen("factorial.in","r",stdin);
  //freopen("factorial.out","w",stdout);
  int n;
  scanf("%d",&n);
  a[MAXN]=1;
  printf("%d!=",n);
  for(int i=1; i<=n; i++)
    mul(i);
  if(a[MAXN-len+1])
    printf("%d",a[MAXN-len+1]);
  for(int i=MAXN-len+2; i<=MAXN; i++)
    printf("%04d",a[i]);
  printf("\n");
  return 0;
}

