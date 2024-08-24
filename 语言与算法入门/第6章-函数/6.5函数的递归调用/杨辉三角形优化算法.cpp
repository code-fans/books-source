//杨辉三角形优化算法
#include <bits/stdc++.h>
using namespace std;
int a[14][14];//数组用于存储杨辉三角形各元素的值

int c(int x,int y)/*求杨辉三角形中第x行第y列的值*/
{
  if((y==1)||(y==x+1))
    a[x][y]=1; //若为两斜边，则值为1
  if(a[x][y]!=0)//如果该位置的值已经计算过
    return a[x][y];//则无需递归计算，直接返回该值即可
//计算前一行中第y-1列与第y列值之和并存入a[x][y]
  a[x][y]=c(x-1,y-1)+c(x-1,y);
  return a[x][y];
}

int main()
{
  int i,j,n;
  do
  {
    printf("请输入n的值:");
    scanf("%d",&n);
  }
  while(n>12); //保证输入的值不大于12以保持屏幕效果
  for(i=0; i<=n; i++) /*控制输出n行*/
  {
    for(j=0; j<24-2*i; j++)
      printf(" ");/*控制输出第i行前面的空格*/
    for(j=1; j<i+2; j++)
      printf("%5d",c(i,j));/*输出第i行的第j个值*/
    printf("\n");
  }
  return 0;
}

