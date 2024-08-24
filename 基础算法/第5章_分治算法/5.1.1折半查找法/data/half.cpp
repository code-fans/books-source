//非递归的折半查找法
#include <bits/stdc++.h>
using namespace std;

int key,n,a[10010];

void Half()                              //二分查找法
{
  int Left=1;
  int Right=n;
  while (Left<=Right)
  {
    int mid=(Right+Left)>>1;
    if (key==a[mid])                     //如果正好找到
    {
      printf("%d\n",mid);
      exit(0);
    }
    else if (key<a[mid])                 //选择左半段
      Right=mid-1;
    else                                 //选择右半段
      Left=mid+1;
  }
  puts("-1");
}

int main ()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  cin>>key;
  Half();
  return 0;
}

