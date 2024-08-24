//序列的逆序数－线段树
#include <bits/stdc++.h>
using namespace std;

struct Seg_Tree
{
  int left,right,val;
  int calmid()
  {
    return (left+right)>>1;
  }
} t[15000];
int val[5001];                               //保存序列

void BuildTree(int left,int right,int pos)
{
  t[pos].left = left;
  t[pos].right = right;
  t[pos].val = 0;                            //这一句不能省
  if(left != right)
  {
    int mid = t[pos].calmid();
    BuildTree(left,mid,pos<<1);
    BuildTree(mid+1,right,pos<<1|1);
  }
}

int Query(int L,int R,int pos)               //统计[L,R]区间比L大的逆序数
{
  if(L <= t[pos].left && R >= t[pos].right)  //如果在包含区间内，则返回值
    return t[pos].val;
  int min = (t[pos].left+t[pos].right)>>1;   //取左右端点的中间
  int ans = 0;
  if(L <= min)
    ans += Query(L, R, pos<<1);          //递归左子树
  if(R > min)
    ans += Query(L, R, pos<<1|1);        //递归右子树
  return ans;
}

void Update(int id,int pos)              //更新所有包含id这个数的区间的val值
{
  t[pos].val ++;                         //加一
  if(t[pos].left != t[pos].right)
  {
    int mid = t[pos].calmid();
    if(id <= mid)
      Update(id,pos<<1);
    else
      Update(id,pos<<1|1);
  }
}

int main()
{
  //freopen("samsara.in","r",stdin);
  //freopen("samsara.out","w",stdout);
  int n;
  while(scanf("%d",&n) == 1)
  {
    BuildTree(0,n-1,1);
    unsigned long long sum = 0;
    for(int i=0; i<n; i++)
    {
      scanf("%d",&val[i]);
      sum += Query(val[i],n-1,1);        //此时val[i]还未插入树中
      Update(val[i],1);                  //此时插入val[i]，即更新树
    }
    unsigned long long Ans = sum;
    for(int i=0; i<n; i++)
    {
      sum=sum-val[i]+(n-val[i]-1);
      Ans=min(Ans,sum);
    }
    cout<<Ans<<endl;
  }
  return 0;
}

