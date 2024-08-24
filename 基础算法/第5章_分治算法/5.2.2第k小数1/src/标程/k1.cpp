//第k小数1
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int val,ID;                           //ID保存原始位置
} a[100001];
int m,k;

void Swap(int &i,int &j)               //引用i,j
{
  swap(a[i].val,a[j].val);             //两元素互换
  swap(a[i].ID,a[j].ID);
  swap(i,j);                           //指针互换
}

int Find(int START,int END)
{
  int i=START;
  int j=END;
  while(i!=j)                          //当指针未重合时
  {
    if(i<j)                            //如i指针在j指针左
      if(a[i].val>a[j].val)
        Swap(i,j);
      else
        --j;                           //j指针左移
    else                               //如i指针在j指针右（指针已互换）
      if(a[i].val<a[j].val)
        Swap(i,j);
      else
        ++j;                           //j指针右移
  }
  if(i==k)                             //若已找到第k小数
    return a[i].ID;                    //输出答案即原位置
  else if(i<k)                         //此时i和j已重合
    Find(i+1,END);                     //取右边数组递归查找
  else
    Find(START,i-1);                   //取左边数组递归查找
}

int main()
{
  //freopen("k1.in","r",stdin);
  //freopen("k1.out","w",stdout);
  scanf("%d%d",&m,&k);
  for(int i=1; i<=m; i++)
  {
    scanf("%d",&a[i].val);
    a[i].ID=i;
  }
  cout<<Find(1,m)<<endl;               //在1~m之间开始二分查找
  return 0;
}

