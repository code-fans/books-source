// 简单静态链表
#include <bits/stdc++.h>
using namespace std;

struct  student
{
  long num;                      //学号
  float score;                   //成绩
  struct student *next;          //该指针指向student类型的结构体
};                               //注意必须有分号

int main()
{
  struct student a,b,c;
  a.num=34341;                   //赋值
  a.score=81.5;
  b.num=34343;
  b.score=97;
  c.num=34344;
  c.score=82;
  struct student *head=&a;       //将a的地址给head
  a.next=&b;                     //将b的地址给a.next，即链接下一结构体元素
  b.next=&c;
  c.next=NULL;                   //指向空地址
  struct student *p=head;
  do                             //输出记录
  {
    cout<<p->num<<" "<<p->score<<endl;
    p=p->next;
  }
  while(p!=NULL);
  return 0;
}

