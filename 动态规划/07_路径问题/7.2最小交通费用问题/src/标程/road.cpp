//最小交通费用问题
#include <bits/stdc++.h>
using namespace std;
const int MAXN=101;

int N,M,a,b,s;
int D[MAXN][MAXN];

void Floyd()
{
  for (int k=1; k<=N; k++)
    for (int i=1; i<=N; i++)
      for (int j=1; j<=N; j++)
        if (D[i][k]!=-1 && D[k][j]!=-1)
          if (D[i][k]+D[k][j]<D[i][j] || D[i][j]==-1)
            D[i][j]=D[i][k]+D[k][j];
}

int main()
{
  //freopen("road.in" ,"r",stdin);
  //freopen("road.out","w",stdout);
  scanf("%d %d",&N,&M);
  memset(D,-1,sizeof(D));
  for (int i=1; i<=M; i++)
  {
    scanf("%d %d %d",&a,&b,&s);
    D[a][b]=s;
  }
  scanf("%d %d",&a,&b);
  Floyd();
  printf("%d\n",D[a][b]+D[b][a]);
  return 0;
}

