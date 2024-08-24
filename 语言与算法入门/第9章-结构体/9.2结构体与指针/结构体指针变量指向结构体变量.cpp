//结构体指针变量指向结构体变量
#include <bits/stdc++.h>
using namespace std;

struct student
{
  int num;
  char name[20],sex;
  float score;
};

int main()
{
  struct student stu;   //定义结构体变量stu
  struct student *p;    //*p必须和stu一样，均为struct student类型
  p=&stu;               //结构体指针p指向结构体stu
  stu.num=10001;
  strcpy(stu.name,"Neo");//无法用"="对字符数组赋值，故用strcpy()
  stu.sex='M';
  stu.score=90.5;
  cout<<stu.num<<stu.name<<stu.sex<<stu.score<<endl;
  cout<<(*p).num<<(*p).name<<(*p).sex<<(*p).score<<endl;
  return 0;
}

