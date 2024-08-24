//贪心的老板
#include<bits/stdc++.h>
using namespace std;
const int MAXH=100000;
const int INF=0xffffff;

int n,heapsize;                      //堆的大小
int a[MAXH];                         //堆中元素的值

void Maxheapify(int i)               //维护大根堆
{
  int largest;
  int l=i<<1;                        //左子树下标
  int r=(i<<1)+1;                    //右子树下标
  if(l<=heapsize && a[i]<a[l])
    largest=l;
  else
    largest=i;
  if(r<=heapsize && a[r]>a[largest])
    largest=r;
  if(largest != i)
  {
    swap(a[i],a[largest]);
    Maxheapify(largest);
  }
}

void BuildMaxHeap()                  //建立大根堆
{
  heapsize=n;
  for(int i=n/2; i>=1; i--)
    Maxheapify(i);
}

int ExtractMax(int a[])             //弹出并返回堆中最大元素
{
  int Max=a[1];
  a[1]=a[heapsize];
  a[heapsize]=-1;
  heapsize--;
  Maxheapify(1);                    //维护弹出后堆的性质
  return Max;
}

void HeapIncreaseKey(int i,int key) //改变结点当前的值
{
  if(a[i]>key)                      //更改的值必须要大于当前的值
  {
    cout<<"-1\n";
    return;
  }
  a[i]=key;
  while(i>1 && a[i>>1]<a[i])        //旋转并保持堆的性质
  {
    swap(a[i],a[i>>1]);
    i=i>>1;
  }
}

void MaxHeapInsert(int key)         //往堆中插入一个元素
{
  heapsize++;
  a[heapsize]=-INF;                 //初始化插入元素为极小值
  HeapIncreaseKey(heapsize,key);    //插入元素
}

int main()                          //演示操作
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int i,key,v;
  cin>>n;
  for(i=1; i<=n; i++)
    cin>>a[i];
  BuildMaxHeap();                   //构建堆
  while(1)
  {
    cin>>i;
    if(i==1)                        //显示最大优先值
      cout<<a[1]<<"\n";
    else if(i==2)                   //最大优先值出列
      cout<<ExtractMax(a)<<"\n";
    else if(i==3)                   //改变某元素的优先值
    {
      cin>>v>>key;
      HeapIncreaseKey(v,key);
    }
    else if(i==4)                   //插入新的元素
    {
      cin>>key;
      MaxHeapInsert(key);
    }
    else                            //退出
      break;
    getchar();
  }
  return 0;
}

