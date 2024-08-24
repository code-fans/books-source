//公司效益
#include <bits/stdc++.h>
using namespace std;
const int MAXN=305;
int match[MAXN],visitX[MAXN],visitY[MAXN];
int A[MAXN],B[MAXN],w[MAXN][MAXN];
int n;

int Dfs(int x)
{
  visitX[x]=1;
  for(int i=1; i<=n; i++)
    if(!visitY[i]&&A[x]+B[i]==w[x][i])          //特别判断
    {
      visitY[i]=1;
      if(!match[i] || Dfs(match[i]))
      {
        match[i]=x;
        return 1;
      }
    }
  return 0;
}

void KM()
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      A[i]=max(A[i],w[i][j]);
  for(int i=1; i<=n; i++)
    while(1)
    {
      memset(visitX,0,sizeof(visitX));
      memset(visitY,0,sizeof(visitY));
      if(Dfs(i))
        break;
      else
      {
        int d=INT_MAX;
        for(int j=1; j<=n; j++)
          for(int k=1; visitX[j] && k<=n; k++)
            if(!visitY[k] && d>A[j]+B[k]-w[j][k])
              d=A[j]+B[k]-w[j][k];
        for(int j=1; j<=n; j++)
        {
          if(visitX[j]) A[j]-=d;
          if(visitY[j]) B[j]+=d;
        }
      }
    }
}

int main()
{
  //freopen("max.in","r",stdin);
  //freopen("max.out","w",stdout);
  while(~scanf("%d",&n))
  {
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(match,0,sizeof(match));
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        scanf("%d",&w[i][j]);
    KM();
    int sum=0;
    for(int i=1; i<=n; i++)
      sum+=w[match[i]][i];
    printf("%d\n",sum);
  }
  return 0;
}

