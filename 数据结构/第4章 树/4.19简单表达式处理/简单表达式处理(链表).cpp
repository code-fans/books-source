//简单表达式处理
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
  if(i==j)                         //当只有一个数字时
  {
    p=new BTNode;
    p->data=s[i];
    p->lchild=NULL;
    p->rchild=NULL;
    return p;                      //建立结点后返回
  }
  for(k=i; k<=j; k++)
    if(s[k]=='+'||s[k]=='-')
    {
      plus++;
      posi=k;                     //确定运算符位置
    }
  if(plus==0)                      //如果没有+-,就查找*/
    for(k=i; k<=j; k++)
      if(s[k]=='*'||s[k]=='/')     //查找
      {
        plus++;
        posi=k;
      }
  if(plus!=0)
  {
    p=new BTNode;
    p->data=s[posi];
    p->lchild=CRTree(s,i,posi-1);   //递归
    p->rchild=CRTree(s,posi+1,j);   //递归
    return p;
  }
}

void DispPre(BTNode *T)             //打印前序表达式
{
  if(T!=NULL)
  {
    printf("%c ",T->data);
    DispPre(T->lchild);
    DispPre(T->rchild);
  }
}

void DispIn(BTNode *T)              //打印中序表达式
{
  if(T!=NULL)
  {
    DispIn(T->lchild);
    printf("%c ",T->data);
    DispIn(T->rchild);
  }
}

void DispPost(BTNode *T)            //打印后序表达式
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
  printf("\n前序表达式为:\n");
  DispPre(T);
  printf("\n中序表达式为:\n");
  DispIn(T);
  printf("\n后序表达式为:\n");
  DispPost(T);
  return 0;
}

