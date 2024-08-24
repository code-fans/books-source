//后序表达式
#include <bits/stdc++.h>
using namespace std;

char Exp[100];                            //存储后缀表达式,注意不能写成exp
char Stack[100];                          //作为栈使用,注意不能写成stack
int t,top;                                //t为Exp的下标,top为Stack的下标

void PutExp()                             //输出表达式
{
  for (int j=1; j<t; j++)
    printf("%c",Exp[j]=='#' ? ' ':Exp[j]);
  cout<<endl;
}

void Trans()                                   //转换成后缀表达式
{
  char ch;
  do
  {
    scanf("%c",&ch);
    if(ch>='0' && ch<='9')                     //读入一个完整的数
    {
      while(ch>='0' && ch<='9')
        Exp[++t]=ch,scanf("%c",&ch);
      Exp[++t]='#';
    }
    switch(ch)
    {
      case '(':
        Stack[++top]=ch;                //左括号则插入堆栈
        break;
      case ')':
        while(Stack[top]!='(')          //右括号
          Exp[++t]=Stack[top],top--;     //出栈到Exp直到左括号
        top--;                          //删除堆栈里的左括号
        break;
      case '+':                                //如果是加号和减号
      case '-':
        while (top!=0 && Stack[top]!='(')//直到遇到左括号
          Exp[++t]=Stack[top],top--;    //出栈到后序表达式
        Stack[++top]=ch;                //堆栈中插入'+'或'-'
        break;
      case '*':                                //如果是乘号和除号
      case '/':
        while (Stack[top]=='*' || Stack[top]=='/')
          Exp[++t]=Stack[top],top--;    //出栈全部'*'或'/'
        Stack[++top]=ch;                //栈中插入乘号或除号
        break;
    }
  }
  while(ch!='#');
  while (top!=0)                               //全部栈元素放到后序表达式
    Exp[++t]=Stack[top],top--;
  Exp[++t]='#';
}

double Compvalue()                             //计算后缀表达式的值
{
  double stk[100];                             //作为数字栈使用
  t=1,top=0;                               //t为Exp下标,top为stk下标
  char ch=Exp[t++];
  while (ch!='#')
  {
    switch (ch)
    {
      case '+':
        stk[top-1]=stk[top-1]+stk[top];
        top--;
        break;
      case '-':
        stk[top-1]=stk[top-1]-stk[top];
        top--;
        break;
      case '*':
        stk[top-1]=stk[top-1]*stk[top];
        top--;
        break;
      case '/':
        if (stk[top]!=0)
          stk[top-1]=stk[top-1]/stk[top];
        else
          printf("-1\n"),exit(0);       //异常退出
        top--;
        break;
      default:
        int d=0;
        while (ch>='0' && ch<='9')      //判定为数字字符
        {
          d=10*d+ch-'0';                //将数字字符转换成对应数值
          ch=Exp[t++];
        }
        stk[++top]=d;
    }
    ch=Exp[t++];
  }
  return stk[top];
}

int main()
{
  //freopen("ReversePolish.in","r",stdin);
  //freopen("ReversePolish.out","w",stdout);

  Trans();                                     //转成后缀表达式
  //PutExp();                                  //输出后序表达式
  printf("%0.2f\n",Compvalue());               //输出计算结果
  return 0;
}

