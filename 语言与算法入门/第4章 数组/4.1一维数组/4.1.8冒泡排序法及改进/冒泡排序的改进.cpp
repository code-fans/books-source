//冒泡排序法的改进 - 有一类数据无法通过测试，请找出问题所在并解决
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  cin>>n;
  int a[n+1];//可动态定义数组大小,但不能同时赋值,如int a[n+1]={0};
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  int k=2,LastSwap;//k靠近数组左端的位置，LastSwap为最后交换的位置
  while(k<n)//当左端a[k]的位置小于右端a[n]的位置,即还有数要比较
  {
    LastSwap=n;            //先设定这一轮扫描最后交换位置为n
    for(int j=n; j>=k; j--)//从后向前扫描到k（从前向后扫描也一样）
      if(a[j]<a[j-1])      //如果后面的数比前面的数小
      {
        swap(a[j],a[j-1]); //交换a[j]和a[j-1]的值
        LastSwap=j;        //记录最后的变更位置
      }
    k=LastSwap;            //下一轮只需比较到上一轮的LastSwap
  }
  for(int i=1; i<n; i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n]);
  return 0;
}

