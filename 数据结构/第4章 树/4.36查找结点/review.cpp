//二叉树二分查找法
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;

struct BST
{
  int val,lson,rson;
} Tree[100];
int tot,root,n,locate;

int New(int val)                         //创建新结点
{
  Tree[++tot].val=val;
  return tot;
}

void Build()                             //建树
{
  New(-INF);
  New(INF);
  root=1;
  Tree[1].rson=2;
}

void Insert(int &p,int val)               //插入结点val
{
  if(p==0)
  {
    p=New(val);
    return;
  }
  if(val<Tree[p].val)
    Insert(Tree[p].lson,val);
  else
    Insert(Tree[p].rson,val);
}

int Search(int p,int val)                  //查找元素val
{
  if(p==0)
    return -1;
  if(val==Tree[p].val)
    return Tree[p].val;
  return val<Tree[p].val ? Search(Tree[p].lson,val) : Search(Tree[p].rson,val);
}


int GetPre(int &root,int val,int &fa,int &firstfa)
{
  while(root)
  {
    if(Tree[root].val==val)
      return root;

    fa = root;
    if(Tree[root].val>val)
      root=Tree[root].lson;
    else
    {
      firstfa = root;//出现右拐点
      root=Tree[root].rson;
    }
  }
  return 0;
}

int GetNext(int val)                    //查找后继
{
  int ans=2;                            //包括有INF的结点
  int p=root;
  while(p)
  {
    if(val==Tree[p].val)                  //搜索val成功
    {
      if(Tree[p].rson>0)                     //如果有右子树
      {
        p=Tree[p].rson;
        while(Tree[p].lson>0)                //一直往左子树走
          p=Tree[p].lson;
        ans=p;
      }
      break;
    }
    if(Tree[p].val>val && Tree[p].val<Tree[ans].val)//尝试更新后继
      ans=p;
    p=val<Tree[p].val ? Tree[p].lson : Tree[p].rson;//向下搜索
  }
  return ans;
}

void Delete(int val)                            //删除val
{
  int &p=root;   //p为引用
  while(p)
  {
    if(val==Tree[p].val)
      break;
    p=val<Tree[p].val ?Tree[p].lson:Tree[p].rson;//向下查找
  }
  if(p==0)
    return;
  if(Tree[p].lson==0)//如果没有左子树
    p=Tree[p].rson;//右子树代替p的位置
  else if(Tree[p].rson==0)//如果没有右子树
    p=Tree[p].lson;//左子树代替p的位置
  else         //左/右子树均有
  {
    int next=Tree[p].rson;//求后继
    while(Tree[next].lson>0)
      next=Tree[next].lson;
    Delete(Tree[next].val);//后继没有左子树，直接删除
    Tree[next].lson=Tree[p].lson;//next代替p的位置
    Tree[next].rson=Tree[p].rson;
    p=next;
  }
}

int main()
{
//  //freopen("review.in","r",stdin);
//  //freopen("review.out","w",stdout);
  Build();
  scanf("%d",&n);
  for(int i=0,x; i<n; i++)
  {
    scanf("%d",&x);
    Insert(root,x);
  }
  while(1)
  {
    scanf("%d",&locate);
    cout<<GetPre(root,locate,root,root)<<endl;
  }
  scanf("%d",&locate);
  printf("%d\n",Search(root,locate));
  return 0;
}

