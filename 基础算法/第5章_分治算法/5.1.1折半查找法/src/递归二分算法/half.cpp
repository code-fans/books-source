//递归的折半查找法
#include <bits/stdc++.h>
using namespace std;
int a[10010],key,n;

int Search(int Left,int Right)  //在Left~Right这一段查找
{
  if(Right>=Left)
  {
    int mid=(Left+Right)/2;     //取中间值mid，用位运算（left+Right）>>1速度更快
    if(key==a[mid])             //如果相等,则打印该数
    {
      printf("%d\n",mid);
      return 0;
    }
    else if(key<a[mid])         //如key小于中间值,则取前半段
      Search(Left,mid-1);
    else                        //如key大于中间值,则取后半段
      Search(mid+1,Right);
  }
  else
  {
    printf("-1\n");
    return 0;
  }
}

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; ++i)       //从下标1开始
    cin>>a[i];
  cin>>key;
  Search(1,n);
  return 0;
}

