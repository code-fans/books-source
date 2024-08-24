//第k小数 - 方法二
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int val,ID;
} a[100001];
int i,j,m,k;

int CMP(st a, st b)                  //对结构体排序的比较函数
{
  return a.val<b.val;
}

void Swap(int i,int j)               //不包含指针交换
{
  swap(a[i].val,a[j].val);
  swap(a[i].ID,a[j].ID);
}

int Find(int START,int END)
{
  i=START;
  j=END;
  while(i!=j)
  {
    if(i<j)
      if(a[i].val>a[j].val)
        Swap(i,j),  swap(i,j);       //此处指针交换
      else
        --j;
    else if(a[i].val<a[j].val)
      Swap(i,j),  swap(i,j);
    else
      ++j;
  }
  if(i==k)
    return a[i].ID;
  else if(i<k)
    Find(i+1,END);
  else
    Find(START,i-1);
}

int main()
{
  //freopen("k1.in","r",stdin);
  //freopen("k1.out","w",stdout);
  scanf("%d%d",&m,&k);
  for(i=1; i<=m; i++)
  {
    scanf("%d",&a[i].val);
    a[i].ID=i;
  }
  for(i=6; i<=m+1; i+=5)             //每五个元素进行组内排序
    sort(a+i-5,a+i,CMP);
  for(i=1; i<=m/5; i++)              //将每组的中位数交换到数组前面
    Swap(i,i*5-2);
  sort(a+1,a+i,CMP);                 //对排到前面的所有中位数排序
  Swap(1,i/2);                       //将中位数中的中位数作为基准
  cout<<Find(1,m)<<endl;
  return 0;
}

