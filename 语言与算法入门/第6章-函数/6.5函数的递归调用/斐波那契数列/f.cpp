//斐波那契数列改进算法
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;//设置unsigned long long的别名为ULL

ULL a[500];
ULL f(int n)
{
  if(n<3)
    a[n]=1;
  if(a[n]>0)//若已求出第n项的值
    return a[n];//直接返回该值
  a[n]=f(n-1)+f(n-2);//保存递归求出的值
  return a[n];
}

int main()
{
  freopen("f.in","r",stdin);
  freopen("f.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%llu\n",f(n));
  return 0;
}

