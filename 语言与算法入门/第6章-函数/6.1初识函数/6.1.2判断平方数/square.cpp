//判断平方数
#include <bits/stdc++.h>
using namespace std;

void Square(int x);      //对子函数的声明

int main()
{
  freopen("square.in","r",stdin);
  freopen("square.out","w",stdout);
  int x;
  while(cin>>x)
    Square(x);
  return 0;
}

void Square(int n)       //void表示函数无返回值
{
  for(int i=1; n>0; i+=2)//由1+1，1+3，1+3+5...为平方数推导而来
    n-=i;
  cout<<(n==0?1:0)<<endl;//直接输出结果，所以无return值
}
