//大根堆排序（sort.cpp）
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
int a[MAXN],n,heapsize;

void Maxheapify(int i)                //定义根结点
{
  int largest;
  int l=i<<1;                         //计算该结点的左孩子下标
  int r=(i<<1)+1;                     //计算该结点的右孩子下标
  if(l<=heapsize && a[i]<a[l])        //记录最大元素的下标
    largest=l;
  else
    largest=i;
  if(r<=heapsize && a[r]>a[largest])
    largest=r;
  if(largest != i)
  {
    swap(a[i],a[largest]);            //交换最大元素与i的值
    Maxheapify(largest);              //递归检查交换后的结点是否满足大根堆性质
  }
}

void BuildMaxHeap()                   //建堆
{
  heapsize=n;
  for(int i=n/2; i>=1; i--)
    Maxheapify(i);
}

void Heapsort()
{
  BuildMaxHeap();                    //建立最大堆
  for(int i=n; i>=2; i--)
  {
    swap(a[1],a[i]);                 //将a[i]与a[1]交换
    --heapsize;                      //剔除交换后的元素a[i]
    Maxheapify(1);                   //维护最大堆性质
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  Heapsort();
  for(int i=1; i<=n; i++)
    cout<<a[i]<<" ";
  return 0;
}

