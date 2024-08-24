//最长不下降序列 - 动规优化算法
#include <bits/stdc++.h>
using namespace std;

int a[100001];
int Link[100001];              //Linux下有一个link的函数，不要同名
int Long[100001];

int Find(int key,int Max)      //二分查找
{
  int L=1,R=Max,mid;
  while(L<=R)
  {
    mid=(L+R)>>1;
    if(a[Long[mid]]<key)
      L=mid+1;
    else R=mid-1;
  }
  return L-1;
}

int main()
{
  freopen("robot.in","r",stdin);
  freopen("robot.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  int Max=1;                   //初始最长序号数为1
  Long[Max]=1;                 //初始为第一个元素
  Link[1]=1;                   //初始链为第一个元素
  for(int t=2; t<=n; ++t)
    if(a[t]>=a[Long[Max]])     //接在既定序列之后
    {
      Long[++Max]=t;
      Link[t]=Long[Max-1];
    }
    else                       //在既定序列中查找位置并插入
    {
      int j=Find(a[t],Max);
      Long[j+1]=t;
      Link[t]=Long[j];
    }
  printf("%d\n",Max);
  /*  此段可输出最长链的各元素
  int k=Max;
  int i=Long[Max];
  while(Max>0)
  {
    Long[Max]=a[i];            //改为 Long[Max]=i 可输出序号
    i=Link[i];
    Max--;
  }
  for(i=1; i<=k; i++)
    cout<<Long[i]<<' ';
  */
  return 0;
}

