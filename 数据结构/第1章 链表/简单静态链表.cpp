// �򵥾�̬����
#include <bits/stdc++.h>
using namespace std;

struct  student
{
  long num;                      //ѧ��
  float score;                   //�ɼ�
  struct student *next;          //��ָ��ָ��student���͵Ľṹ��
};                               //ע������зֺ�

int main()
{
  struct student a,b,c;
  a.num=34341;                   //��ֵ
  a.score=81.5;
  b.num=34343;
  b.score=97;
  c.num=34344;
  c.score=82;
  struct student *head=&a;       //��a�ĵ�ַ��head
  a.next=&b;                     //��b�ĵ�ַ��a.next����������һ�ṹ��Ԫ��
  b.next=&c;
  c.next=NULL;                   //ָ��յ�ַ
  struct student *p=head;
  do                             //�����¼
  {
    cout<<p->num<<" "<<p->score<<endl;
    p=p->next;
  }
  while(p!=NULL);
  return 0;
}

