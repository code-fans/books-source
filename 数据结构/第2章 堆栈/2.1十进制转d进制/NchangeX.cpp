//十进制转d进制
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000                   //栈能容纳的最多元素个数

int Stack[MAXN];
int Top = -1;                       //初始化栈顶指针为-1
char c[36]= {'0','1','2','3','4','5','6','7','8','9','A','B',
             'C','D','E','F','G','H','I','J','K','L','M','N',
             'O','P','Q','R','S','T','U','V','W','X','Y','Z'
            };

int StackEmpty()                    //判断栈是否为空
{
  return Top<0 ? 1:0;
}

char Pop()                          //栈顶元素出栈并获取出栈的元素值
{
  int temp=Stack[Top--];
  return c[temp];
}

void Push(int value)                //入栈
{
  Stack[++Top]=value;
}

void Conversion(int N,int d)        //进制转换
{
  while(N)
  {
    Push(N%d);
    N/=d;
  }
  while(!StackEmpty())
    cout<<Pop();
}

int main()
{
  freopen("NchangeX.in","r",stdin);
  freopen("NchangeX.out","w",stdout);
  int number,d;
  cin>>number>>d;
  if(number==0)                     //注意特例0
    cout<<0<<endl;
  else
  {
    Conversion(number,d);
    cout<<endl;
  }
  return 0;
}

