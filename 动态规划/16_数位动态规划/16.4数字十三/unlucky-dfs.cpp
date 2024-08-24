//数字十三
//题目要求包含13且能被13整除，所以定义
//dp[pos][last][ok][mod]表示pos位数，上位数是last,ok:是否已经包含13，mod:该数对13取模后的值
#include <bits/stdc++.h>
using namespace std;

const int N=20;
int dp[N][10][2][13],num[N],n,len;

int DFS(int pos,int last,bool ok,int mod,bool limit)//上一位数,当前数的余数
{
  if (!pos)
    return ok && !mod;    //包含13且能被13整除，返回1
  if (~dp[pos][last][ok][mod] && !limit)//如果dp[pos][last][ok][mod]已经有值且无限制
    return dp[pos][last][ok][mod];
  int up=limit ? num[pos]:9;
  int ans=0;
  for (int i=0; i<=up; i++)
    ans+=DFS(pos-1,i,ok || last==1 && i==3,(mod*10+i)%13,limit && i==num[pos]);
  if (!limit)
    dp[pos][last][ok][mod]=ans;
  return ans;
}

int main()
{
  freopen("unlucky.in","r",stdin);
  freopen("unlucky.out","w",stdout);
  memset(dp,-1,sizeof(dp));
  while (~scanf("%d",&n))            //没有输入返回-1,取反为0
  {
    for(len=0; n; n/=10)
      num[++len]=n%10;
    printf("%d\n",DFS(len,0,0,0,1));
  }
  return 0;
}
