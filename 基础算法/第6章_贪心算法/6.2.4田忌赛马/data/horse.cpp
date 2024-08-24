//田忌赛马 - 贪心+动规
#include <bits/stdc++.h>
using namespace std;

int tian[1001],king[1001];
int f[1001][1001];

int S(int i,int j)
{
  if(tian[i]==king[j])
    return 0;
  return (tian[i]>king[j]?200:-200);
}

int main()
{
  freopen("horse.in","r",stdin);
  freopen("horse.out","w",stdout);

  for(int n; scanf("%d",&n)  && n;)
  {
    memset(f,0,sizeof(f));
    int ans=-0x7fffffff;
    for(int i=1; i<=n; i++)
      scanf("%d",&tian[i]);
    for(int i=1; i<=n; i++)
      scanf("%d",&king[i]);
    sort(tian+1,tian+n+1,greater<int>());
    sort(king+1,king+n+1,greater<int>());
    for(int i=1; i<=n; i++)
    {
      f[i][i]=f[i-1][i-1]+S(i,i);
      f[i][0]=f[i-1][0]+S(n-i+1,i);
      for(int j=1; j<i; j++)
        f[i][j]=max(f[i-1][j-1]+S(j,i),f[i-1][j]+S(n-(i-j)+1,i));
    }
    for(int j=0; j<=n; j++)
      ans=max(ans,f[n][j]);
    printf("%d\n",ans);
  }
  return 0;
}

