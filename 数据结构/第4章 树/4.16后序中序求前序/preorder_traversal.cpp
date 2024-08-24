//前序遍历
#include <bits/stdc++.h>
using namespace std;

struct tree
{
  struct tree *left;
  int date;
  struct tree *right;
};
typedef struct tree treenode;
typedef struct tree *b_tree;

b_tree insert(b_tree root,int node)           //插入结点
{
  b_tree newnode;
  b_tree currentnode;
  b_tree parentnode;

  newnode=new treenode;
  newnode->date=node;
  newnode->left=NULL;
  newnode->right=NULL;

  if(root==NULL)                              //第一个结点建立
    return newnode;
  else
  {
    currentnode=root;                         //存储当前结点
    while(currentnode!=NULL)
    {
      parentnode=currentnode;                 //存储父结点
      if(currentnode->date>node)
        currentnode=currentnode->left;        //左子树
      else
        currentnode=currentnode->right;       //右子树
    }
    if(parentnode->date>node)
      parentnode->left=newnode;
    else
      parentnode->right=newnode;
  }
  return root;
}

b_tree create(int *data,int len)              //建立二叉树
{
  b_tree root=NULL;
  for(int i=1; i<=len; i++)
    root=insert(root,data[i]);
  return root;
}
char trans(int x)
{
  return char('A'+x-1);
}

void print(b_tree root)                       //前序遍历
{
  if(root!=NULL)
  {
    cout<<trans(root->date);
    print(root->left);
    print(root->right);
  }
}
void print2(b_tree root)                       //前序遍历
{
  if(root!=NULL)
  {
    print(root->left);
    cout<<trans(root->date);
    print(root->right);
  }
}


int main()
{

  freopen("preorder_traversal4.in","r",stdin);
  freopen("tree4.in","w",stdout);
  int n;
  b_tree root=NULL;
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  root=create(node,n);
  print(root);
  cout<<endl;
  print2(root);
  cout<<endl;
  return 0;
}

