//N皇后 - 递归算法1
#include <bits/stdc++.h>
using namespace std;

int n,board[21];

void Print()                //打印棋子布局
{
  for(int i=1; i<=n; i++)
    printf("%d",board[i]);
  puts("");
}

void PrintGraph()           //图形化打印布局,用于调试
{
  for(int i=1; i<=n; ++i)
  {
    for(int j=1; j<=n; ++j)
      if(board[i]==j)
        printf("◎");       //特殊符号可在word软件里的插入符号中寻找
      else
        printf("□");
    puts("");
  }
  puts("");
}

int Try(int x,int y)        //测试x行y列可否摆放棋子,成功返回1，否则返回0
{
  for(int j=1; j<x; j++)    //与数组中已放好的数比较
    if((board[j]==y)||(abs(x-j)==abs(board[j]-y)))
      return 0;
  return 1;
}

void Place(int x)           //递归函数
{
  if(x>n)                   //棋子第n行已摆好，则打印成功方案
  {
    Print();
    //PrintGraph();         //若使用该语句，可图形化打印布局
  }
  else
    for(int y=1; y<=n; ++y) //该行棋子依次从左向右移
      if(Try(x,y))          //如果可以摆放
      {
        board[x]=y;         //给a[x]赋值
        Place(x+1);         //继续下一行的递归
      }
}

int main()
{
  scanf("%d",&n);
  Place(1);                 //从第1行开始递归
  return 0;
}

