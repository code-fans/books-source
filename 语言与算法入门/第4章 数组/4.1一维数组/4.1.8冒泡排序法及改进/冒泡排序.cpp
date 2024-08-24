//用冒泡法对n个数排序（由小到大）
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int a[10005],n;//在没赋初值的情况下，数组a里的各元素值未知
  scanf("%d",&n);
  for(int i=1; i<=n; i++)//从下标1即a[1]开始，a[0]不参与运算
    scanf("%d",&a[i]);
  for(int j=1; j<=n-1; j++) //大循环共n-1次
    for(int i=1; i<=n-j; i++) //每个小循环的步数逐次递减
      if(a[i]>a[i+1])//比较两数，如前面数大于后面数,则小数上浮,大数下沉
        swap(a[i],a[i+1]);
  for(int i=1; i<n; i++)
    printf("%d ",a[i]);//最后打印已排好序的数组
  printf("%d\n",a[n]);
  return 0;
}

