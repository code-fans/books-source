//后序表达式
#include <bits/stdc++.h>
using namespace std;

string Exp[100];                               //存后序表达式,不能写成exp
int t,top;                                     //t为Exp的下标

void PutExp()                                  //输出表达式
{
  for(int j=1; j<=t; j++)
    cout<<Exp[j]<<" ";
  cout<<endl;
}

void Trans()                                   //转换成后缀表达式
{
  char Stack[100];                             //作为栈使用,不能写成stack
  string ch;
  cin>>ch;
  for(int i=0; i<ch.size(); i++)
    if(ch[i]>='0' && ch[i]<='9')               //保存完整的数字字符串
    {
      Exp[++t]=ch[i];
      while(i+1<ch.size() && ch[i+1]>='0' && ch[i+1]<='9')//如果为多位数
        Exp[t]+=ch[++i];                       //多位数保存在一个string中
    }
    else if(ch[i]=='(')
      Stack[++top]=ch[i];                      //左括号则插入堆栈
    else if(ch[i]==')')
    {
      for(; Stack[top]!='('; top--)            //右括号
        Exp[++t]=Stack[top];                   //出栈到Exp直到左括号
      top--;                                   //删除堆栈里的左括号
    }
    else if(ch[i]=='+' || ch[i]=='-')          //如果是加号和减号
    {
      for(; top!=0 && Stack[top]!='('; top--)  //直到遇到左括号
        Exp[++t]=Stack[top];                   //出栈到后序表达式
      Stack[++top]=ch[i];                      //堆栈中插入'+'或'-'
    }
    else if(ch[i]=='*' || ch[i]=='/')          //如果是乘号和除号
    {
      for(; Stack[top]=='*' || Stack[top]=='/'; top--)
        Exp[++t]=Stack[top];                   //出栈全部'*'或'/'
      Stack[++top]=ch[i];                      //栈中插入乘号或除号
    }
  for(; top!=0; top--)                         //全部栈元素放到后序表达式
    Exp[++t]=Stack[top];
}

double Compvalue()                             //计算后缀表达式的值
{
  double stk[100];                             //作为数字栈使用
  top=0;                                       //top为stk下标
  for(int i=1; i<=t; i++)
  {
    if(Exp[i]!="+" && Exp[i]!="-" && Exp[i]!="*" && Exp[i]!="/" )
    {
      double d=0;
      for(int j=0; j<Exp[i].size(); j++)       //将数字字符串转为数字
        d=10*d+(Exp[i][j]-'0');
      stk[++top]=d;
    }
    else
    {
      if(Exp[i]=="+")
        stk[top-1]=stk[top-1]+stk[top];
      else if(Exp[i]=="-")
        stk[top-1]=stk[top-1]-stk[top];
      else if(Exp[i]=="*")
        stk[top-1]=stk[top-1]*stk[top];
      else if(Exp[i]=="/")
        stk[top-1]=stk[top-1]/stk[top];
      top--;
    }
  }
  return stk[top];
}

int main()
{
  //freopen("ReversePolish.in","r",stdin);
  //freopen("ReversePolish.out","w",stdout);
  Trans();                                     //转成后缀表达式
  //PutExp();                                  //输出后序表达式的测试
  printf("%0.2f\n",Compvalue());               //输出计算结果
  return 0;
}

