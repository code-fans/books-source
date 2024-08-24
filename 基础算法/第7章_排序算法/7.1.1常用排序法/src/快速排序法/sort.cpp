//朴素快速排序
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int a[N];

void QuickSort(int i,int j)               //快排函数
{
  int m=i,n=j;
  int k=a[(i+j)>>1];                      //选取中间元素
  while(m<=n)
  {
    while(a[m]<k)  m++;                   //从左到右找比k大的元素
    while(a[n]>k)  n--;                   //从右到左找比k小的元素
    if(m<=n)
      swap(a[m++],a[n--]);                //交换,且指针指向下一元素
  }
  if(m<j)  QuickSort(m,j);                //递归
  if(n>i)  QuickSort(i,n);
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  QuickSort(1,n);
  for(int i=1; i<=n; i++)
    printf("%d ",a[i]);
  return 0;
}

