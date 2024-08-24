//致命武器
#include <bits/stdc++.h>
using namespace std;
#define lson l,m,pos<<1               //pos<<1相当于pos*2 
#define rson m+1,r,pos<<1|1           //pos<<1|1相当于pos*2+1 
#define N 100001

int st[N<<2];                         //st[]记录金属标记：0,1,2,3;其中0代表杂色

void BuildTree(int l,int r,int pos,int Metal)
{
  st[pos]=Metal;
  if(l!=r)
  {
    int m=(l+r)>>1;                   //二分递归左右子结点
    BuildTree(lson,Metal);
    BuildTree(rson,Metal);
  }
}

void Updata(int L,int R,int l,int r,int pos,int Metal)//更新L~R,从1~n,st[1]开始
{
  if(L<=l && R>=r)                    //如果更新部分恰好被包含
    st[pos]=Metal;                    //则整个一段都更新为新颜色
  else
  {
    if(st[pos])                       //如果该结点为纯色,且修改部分区间
    {
      st[pos<<1]=st[pos<<1|1]=st[pos];//则左儿子和右儿子均设为该颜色
      st[pos]=0;                      //st[pos]设为杂色
    }
    int m=(l+r)>>1;
    if(L<=m)
      Updata(L,R,lson,Metal);         //递归更新左儿子
    if(R>m)
      Updata(L,R,rson,Metal);         //递归更新右儿子
  }
}

int Query(int l,int r,int pos)
{
  if(st[pos])                         //st[pos]为纯色时
    return st[pos]*(r-l+1);           //直接返回成段相乘的结果
  int m=(l+r)>>1;
  return Query(lson)+Query(rson);
}

int main()
{
  //freopen("terminator.in","r",stdin);
  //freopen("terminator.out","w",stdout);
  int T,L,R,n,q,Metal,Case=0;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&q);
    BuildTree(1,n,1,1);
    while(q--)
    {
      scanf("%d%d%d",&L,&R,&Metal);
      Updata(L,R,1,n,1,Metal);
    }
    printf("Case %d: The total value of the hook is %d.\n",++Case,Query(1,n,1));
  }
  return 0;
}

