//全局变量与局部变量
#include <bits/stdc++.h>
using namespace std;

int num1=5;   //全局变量,赋值为5,下面的所有函数都可使用它
char c[10];   //全局数组,全部元素均自动赋值0,下面所有函数都可用它

void Fun1()
{
  int a=1;    //a为局部变量,只能在本函数中使用
  num1+=a;    //可以使用全局变量num1
}

int num2=4;   //全局变量,不能被上面的Fun1用，可被下面的Fun2和main用
void Fun2()
{
  num2++;
}

int a[10];    //全局数组,全部元素均自动赋值0,只能被后面的main函数用
int x;        //全局变量,系统自动赋值为0,只能被后面的main函数使用
int main()
{
  int y;                   //局部变量,值未知,只在main函数中有效
  Fun1();
  Fun2();
  printf("%d\n",num1+num2);//可使用全局变量num1和num2,输出值为11
  for(int i=0; i<=9; i++)
    printf("%d ",a[i]);    //全局数组未手工赋值，输出的值均为0
  printf("\n x=%d,y=%d\n");//全局变量x为0,局部变量y为未知的一个值
  for(int i=0; i<=9; i++)
    printf("%c ",c[i]);    //按%c格式输出为空,如按%d格式输出均为0
  printf("\n");
  int b[10];               //局部数组未手工赋值，输出值任意
  for(int i=0; i<=9; i++)
    printf("%d ",b[i]);    //输出的值未知
  return 0;
}

