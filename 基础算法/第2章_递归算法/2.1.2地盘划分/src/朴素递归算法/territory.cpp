//地盘划分 - 朴素递归算法
#include <bits/stdc++.h>
using namespace std;

int Square(int a,int b)
{
  if(a==b)
    return 1;
  if(a>b)
    swap(a,b);
  return Square(a,b-a)+1;
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
