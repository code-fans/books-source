//二叉树结构数组表示法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 32768                      //2^15
int n;
struct tree
{
  int Left;
  int Date;
  int Right;
} b_tree[MAXN];

void create(int *node,int len)
{
  int level;
  int position;                        //左树-1,右树1
  for(int i=1; i<=len; i++)            //依次建立其它结点
  {
    b_tree[i].Date=node[i];            //元素值存入结点
    level=0;                           //树根为0
    position=0;
    while(position==0)
    {
      if(node[i]>b_tree[level].Date)   //判断是否为右子树
        if(b_tree[level].Right!=-1)    //如果该位置已被占用,继续往下找
          level=b_tree[level].Right;
        else
          position=-1;                 //设为右树
      else                             //判断是否为左子树
        if(b_tree[level].Left!=-1)
          level=b_tree[level].Left;
        else
          position=1;                  //设为左树
    }
    if(position==1)
      b_tree[level].Left=i;            //连接左子树
    else
      b_tree[level].Right=i;           //连接右子树
  }
}

void print()
{
  for(int i=1; i<=n; i++)
    cout<<b_tree[i].Left<<' '<<b_tree[i].Date<<' '<<b_tree[i].Right<<'\n';
}

int main()
{
  freopen("arraytree.in","r",stdin);
  freopen("arraytree.out","w",stdout);
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)            //初始化
  {
    b_tree[i].Left=-1;
    b_tree[i].Date=0;
    b_tree[i].Right=-1;
  }
  create(node,n);
  print();
  return 0;
}

