//直接插入排序法
#include <bits/stdc++.h>
#define N 100000
int a[N+1];

void InsertSort(int n,int a[])
{
  for(int i=2; i<=n; i++)               //插入元素从第2个位置开始
  {
    int j,insert=a[i];                  //a[i]为要插入的数,赋值给insert以防丢失
    for(j=i-1; j>=1 && insert<a[j]; --j)//从a[i-1]开始向前找比a[i]小的数
      a[j+1]=a[j];                      //前面比a[i]大的数依次向后挪一个位置保存
    a[j+1]=insert;                      //a[i]的值插入到正确位置
  }
}
int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  InsertSort(n,a);                        //插入排序
  for(int i=1; i<=n; ++i)
    printf("%d ",a[i]);
  return 0;
}
