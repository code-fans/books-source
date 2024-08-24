#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//线段树
//区间染色
const int maxN = 1000010;
struct node
{
  int lt, rt, val, turn;
} tree[4*maxN];
int a[30];
int t=0;
//向下更新
void pushDown(int id)
{
  if (tree[id].turn != 0)
  {
    tree[id<<1].turn = tree[id<<1].val = tree[id].turn;
    tree[id<<1|1].turn = tree[id<<1|1].val = tree[id].turn;
    tree[id].turn = 0;
  }
}

//向上更新
void pushUp(int id)
{
  if (tree[id<<1].val == tree[id<<1|1].val)
    tree[id].val = tree[id<<1].val;
  else
    tree[id].val = 0;
}

//建立线段树
void build(int lt, int rt, int id)
{
  tree[id].lt = lt;
  tree[id].rt = rt;
  tree[id].val = 2;//每段的初值，根据题目要求
  tree[id].turn = 2;
  if (lt == rt)
  {
    //tree[id].turn = ??;
    tree[id].turn=2;
    return;
  }
  int mid = (lt+rt)>>1;
  build(lt, mid, id<<1);
  build(mid+1, rt, id<<1|1);
}

//更改每段的值，多用于染色
void change(int lt, int rt, int id, int col)
{
  if(lt <= tree[id].lt && rt >= tree[id].rt)
  {
    tree[id].val = tree[id].turn = col;
    return;
  }
  pushDown(id);
  int mid = (tree[id].lt+tree[id].rt)>>1;
  if (lt <= mid)
    change(lt, rt, id<<1, col);
  if (rt > mid)
    change(lt, rt, id<<1|1, col);
  pushUp(id);
}

void query(int lt, int rt, int id)
{
  if (lt > tree[id].rt || rt < tree[id].lt)
    return;
  if (tree[id].val != 0)
  {
    //operator;
    int ok=0;
    for(int i=0; i<t; i++)
    {
      if(a[i]==tree[id].val)
        ok=1;
    }
    if(ok==0)
      a[t++]=tree[id].val;
    return;
  }
  query(lt, rt, id<<1);
  query(lt, rt, id<<1|1);
}
int main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int n,m;
  while(~scanf("%d%d",&n,&m) && (n!=0 || m!=0) )
  {
    build(1,n,1);
    while(m--)
    {
      char str[5];
      scanf("%s",str);
      //printf("%s\n",str);
      if(str[0]=='P')
      {
        int l,r,turn,root=1;
        scanf("%d%d%d",&l,&r,&turn);
        change(l,r,1,turn);
      }
      else
      {
        int l,r;
        t=0;
        scanf("%d%d",&l,&r);
        query(l,r,1);
        sort(a,a+t);
        for(int i=0; i<t; i++)
        {
          if(i)
            printf(" ");
          printf("%d",a[i]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
