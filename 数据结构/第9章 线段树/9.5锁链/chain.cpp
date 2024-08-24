//锁链
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int left,right,color;                 //color二进制码标记颜色
  int lazy;                             //标记是否更新
  int mid()
  {
    return (left+right)>>1;
  }
} E[100005<<2];                         //大小设为4倍

void BuildTree(int root,int l,int r)
{
  E[root].left=l;
  E[root].right=r;
  E[root].color=1;
  E[root].lazy=0;                       //初始为未标记
  if(l!=r)
  {
    int mid=E[root].mid();
    BuildTree(root<<1,l,mid);
    BuildTree(root<<1|1,mid+1,r);
  }
}

void Update(int pos,int l,int r,int c)  //lazy思想，延迟更新
{
  if(E[pos].left==l && E[pos].right==r) //恰好为该段
  {
    E[pos].color=c;
    if(l^r)                            //叶子结点不能标记lazy
      E[pos].lazy=1;                   //作懒标记
  }
  else
  {
    if(E[pos].lazy==1)                  //如果已做标记
    {
      E[pos<<1].lazy=E[pos<<1|1].lazy=1;//两子结点也做标记
      E[pos<<1].color=E[pos<<1|1].color=E[pos].color;//更新为父结点颜色
      E[pos].lazy=0;                    //自身清空
    }
    int mid=E[pos].mid();
    if(r<=mid)
      Update(pos<<1,l,r,c);             //更新左结点
    else if(l>mid)
      Update(pos<<1|1,l,r,c);           //更新右结点
    else
    {
      Update(pos<<1,l,mid,c);
      Update(pos<<1|1,mid+1,r,c);
    }
    E[pos].color=E[pos<<1].color|E[pos<<1|1].color;//位或运算
  }
}

int Query(int pos,int l,int r)
{
  if((E[pos].left==l && E[pos].right==r) || E[pos].lazy==1)
    return E[pos].color;
  else
  {
    int mid=E[pos].mid();
    if(r<=mid)
      return Query(pos<<1,l,r);         //递归左结点
    else if(l>mid)
      return Query(pos<<1|1,l,r);       //递归右结点
    else
      return Query(pos<<1,l,mid)|Query(pos<<1|1,mid+1,r);//两段的合并
  }
}

int Code(int x)                         //将x转换为二进制码
{
  return 1<<(x-1);                      //例如x=7,返回64,即二进制1000000
}

int Ucode(int x,int t=0)                //计算二进制的x中有多少个1
{
  for (; x; x>>=1)
    t+= x&1;                            //如果当前位为1
  return t;
}

int main()
{
  int L,m,t,st,en,a,b,c;
  char opt;
  while(~scanf("%d%d%d",&L,&t,&m))
  {
    BuildTree(1,1,L);
    for(int i=0; i<m; i++)
    {
      scanf(" %c",&opt);
      if(opt=='C')
      {
        scanf("%d%d%d",&a,&b,&c);
        c=Code(c);                      //将颜色转为二进制
        a<b?Update(1,a,b,c):Update(1,b,a,c);
      }
      if(opt=='P')
      {
        scanf("%d%d",&st,&en);
        printf("%d\n",st<en?Ucode(Query(1,st,en)):Ucode(Query(1,en,st)));
      }
    }
  }
  return 0;
}

