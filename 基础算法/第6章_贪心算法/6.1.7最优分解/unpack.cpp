/*最优分解
贪心算法。如果a+b=n，则|a-b|越小，那么a*b越大，可以将n分解成从2开始的连续自然数的和。
例如：输入n=10，则可以分解为2、3、4，还剩下1不够5，把这个1倒着加，4 -> 5。
所以，最终分解为2,3,5，结果为2*3*5=30。
如果剩下的数字和前面的数字相等，则最后的再加1
*/
#include <bits/stdc++.h>
using namespace std;

int a[100];               //保存分解后的数

long long Fun(int n)
{
  int k=0;                //k为数组下标指针
  for(int i=2; n>a[k]; i++)
  {
    a[++k]=i;
    n-=i;
  }
  if(n==a[k])             //如果剩下值和最后一个数组元素值相等
    a[k]++;               //最后的数组元素值再加1
  for(int i=0; i<n; i++)  //再把剩下的值逆序每个加1到数组元素中
    a[k-i]++;
  long long sum=1;
  for(int i=1; i<=k; i++) //从下标1开始乘
    sum*=a[i];
  return sum;
}

int main()
{
  freopen("unpack.in","r",stdin);
  freopen("unpack.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%lld\n",Fun(n));
  return 0;
}

