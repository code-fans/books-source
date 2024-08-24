//拆分自然数 - 递归算法
#include <bits/stdc++.h>
using namespace std;

int Num[100],Count;

void Print(int k)                 //打印k个数
{
  printf("%d=%d",Num[0],Num[1]);
  for(int i=2; i<=k; i++)
    printf("+%d",Num[i]);
  printf("\n");
  ++Count;
}

void split(int k,int n)           //k为指向的位数,n为待划分的数
{
  if(n<=0)                        //如无法再拆分，则打印
    Print(k);
  else
    for(int i=Num[k]; i<=n; ++i)
      if(i>=Num[k])               //如果拆分的数大于等于前一个数
      {
        Num[k+1]=i;               //则成功拆分
        split(k+1,n-Num[k+1]);    //并进入下一个数的递归
      }
}

int main()
{
  //freopen("Distribution.in","r",stdin);
  //freopen("Distribution.out","w",stdout);
  scanf("%d",&Num[0]);            //例如输入7
  for(int i=1; i<=Num[0]/2; ++i)  //先拆分成两位加数
  {
    Num[1]=i;                     //例如Num[0]为7时，第一位数即Num[1]只可能是1,2,3
    split(1,Num[0]-Num[1]);       //递归继续拆分
  }
  printf("%d\n",Count);
  return 0;
}

