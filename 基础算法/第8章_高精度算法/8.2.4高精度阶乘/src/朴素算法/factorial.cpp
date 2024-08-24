//朴素算法求高精度阶乘
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("factorial.in","r",stdin);
  freopen("factorial.out","w",stdout);
  int data[50001]= {0,1};
  int n,digit=1;                             //位数
  scanf("%d",&n);
  for(int i=1; i<n+1; i++)
  {
    for(int j=1; j<digit+1; j++)             //阶乘运算
      data[j]*=i;
    for(int j=1; j<digit+1; j++)
      if(data[j]>=10)                        //当某位数>=10时，需整理数据
        for(int r=1; r<digit+1; r++)
        {
          if(data[digit]>=10)                //位数增加1
            digit++;
          data[r+1]+=data[r]/10;
          data[r]=data[r]%10;
        }
  }
  printf("%d!=",n);                          //打印结果
  for(int k=digit; k>0; k--)
    printf("%d",data[k]);
  printf("\n");
  return 0;
}

