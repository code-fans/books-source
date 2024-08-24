//结构体数组实例
#include <bits/stdc++.h>
using namespace std;

struct student
{
  int ID;
  char name[20];
  char sex;
  float score;
};

struct student s[3]= {{
    10001,"琪儿",'M',95
  },
  {10002,"小光",'F',92}
};                 //定义了结构体数组stu[3]并对前两个赋值

int main()
{
  scanf("%d %s %c %f",&s[2].ID,s[2].name,&s[2].sex,&s[2].score);
  for(int i=0; i<3; i++)
    printf("%d %s %c %f\n",s[i].ID,s[i].name,s[i].sex,s[i].score);
  return 0;
}

