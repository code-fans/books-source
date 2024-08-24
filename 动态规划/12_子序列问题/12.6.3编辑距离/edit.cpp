//动态规划思想，题目问的是字符串a到字符串b的编辑距离。动态规划有最优子问题结构，
//子问题的形式和原问题结构相似，且规模减小。那么在考虑问题的时候，往前想一步：
//
//·如果字符串a前alen-1个字符已经和b相同，那么当前a到b的编辑距离就是1（删除最后一个）
//
//·如果字符串a和b的前blen-1个字符相同，那么当前a到b的距离也是1（添加一个）
//·如果a的前alen-1个字符和b的blen-1个字符已经相同，如果a的最后一个字符和b的最后一个
//字符相同，那么a到b的编辑距离为0，否则为1（改变一次）
//设状态为dp[i][j],表示字符串a的前i个字符到字符串b的前j个字符的编辑距离，由以上分析，
//可以写出该dp的状态转移方程：
//
//dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1])(a的第i个字符和b的第j个字符相同)
//dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)(a的第i个字符和b的第j个字符不同)
#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
int d[maxn][maxn];

int min(int a,int b,int c)
{
  if(a>b) swap(a,b);
  if(a>c) swap(a,c);
  return a;
}

int main()
{
  freopen("edit.in","r",stdin);
  freopen("edit.out","w",stdout);
  char a[maxn],b[maxn];
  cin>>a>>b;
  memset(d,0,sizeof(d));
  int len1=strlen(a);
  for(int i=1; i<=len1; i++)
    d[i][0]=i;
  int len2=strlen(b);
  for(int i=1; i<=len2; i++)
    d[0][i]=i;
  for(int i=1; i<=len1; i++)
    for(int j=1; j<=len2; j++)
      d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+(a[i-1]==b[j-1]?0:1));
  cout<<d[len1][len2]<<endl;
  return 0;
}
