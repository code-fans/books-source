//�ṹ��ָ�����ָ��ṹ�����
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
  struct student stu;   //����ṹ�����stu
  struct student *p;    //*p�����stuһ������Ϊstruct student����
  p=&stu;               //�ṹ��ָ��pָ��ṹ��stu
  stu.num=10001;
  strcpy(stu.name,"Neo");//�޷���"="���ַ����鸳ֵ������strcpy()
  stu.sex='M';
  stu.score=90.5;
  cout<<stu.num<<stu.name<<stu.sex<<stu.score<<endl;
  cout<<(*p).num<<(*p).name<<(*p).sex<<(*p).score<<endl;
  return 0;
}

