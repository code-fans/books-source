//�������������
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
  b_tree newnode=new treenode;            //�����½��
  newnode->data=node;                     //�½�㸳ֵ
  newnode->left=NULL;
  newnode->right=NULL;
  b_tree currentnode;
  b_tree parentnode;
  if(root==NULL)                          //��һ����㽨��
    return newnode;
  else
  {
    currentnode=root;                     //�Ӹ���㿪ʼ
    while(currentnode!=NULL)              //��û���ҵ���λ��ʱ
    {
      parentnode=currentnode;             //����ǰ�����Ϊ�����
      if(currentnode->data>node)
        currentnode=currentnode->left;    //˳������������ȥ
      else
        currentnode=currentnode->right;   //˳������������ȥ
    }
    if(parentnode->data>node)
      parentnode->left=newnode;
    else
      parentnode->right=newnode;
  }
  return root;
}

b_tree Create(int *data,int len)          //����������
{
  b_tree root=NULL;
  for(int i=1; i<=len; i++)
    root=Insert(root,data[i]);
  return root;
}

void Print(b_tree root)                   //�ݹ��ӡ������
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
