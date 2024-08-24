// ��������
#include <bits/stdc++.h>
using namespace std;
typedef struct List *Link;
typedef struct List Lnode;

struct List
{
  int data;
  struct List *next;
};

Link SetNull(Link Head)
{
  Link p=Head;
  while(p!=NULL)
  {
    p=p->next;
    delete(Head);
    Head=p;
  }
  return Head;
}

Link Insert(Link Head,int x,int i)            //����Ԫ��x��i��λ��
{
  Link NewPoint=new Lnode;                    //�½����
  NewPoint->data=x;                           //��㸳ֵ
  if(i==1)                                    //�������λ��Ϊ��һ�����ʱ
  {
    NewPoint->next=Head;
    Head=NewPoint;
  }
  else
  {
    int j=1;
    Link p=Head;
    while(j<i-1 && p->next!=NULL)             //����ҵ����ʵ�λ��
    {
      p=p->next;
      j++;
    }
    if(j==i-1)
    {
      NewPoint->next=p->next;
      p->next=NewPoint;
    }
    else  printf("����Ԫ��ʧ��,�����ֵ����!");
  }
  return Head;
}

Link Create(Link Head)
{
  int newData;
  while(1)
  {
    Link NewPoint=new Lnode;
    printf("����������Ԫ��ֵ: ����������'-1'\n");
    scanf("%d",&newData);
    if (newData==-1)
      return Head;
    NewPoint->data=newData;
    if(Head==NULL)
      NewPoint->next=NULL;
    else
      NewPoint->next=Head;
    Head=NewPoint;
  }
}

int Lenth(Link Head)
{
  int len=0;
  Link p=Head;
  while(p!=NULL)
  {
    len++;
    p=p->next;
  }
  return len;
}

int Get(Link Head,int i)
{
  int j=1;
  Link p=Head;
  while(j<i && p!=NULL)
  {
    p=p->next;
    j++;
  }
  if(p!=NULL)
    return(p->data);
  else
    printf("�������ݴ���!");
  return -1;
}

int Locate(Link Head,int x)
{
  int n=0;
  Link p=Head;
  while(p!=NULL && p->data !=x)
  {
    p=p->next;
    n++;
  }
  return p==NULL?-1:n+1;
}

void Display(Link Head)
{
  Link p=Head;
  if(p==NULL)
    printf("\n����Ϊ��\n");
  else
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  printf("\n");
}

Link Del(Link Head,int i)              //ɾ��iλ���ϵĽ��
{
  Link p=Head,t;
  if(i==1)                             //����ǵ�һ�����
  {
    Head=Head->next;
    delete(p);                         //ɾ��Head���
  }
  else
  {
    int j=1;
    while(j<i-1 && p->next !=NULL)     //�ҵ�ɾ����ǰһ��λ��
    {
      p=p->next;
      j++;
    }
    if(p->next!=NULL && j==i-1)
    {
      t=p->next;
      p->next=t->next;
    }
    if(t!=NULL)
      delete(t);                       //�ͷŸý���ڴ�ռ�
  }
  return Head;
}

int main()
{
  Link head=NULL;
  printf("\n��������\n");
  head=Create(head);
  Display(head);
  while(1)
  {
    system("cls");                //DOS�µ���������,��������
    printf("  ����Ϊ��");
    Display(head);
    printf("\n�����˵���\n");
    printf("  1.���������\n");
    printf("  2.��ȡ�����n��Ԫ��ֵ\n");
    printf("  3.����������ĳ��Ԫ�ص�λ��\n");
    printf("  4.����ĳԪ�ص�����\n");
    printf("  5.ɾ�������е�n��Ԫ��\n");
    printf("  6.�������\n");
    int Choice,x,y;
    scanf("%d",&Choice);
    switch(Choice)
    {
      case 1:
        printf("������Ϊ %d\n",Lenth(head));
        break;
      case 2:
        printf("������Ҫ���ҵ�Ԫ��ֵλ��\n");
        scanf("%d",&x);
        printf("ֵΪ %d\n",Get(head,x));
        break;
      case 3:
        printf("������Ҫ���ҵ�Ԫ��ֵ\n");
        scanf("%d",&x);
        printf("λ���� %d\n",Locate(head,x));
        break;
      case 4:
        printf("������Ҫ�����ֵ��λ��\n");
        scanf("%d%d",&x,&y);
        head=Insert(head,x,y);
        break;
      case 5:
        printf("������Ҫɾ��Ԫ�ص�λ��\n");
        scanf("%d",&x);
        head=Del(head,x);
        break;
      case 6:
        head=SetNull(head);
    }
    Display(head);
    system("pause");              //��ͣ,������ֻ����windowsƽ̨����,��������
  }
  return 0;
}

