//结构体变量实例
#include <bits/stdc++.h>
using namespace std;

struct student
{
  int ID;
  char name[20];
  char sex;
  float score;
};

int main()
{
  struct student a= {10001,"琪儿",'M',95};       //定义变量并赋值
  struct student b= {10002,"小光",'F',92};       //不能改变赋值顺序
  struct student c;                              //结构体c未赋初值
  scanf("%d%s%c%f",&c.ID,c.name,&c.sex,&c.score);//注意c.name前无"&"
  printf("%d %s %c %f\n",a.ID,a.name,a.sex,a.score);
  printf("%d %s %c %f\n",b.ID,b.name,b.sex,b.score);
  printf("%d %s %c %f\n",c.ID,c.name,c.sex,c.score);
  return 0;
}

