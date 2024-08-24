//被限制的加法
#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,n9,sum;               //n9表示之前积累的9的个数，初始为0

int main()
{
  freopen("add3.in","r",stdin);
  freopen("add3.out","w",stdout);

  scanf("%d",&n);
  bool first=1;
  for(int i=1; i<=n; i++)         //从高位开始，依次处理每一位
  {
    scanf("%d%d",&a,&b);
    sum=a+b;
    if(sum<9)                     //无进位情况
    {
      if(c>0||first==0)           //避免前导0
        printf("%d",c);
      for(int j=1; j<=n9; j++)    //因为该位无进位，则可将之前积累的999..99输出
        printf("9");
      first=0;
      n9=0;                       //积累的999...999已输出，因此设为0
      c=sum;
    }
    else if(sum==9)               //为9时，只要记录9的个数
      n9++;
    else                          //大于9，即产生进位情况
    {
      printf("%d",++c);           //进位后输出
      for(int j=1; j<=n9; j++)    //因为进位,将前面积累的999..99以000...000输出
        printf("0");
      first=0;
      n9=0;
      c=sum-10;                   //c记录该位数进位后余下的数
    }
  }

  printf("%d",c);                 //处理剩下的一段999...999
  for(int j=1; j<=n9; j++)
    printf("9");
  printf("\n");
  return 0;
}

