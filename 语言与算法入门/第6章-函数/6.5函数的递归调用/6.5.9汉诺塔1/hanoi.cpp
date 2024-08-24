//汉诺塔
#include <bits/stdc++.h>
using namespace std;

void Move(int n,char A,char B,char C)//将n个金片从A针借助B针移到C针
{
  if(n==1)                        //当盘片只剩1个时
    printf("%c->%c ",A,C);        //移动金片从A到C
  else
  {
    Move(n-1,A,C,B);                 //递归调用,金片数-1,三个针换位置
    printf("%c->%c ",A,C);        //移动金片从A到C
    Move(n-1,B,A,C);                 //递归调用,金片数-1,三个针换位置
  }
}

int main()
{
  int m;                          //金片数
  scanf("%d",&m);                 //输入金片数
  Move(m,'A','B','C');
  return 0;
}

