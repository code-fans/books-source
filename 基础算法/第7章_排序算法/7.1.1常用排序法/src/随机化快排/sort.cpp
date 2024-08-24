//随机化快速排序法
#include <bits/stdc++.h>
using namespace std;

int a[100001];

void QuickSort(int L,int R)
{
  int m=L,n=R;
  for(int k=a[rand()%(R-L+1)+L]; m<=n;)  //k为随机确定的元素
  {
    while(a[m]<k)  m++;                  //从左到右找比k大的元素
    while(a[n]>k)  n--;                  //从右到左找比k小的元素
    if(m<=n)                             //若找到且满足条件，则交换
      swap(a[m++],a[n--]);
  }
  if(m<R)  QuickSort(m,R);               //递归
  if(n>L)  QuickSort(L,n);
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  srand(time(0));                        //随机化种子
  QuickSort(1,n);
  for(int i=1; i<=n; i++)
    printf("%d ",a[i]);
  return 0;
}

