//地盘划分 - 优化递归算法
#include <bits/stdc++.h>
using namespace std;

int Square(int a,int b)
{
  if(a>b)
    swap(a,b);
  if(b%a)
    return Square(a,b%a)+b/a;
  else
    return b/a;
}

int main()
{
  //freopen("territory.in","r",stdin);
  //freopen("territory.out","w",stdout);
  int x,y;
  scanf("%d %d",&x,&y);
  printf("%d\n",Square(x,y));
  return 0;
}

