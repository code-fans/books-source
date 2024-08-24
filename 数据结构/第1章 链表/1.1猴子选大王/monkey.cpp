//密钥
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int ID;                           //编号
  struct Node *next;
};

int main()
{
  //freopen("monkey.in","r",stdin);
  //freopen("monkey.out","w",stdout);
  struct Node *head,*s,*q,*t;
  int n,m,count=0;
  scanf("%d%d",&n,&m);
  for (int i=1; i<=n; i++)
  {
    s=new Node;                    //创建结点s
    s->ID=i;
    s->next=NULL;
    if (i==1)                      //建立表头结点
      head=s,q=head;               //head作为表头结点,q总是指向链表的最后一个结点
    else                           //建立其它结点
    {
      q->next=s;
      q=q->next;
    }
  }
  q->next=head;                    //建立循环单链表

  q=head;                          //q先指向表头结点
  do
  {
    count++;                       //计数器增1
    if (count==m-1)                //跳到要删除结点的前驱处
    {
      t=q->next;                   //t指向要删除的结点
      q->next=t->next;             //链接跳过要删除的结点
      delete(t);                   //释放删除结点的内存空间
      count=0;                     //计数器重置0
    }
    q=q->next;
  }
  while (q->next!=q);              //循环直到只剩一个结点
  printf("%d\n",q->ID);            //输出最后的一个结点值
  delete(q);
  return 0;
}

