//Ë¿³ñÖ®Â· ¡ªDP2
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;

int D[1002],C[1002],f[1002][1002];

int main()
{
  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=1; i<=N; i++)
    scanf("%d",&D[i]);
  for(int i=1; i<=M; i++)
    scanf("%d",&C[i]);
  memset(f,127,sizeof(f));
  for(int i=0; i<=M; i++)
    f[0][i]=0;
  for(int i=1; i<=N; i++)
    for(int j=i; j<=M-(N-i); j++)
      f[i][j]=min(f[i][j-1],f[i-1][j-1]+D[i]*C[j]);
  int ans=INF;
  for(int i=N; i<=M; i++)
    ans=min(ans,f[N][i]);
  printf("%d",ans);
  return 0;
}
