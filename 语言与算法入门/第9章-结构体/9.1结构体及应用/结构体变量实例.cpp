//�ṹ�����ʵ��
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
  struct student a= {10001,"����",'M',95};       //�����������ֵ
  struct student b= {10002,"С��",'F',92};       //���ܸı丳ֵ˳��
  struct student c;                              //�ṹ��cδ����ֵ
  scanf("%d%s%c%f",&c.ID,c.name,&c.sex,&c.score);//ע��c.nameǰ��"&"
  printf("%d %s %c %f\n",a.ID,a.name,a.sex,a.score);
  printf("%d %s %c %f\n",b.ID,b.name,b.sex,b.score);
  printf("%d %s %c %f\n",c.ID,c.name,c.sex,c.score);
  return 0;
}

