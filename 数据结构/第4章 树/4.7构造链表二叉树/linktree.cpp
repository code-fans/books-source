//构造链表二叉树
#include <bits/stdc++.h>
using namespace std;

struct tree
{
  struct tree *left;
  int data;
  struct tree *right;
};
typedef struct tree treenode;
typedef struct tree *b_tree;

b_tree Insert(b_tree root,int node)
{
  b_tree newnode=new treenode;            //开辟新结点
  newnode->data=node;                     //新结点赋值
  newnode->left=NULL;
  newnode->right=NULL;
  b_tree currentnode;
  b_tree parentnode;
  if(root==NULL)                          //第一个结点建立
    return newnode;
  else
  {
    currentnode=root;                     //从根结点开始
    while(currentnode!=NULL)              //当没有找到空位置时
    {
      parentnode=currentnode;             //将当前结点作为父结点
      if(currentnode->data>node)
        currentnode=currentnode->left;    //顺着左子树找下去
      else
        currentnode=currentnode->right;   //顺着右子树找下去
    }
    if(parentnode->data>node)
      parentnode->left=newnode;
    else
      parentnode->right=newnode;
  }
  return root;
}

b_tree Create(int *data,int len)          //建立二叉树
{
  b_tree root=NULL;
  for(int i=1; i<=len; i++)
    root=Insert(root,data[i]);
  return root;
}

void Print(b_tree root)                   //递归打印二叉树
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    Print(root->left);
    Print(root->right);
  }
}

int main()
{
  //freopen("linktree.in","r",stdin);
  //freopen("linktree.out","w",stdout);
  int n;
  b_tree root=NULL;
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  root=Create(node,n);
  Print(root);
  cout<<endl;
  return 0;
}
