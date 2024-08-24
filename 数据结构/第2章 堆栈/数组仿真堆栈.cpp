//简单数组模拟栈
#include<bits/stdc++.h>
#define MAXN 1000              //栈能容纳的最多元素个数
using namespace std;

int Stack[MAXN];               //不能写成stack，会有名称冲突
int Top = -1;                  //初始化栈顶指针为-1

int Pop()                      //栈顶元素出栈并获取出栈的元素值
{
  if(Top<0)
  {
    cout<<"\n栈为空!\n";
    return -1;
  }
  return Stack[Top--];
}

void Push(int value)           //入栈
{
  if(Top>=MAXN)
    cout<<"\n栈已满!\n";
  else
    Stack[++Top]=value;
}

void Display()                 //显示栈中元素
{
  for(int tmp = Top ; tmp >= 0 ; -- tmp)
    cout<<Stack[tmp]<<" ";
  cout<<"\n";
}

int main()
{
  int ins;
  while(1)
  {
    system("cls");              //清屏
    Display();
    cout<<"请输入元素值,(0=退出,-1=出栈)\n";
    cin>>ins;
    if(ins==0)
      exit(0);
    else if(ins!=-1)
      Push(ins);
    else if(ins==-1)
      Pop();
  }
  return 0;
}

