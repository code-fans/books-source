//大根堆排序（sort.cpp）
#include <bits/stdc++.h>
using namespace std;
const int N=100000;

int a[N+1];

void Adjust_down(int i,int m)                //调整
{
  while(i*2<=m)                              //当还有子结点时
  {
    i<<=1;                                   //即i=i*2,找到左子结点下标
    if(i<m && a[i+1]>a[i])                   //如果右子结点比左子结点更大
      i++;                                   //则i指向右子结点
    if(a[i]>a[i/2])                          //子结点比父结点更大
      swap(a[i/2],a[i]);                     //最大子结点与父结点交换
    else                                     //父子结点无交换则结束调整
      break;                                 //因为是逐步由下至上调整的
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)                    //顺序读入结点
    cin>>a[i];
  for(int i=n/2; i>=1; i--)                  //从n/2开始调整
    Adjust_down(i,n);                        //建堆
  for(int i=n; i>=2; i--)                    //排序
  {
    swap(a[i],a[1]);                         //每次交换最大值到最后
    Adjust_down(1,i-1);
  }
  for(int i=1; i<n; i++)                    //从小到大输出
    cout<<a[i]<<' ';
  cout<<a[n]<<endl;
  return 0;
}

