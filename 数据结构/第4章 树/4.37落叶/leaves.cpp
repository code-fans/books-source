//落叶
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char str[100][100];

struct BST
{
  char val;
  int lson,rson;
} tree[100];
int tot,root;

int New(int val)                         //创建新结点
{
  tree[++tot].val=val;
  return tot;
}

void Insert(int &p,char val)
{
  if(p==0)
  {
    p=New(val);
    return;
  }
  if(val<tree[p].val)
    Insert(tree[p].lson,val);
  else
    Insert(tree[p].rson,val);
}

void Print(int k)                    //前序输出
{
  printf("%c",tree[k].val);
  if(tree[k].lson)
    Print(tree[k].lson);
  if(tree[k].rson)
    Print(tree[k].rson);
}

int main()
{
  while(scanf("%s",str[0]))
  {
    root=0;
    int cnt=0;
    while(str[cnt][0]<='Z' && str[cnt][0]>='A')
      scanf("%s",str[++cnt]);
    memset(tree,0,sizeof(tree));
    for(int i=cnt-1; i>=0; i--)
    {
      int len=strlen(str[i]);
      for(int j=0; j<len; j++)
        Insert(root,str[i][j]);
    }
    Print(root);
    puts("");
    if(str[cnt][0]=='$')
      break;
  }
  return 0;
}
