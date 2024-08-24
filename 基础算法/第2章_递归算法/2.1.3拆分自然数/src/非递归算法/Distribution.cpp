//自然数拆分 - 非递归算法
#include <bits/stdc++.h>
using namespace std;

int Num[100];
int n,sum,Count;

void Print(int k)
{
  printf("%d=%d",n,Num[1]);
  for(int i=2; i<=k; i++)
    printf("+%d",Num[i]);
  printf("\n");
  ++Count;
}

int main()
{
  freopen("Distribution.in","r",stdin);
  freopen("Distribution.out","w",stdout);
  scanf("%d",&n);
  Num[1]=1;
  for(int p=1; p>=1;)          //p为堆栈的指针
    if(sum+Num[p]<n)
    {
      sum+=Num[p];
      p++;                     //指向下一个数的位置
      Num[p]=Num[p-1];         //后面的数至少不小于前面的数
    }
    else                       //加起来的和大于等于n的情况
    {
      if(sum+Num[p]==n && p!=1)//p!=1防止出现n=n的输出
        Print(p);              //找到一组解，输出
      p--;                     //返回上一个数的位置
      sum-=Num[p];
      Num[p]++;                //上一个数加1，继续寻找下一组解
    }
  printf("%d\n",Count);
  return 0;
}
