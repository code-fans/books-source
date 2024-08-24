//�򵥱��ʽ����
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
  char data;
  struct node *lchild;
  struct node *rchild;
} BTNode;

BTNode *CRTree(char s[],int i,int j)
{
  int k,posi,plus=0;
  BTNode *p;
  if(i==j)                         //��ֻ��һ������ʱ
  {
    p=new BTNode;
    p->data=s[i];
    p->lchild=NULL;
    p->rchild=NULL;
    return p;                      //�������󷵻�
  }
  for(k=i; k<=j; k++)
    if(s[k]=='+'||s[k]=='-')
    {
      plus++;
      posi=k;                     //ȷ�������λ��
    }
  if(plus==0)                      //���û��+-,�Ͳ���*/
    for(k=i; k<=j; k++)
      if(s[k]=='*'||s[k]=='/')     //����
      {
        plus++;
        posi=k;
      }
  if(plus!=0)
  {
    p=new BTNode;
    p->data=s[posi];
    p->lchild=CRTree(s,i,posi-1);   //�ݹ�
    p->rchild=CRTree(s,posi+1,j);   //�ݹ�
    return p;
  }
}

void DispPre(BTNode *T)             //��ӡǰ����ʽ
{
  if(T!=NULL)
  {
    printf("%c ",T->data);
    DispPre(T->lchild);
    DispPre(T->rchild);
  }
}

void DispIn(BTNode *T)              //��ӡ������ʽ
{
  if(T!=NULL)
  {
    DispIn(T->lchild);
    printf("%c ",T->data);
    DispIn(T->rchild);
  }
}

void DispPost(BTNode *T)            //��ӡ������ʽ
{
  if(T!=NULL)
  {
    DispPost(T->lchild);
    DispPost(T->rchild);
    printf("%c ",T->data);
  }
}

int main()
{
  char s[20];
  BTNode *T;
  gets(s);
  T=CRTree(s,0,strlen(s)-1);
  printf("\nǰ����ʽΪ:\n");
  DispPre(T);
  printf("\n������ʽΪ:\n");
  DispIn(T);
  printf("\n������ʽΪ:\n");
  DispPost(T);
  return 0;
}

