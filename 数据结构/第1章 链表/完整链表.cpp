// 完整链表
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

Link Insert(Link Head,int x,int i)            //插入元素x到i的位置
{
  Link NewPoint=new Lnode;                    //新建结点
  NewPoint->data=x;                           //结点赋值
  if(i==1)                                    //如果插入位置为第一个结点时
  {
    NewPoint->next=Head;
    Head=NewPoint;
  }
  else
  {
    int j=1;
    Link p=Head;
    while(j<i-1 && p->next!=NULL)             //向后找到合适的位置
    {
      p=p->next;
      j++;
    }
    if(j==i-1)
    {
      NewPoint->next=p->next;
      p->next=NewPoint;
    }
    else  printf("插入元素失败,输入的值错误!");
  }
  return Head;
}

Link Create(Link Head)
{
  int newData;
  while(1)
  {
    Link NewPoint=new Lnode;
    printf("请输入链表元素值: 结束则输入'-1'\n");
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
    printf("输入数据错误!");
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
    printf("\n链表为空\n");
  else
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
  printf("\n");
}

Link Del(Link Head,int i)              //删除i位置上的结点
{
  Link p=Head,t;
  if(i==1)                             //如果是第一个结点
  {
    Head=Head->next;
    delete(p);                         //删除Head结点
  }
  else
  {
    int j=1;
    while(j<i-1 && p->next !=NULL)     //找到删除的前一个位置
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
      delete(t);                       //释放该结点内存空间
  }
  return Head;
}

int main()
{
  Link head=NULL;
  printf("\n创建链表：\n");
  head=Create(head);
  Display(head);
  while(1)
  {
    system("cls");                //DOS下的清屏命令,比赛勿用
    printf("  链表为：");
    Display(head);
    printf("\n操作菜单：\n");
    printf("  1.输出链表长度\n");
    printf("  2.获取链表第n个元素值\n");
    printf("  3.查找链表中某个元素的位置\n");
    printf("  4.插入某元素到链表\n");
    printf("  5.删除链表中第n个元素\n");
    printf("  6.清空链表\n");
    int Choice,x,y;
    scanf("%d",&Choice);
    switch(Choice)
    {
      case 1:
        printf("链表长度为 %d\n",Lenth(head));
        break;
      case 2:
        printf("请输入要查找的元素值位置\n");
        scanf("%d",&x);
        printf("值为 %d\n",Get(head,x));
        break;
      case 3:
        printf("请输入要查找的元素值\n");
        scanf("%d",&x);
        printf("位置在 %d\n",Locate(head,x));
        break;
      case 4:
        printf("请输入要插入的值和位置\n");
        scanf("%d%d",&x,&y);
        head=Insert(head,x,y);
        break;
      case 5:
        printf("请输入要删除元素的位置\n");
        scanf("%d",&x);
        head=Del(head,x);
        break;
      case 6:
        head=SetNull(head);
    }
    Display(head);
    system("pause");              //暂停,此命令只能在windows平台上用,比赛勿用
  }
  return 0;
}

