//��Կ
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int ID;                           //���
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
    s=new Node;                    //�������s
    s->ID=i;
    s->next=NULL;
    if (i==1)                      //������ͷ���
      head=s,q=head;               //head��Ϊ��ͷ���,q����ָ����������һ�����
    else                           //�����������
    {
      q->next=s;
      q=q->next;
    }
  }
  q->next=head;                    //����ѭ��������

  q=head;                          //q��ָ���ͷ���
  do
  {
    count++;                       //��������1
    if (count==m-1)                //����Ҫɾ������ǰ����
    {
      t=q->next;                   //tָ��Ҫɾ���Ľ��
      q->next=t->next;             //��������Ҫɾ���Ľ��
      delete(t);                   //�ͷ�ɾ�������ڴ�ռ�
      count=0;                     //����������0
    }
    q=q->next;
  }
  while (q->next!=q);              //ѭ��ֱ��ֻʣһ�����
  printf("%d\n",q->ID);            //�������һ�����ֵ
  delete(q);
  return 0;
}

