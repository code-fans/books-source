// 学生成绩管理系统
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
    printf("\n列表为空\n");
  else
  {
    while(p!= NULL && p->ID != ID  )
      p=p->next;
    if(p!=NULL)
    {
      printf("输入修改后的语文、数学、英语成绩\n");
      scanf("%lf%lf%lf",&p->Chinese,&p->Math,&p->English);
    }
    else
      printf("找不到该学生的座号\n");
  }
}

Link Del(Link Head,int ID)
{
  Link p=Head,first=Head;
  if(Head==NULL)
    printf("\n无法删除，列表为空\n");
  else
  {
    while(p!= NULL && p->ID != ID  )
    {
      first=p;                          //first:删除结点的前驱结点
      p=p->next;
    }
    if(p!=NULL)
    {
      if(p==Head)                     //删除链表第一个
        Head=Head->next;
      else
        first->next=p->next;
      delete(p);
    }
    else
      printf("找不到该学生的座号\n");
  }
  return Head;
}

void Display(Link Head)
{
  Link p=Head;
  printf("\n%5s  %15s %6s %6s %6s\n","座号","姓名","语文","数学","英语");
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
  printf("请输入学生座号 姓名 语文 数学 英语成绩: \n");
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
  while(p!=NULL)                //逐个结点的释放
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
    system("cls");                //DOS下的清屏命令
    printf("\n操作菜单：\n");
    printf("  1.添加学生及成绩\n");
    printf("  2.按座号删除记录\n");
    printf("  3.按座号修改记录\n");
    printf("  4.清空全部的记录\n");
    int Choice,x;
    scanf("%d",&Choice);
    switch(Choice)
    {
      case 1:
        head=Create(head);
        break;
      case 2:
        printf("请输入要删除的学生座号\n");
        scanf("%d",&x);
        head=Del(head,x);
        break;
      case 3:
        printf("请输入要修改的学生座号\n");
        scanf("%d",&x);
        Change(head,x);
        break;
      case 4:
        head=Setnull(head);
    }
    Display(head);
    system("pause");              //暂停命令,此命令只能在windows平台上用
  }
  return 0;
}

