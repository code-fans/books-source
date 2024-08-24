// ѧ���ɼ�����ϵͳ
#include <bits/stdc++.h>
using namespace std;
typedef struct List *Link;
typedef struct List Lnode;

struct List
{
  int ID;
  char Name[10];
  double Chinese,Math,English;
  struct List *next;
};

void Change(Link Head,int ID)
{
  Link p=Head;
  if(Head==NULL)
    printf("\n�б�Ϊ��\n");
  else
  {
    while(p!= NULL && p->ID != ID  )
      p=p->next;
    if(p!=NULL)
    {
      printf("�����޸ĺ�����ġ���ѧ��Ӣ��ɼ�\n");
      scanf("%lf%lf%lf",&p->Chinese,&p->Math,&p->English);
    }
    else
      printf("�Ҳ�����ѧ��������\n");
  }
}

Link Del(Link Head,int ID)
{
  Link p=Head,first=Head;
  if(Head==NULL)
    printf("\n�޷�ɾ�����б�Ϊ��\n");
  else
  {
    while(p!= NULL && p->ID != ID  )
    {
      first=p;                          //first:ɾ������ǰ�����
      p=p->next;
    }
    if(p!=NULL)
    {
      if(p==Head)                     //ɾ�������һ��
        Head=Head->next;
      else
        first->next=p->next;
      delete(p);
    }
    else
      printf("�Ҳ�����ѧ��������\n");
  }
  return Head;
}

void Display(Link Head)
{
  Link p=Head;
  printf("\n%5s  %15s %6s %6s %6s\n","����","����","����","��ѧ","Ӣ��");
  while(p!=NULL)
  {
    printf("%5d %15s %6.2f %6.2f %6.2f\n",p->ID,p->Name,p->Chinese,p->Math,p->English);
    p=p->next;
  }
  printf("\n");
}

Link Create(Link Head)
{
  Link St=new Lnode;
  printf("������ѧ������ ���� ���� ��ѧ Ӣ��ɼ�: \n");
  scanf("%d %s %lf %lf %lf",&St->ID,&St->Name,&St->Chinese,&St->Math,&St->English);
  if(Head==NULL)
    St->next=NULL;
  else
    St->next=Head;
  return St;
}

Link Setnull(Link Head)
{
  Link p=Head;
  while(p!=NULL)                //��������ͷ�
  {
    p=p->next;
    delete(Head);
    Head=p;
  }
  return Head;
}

int main()
{
  Link head=NULL;
  while(1)
  {
    system("cls");                //DOS�µ���������
    printf("\n�����˵���\n");
    printf("  1.���ѧ�����ɼ�\n");
    printf("  2.������ɾ����¼\n");
    printf("  3.�������޸ļ�¼\n");
    printf("  4.���ȫ���ļ�¼\n");
    int Choice,x;
    scanf("%d",&Choice);
    switch(Choice)
    {
      case 1:
        head=Create(head);
        break;
      case 2:
        printf("������Ҫɾ����ѧ������\n");
        scanf("%d",&x);
        head=Del(head,x);
        break;
      case 3:
        printf("������Ҫ�޸ĵ�ѧ������\n");
        scanf("%d",&x);
        Change(head,x);
        break;
      case 4:
        head=Setnull(head);
    }
    Display(head);
    system("pause");              //��ͣ����,������ֻ����windowsƽ̨����
  }
  return 0;
}

