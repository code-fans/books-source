//快算24点-STL
#include <bits/stdc++.h>
using namespace std;

int a[5],i,j,k;                            //i,j,k为三个操作符
char opt[5]= {' ','+','-','*','/'};

int F(int x,int k, int y)                  //计算x opt[k] y
{
  if(k==1)
    return x+y;
  if(k==2)
    return max(x,y)-min(x,y);
  if(k==3)
    return x*y;
  return (y==0 || x<y || x%y!=0) ? -999999 : x/y;
}

void P(int a,int b,int c,int d,int e,int f)//输出结果
{
  printf("%d%c%d=%d\n",max(a,b),opt[i],min(a,b),F(max(a,b),i,min(a,b)));
  printf("%d%c%d=%d\n",max(c,d),opt[j],min(c,d),F(max(c,d),j,min(c,d)));
  printf("%d%c%d=%d\n",max(e,f),opt[k],min(e,f),F(max(e,f),k,min(e,f)));
  exit(0);                                 //直接退出程序
}

int main()
{
  scanf("%d%d%d%d", &a[1],&a[2],&a[3],&a[4]);
  sort(a+1,a+5);                           //排序保证遍历所有情况
  do
  {
    for (i = 1; i <= 4; i++)               //暴力枚举3个运算符
      for (j = 1; j <= 4; j++)
        for (k = 1; k <= 4; k++)
          if (F(F(F(a[1],i,a[2]),j,a[3]),k,a[4])==24)    //((a?b)?c)?d
            P(a[1],a[2],F(a[1],i,a[2]),a[3],F(F(a[1],i,a[2]),j,a[3]),a[4]);
          else if(F(F(a[1],i,a[2]),k,F(a[3],j,a[4]))==24)//(a?b)?(c?d)
            P(a[1],a[2],a[3],a[4],F(a[1],i,a[2]),F(a[3],j,a[4]));
  }
  while (next_permutation(a + 1, a + 5));
  puts("No\n");
  return 0;
}
