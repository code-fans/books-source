//二叉树二分查找法
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10000;
int node[MAXN+1];
int n,locate;

struct tree
{
  struct tree *left;
  int date;
  struct tree *right;
};
typedef struct tree treenode;
typedef struct tree *b_tree;

b_tree create(int *node,int position)             //递归建立二叉树
{
  b_tree newnode;
  if(node[position]==0 || position>n)
    return NULL;
  else
  {
    newnode=new treenode;
    newnode->date=node[position];
    newnode->left=create(node,2*position);
    newnode->right=create(node,2*position+1);
    return newnode;
  }
}

b_tree search(b_tree point,int locate)          //二分查找
{
  while(point!=NULL)
    if(point->date==locate)                     //如找到,则返回地址
      return point;
    else if(point->date>locate)
      point=point->left;                        //往左子树找
    else
      point=point->right;                       //往右子树找
  return NULL;                                  //未找到结点,则返回NULL
}

int main()
{
  //freopen("review.in","r",stdin);
  //freopen("review.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&node[i]);
  b_tree root=create(node,1);
  scanf("%d",&locate);
  b_tree point=NULL;
  point=search(root,locate);                    //调用二分查找函数
  point!=NULL?printf("%d\n",point->date):printf("-1\n");
  return 0;
}

