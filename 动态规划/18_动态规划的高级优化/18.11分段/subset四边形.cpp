//�ֶ� �ı����Ż�
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10005],dp[5005][10005],s[5005][10005];

inline int Read(int x=0)                        //���ַ�����ʽ�������ֿ�����
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
  return x;
}

int Dp()
{
  for(int len=1; len<n; len++)
    for(int i=1; i<=m; i++)//ö�ٷֶ� 
    {
      int j=i+len;         //ö������ 
      if(j>n)
        break ;
      for(int k=s[i][j-1]; k<=s[i+1][j]; k++)//�Ż� 
      {
        int t=dp[i-1][k-1]+(a[k]-a[j])*(a[k]-a[j]);
        if(dp[i][j]>t)
        {
          dp[i][j]=t;
          s[i][j]=k;
        }
      }
    }
  return dp[m][n];
}

int main()
{
  freopen("subset.in","r",stdin);
  freopen("subset.out","w",stdout);
  for(int t=Read(),Case=0; t; t--)
  {
    n=Read();
    m=Read();
    for(int i=1; i<=n; i++)
      a[i]=Read();
    sort(a+1,a+n+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=0; i<=m; i++)
    {
      dp[i][i]=0;
      s[i][i]=i;
    }
    for(int i=m+1; i<=n; i++)
      s[m+1][i]=i;
    printf("Case %d: %d\n",++Case,Dp());
  }
  return 0;
}

