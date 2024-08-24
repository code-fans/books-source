//中序遍历 —结构数组法实现
#include <bits/stdc++.h>
using namespace std;
const int MAXN=32768;                  //2^15

int n;
struct tree
{
  int Left,Data,Right;
} tree[MAXN];

void Create(int *node,int len)
{
  for(int i=1; i<=len; i++)            //遍历各结点
  {
    tree[i].Data=node[i];              //元素值存入结点
    int pos=0,dir=0;
    while(dir==0)
    {
      if(node[i]<tree[pos].Data)       //判断是否为左子树
        if(tree[pos].Left!=-1)         //如果该位置已被占用,继续往下找
          pos=tree[pos].Left;
        else
          dir=1;                       //设为左树
      else                             //判断是否为右子树
        if(tree[pos].Right!=-1)
          pos=tree[pos].Right;
        else
          dir=-1;                      //设为右树
    }
    dir==1? tree[pos].Left=i:tree[pos].Right=i;
  }
}

void InOrder(int root)                //中序遍历
{
  if(root!=-1)
  {
    InOrder(tree[root].Left);
    cout<<tree[root].Data<<' ';
    InOrder(tree[root].Right);
  }
}

int main()
{
  freopen("inorder.in","r",stdin);
  freopen("inorder.out","w",stdout);
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)            //初始化
  {
    tree[i].Left=-1;
    tree[i].Data=0;
    tree[i].Right=-1;
  }
  Create(node,n);
  InOrder(1);
  return 0;
}

