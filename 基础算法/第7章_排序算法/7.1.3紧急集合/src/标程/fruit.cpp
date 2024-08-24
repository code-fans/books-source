//紧急集合
#include <bits/stdc++.h>
using namespace std;

int n,sum,ans;
int a[20001],b[20001],t[20001];

int main()
{
  freopen("fruit.in","r",stdin);
  freopen("fruit.out","w",stdout);
  scanf("%d",&n);
  memset(a,127,sizeof(a));               //赋数组元素值为最大值
  memset(b,127,sizeof(b));
  for (int i=1,k; i<=n; i++)
  {
    scanf("%d",&k);
    t[k]++;                              //计数排序
  }
  for (int i=1,k=0; i<=20000; i++)
    for(; t[i]; t[i]--)                  //将桶排序的数据依次移到a数组中
      a[++k]=i;
  int k1=1,k2=1;                         //k1,k2为指针，分别指向a[],b[]
  for (int i=1,k=0; i<n; i++)          //i统计合并次数
  {
    sum=a[k1]<b[k2] ? a[k1++] : b[k2++]; //找到第一个合并的值
    sum+=a[k1]<b[k2] ? a[k1++] : b[k2++];//找到第二个合并的值
    b[++k]=sum;                          //合并的值加入第二个数组
    ans+=sum;                            //统计合并值
  }
  printf("%d\n",ans);
}
