#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int ans,n,m,sum,f[101][51][512]= {1},cnt[512];

bool Check(int a,int b,int k)
{
  return a==n?0:a>=b||a+1<=b-cnt[sum-k];
}

void GetMod(int &ans,int b)
{
  ans=(ans+b)%mod;
}

int main()
{
  //freopen("hat.in","r",stdin);
  //freopen("hat.out","w",stdout);
  scanf("%d%d",&n,&m);
  sum=(1<<(--m))-1;
  for(int i=1; i<=sum; i++)
    cnt[i]=cnt[i^(i&(-i))]+1;       //统计i的二进制数有多少个1
  for(int i=0; i<=(n<<1)-1; i++)
    for(int j=0; j<=n; j++)
      for(int k=0; k<=sum; k++)     //枚举所有方案
      {
        if(Check(j,i-j,k))
          GetMod(f[i+1][j+1][((k<<1)|1)&sum],f[i][j][k]);
        if(Check(i-j,j,sum-k))
          GetMod(f[i+1][j][(k<<1)&sum],f[i][j][k]);
      }
  for(int i=0; i<=sum; i++)
    GetMod(ans,f[n<<1][n][i]);
  printf("%d\n",ans);
  return 0;
}
