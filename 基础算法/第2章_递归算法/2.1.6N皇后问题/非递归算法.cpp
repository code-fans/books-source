//N皇后问题的非递归算法
#include <bits/stdc++.h>
using namespace std;

int board[21];                       //存放皇后位置,数组从1开始

int Try(int k)                       //判断该位置是否可安置皇后
{
  for(int i=1; i<=k-1; i++)
    if((board[i]==board[k])||(abs(board[i]-board[k])==abs(i-k)))
      return 0;
  return 1;
}

int main()
{
  //freopen("queen.in","r",stdin);
  //freopen("queen.out","w",stdout);
  int n,Count=0;
  cin>>n;
  for(int k=1; k>0;)
  {
    board[k]++;                      //棋子放的位置向右移一位
    while((board[k]<=n) && (!Try(k)))//直到试到一个合适的位置
      board[k]++;
    if(board[k]>n)                   //如果越界
      k--;                           //回溯到上一行
    else if(k==n)                    //如果安置好最后一行皇后
      Count++;
    else
      board[++k]=0;                  //继续安置下一行皇后(初始为0）
  }
  cout<<Count<<endl;
  return 0;
}

