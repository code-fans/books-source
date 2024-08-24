//观察17、18、20的二进制表示，可以发现，共有K个1，因为整数幂各不相同
//推广到B进制，符合条件的数转化为B进制，同理，有K个1
//题目转化成求某区间内，满足一个数的b进制中恰好有k个1，其余都是0的数的个数有多少个
//b进制也按2进制来算，即非0的数均看成是1，0仍为0即可
#include<bits/stdc++.h>
using namespace std;

int x,y,k,b;
int a[34];
int dp[34][34];

int DFS(int pos, int sum, bool limit)
{
  if(pos<=0 || sum>k)
    return sum==k;
  if(!limit && dp[pos][sum]!=-1)
    return dp[pos][sum];
  int up=limit?(a[pos]?1:0):1;
  int ans=0;
  for(int i=0; i<=up; i++)
    ans+=DFS(pos-1,sum+i,limit && i==a[pos]);
  if(!limit)
    dp[pos][sum]=ans;
  return ans;
}

int Cal(int n)
{
  int len=0;
  for(; n; n/=b)//转成B进制 
    a[++len]=n%b;
  return DFS(len,0,true);
}

int main()
{
  freopen("amount.in","r",stdin);
  freopen("amount.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  scanf("%d%d%d%d",&x,&y,&k,&b);
  printf("%d\n",Cal(y)-Cal(x-1));
}

