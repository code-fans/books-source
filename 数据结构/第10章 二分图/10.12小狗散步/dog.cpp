#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

struct Data
{
  int x, y;
} A[maxn], B[maxn];
int N, M;
int ch[maxn][maxn], Link[maxn<<2], vis[maxn<<2];

double dis(Data X, Data Y)
{
  return sqrt(abs(X.x-Y.x)*abs(X.x-Y.x)+abs(X.y-Y.y)*abs(X.y-Y.y));
}

bool dfs(int u)
{
  for(int i = 1; i <= N - 1; i++)
    if(!vis[i] && ch[u][i])
    {
      vis[i] = 1;
      if(!Link[i] || dfs(Link[i]))
      {
        Link[i] = u;
        return true;
      }
    }
  return false;
}

int main()
{
  freopen("dog.in","r",stdin);
  freopen("dog.out","w",stdout);
  scanf("%d%d",&N,&M);
  for(int i = 1; i <= N; i++)
    scanf("%d%d", &A[i].x, &A[i].y);
  for(int i = 1; i <= M; i++)
    scanf("%d%d", &B[i].x, &B[i].y);
  memset(ch, 0, sizeof(ch));
  for(int i = 1; i <= N - 1; i++)
    for(int j = 1; j <= M; j++)
      if(dis(A[i], A[i+1]) > (dis(A[i], B[j]) + dis(B[j], A[i+1])) / 2)
        ch[j][i] = 1;
  int ans = 0;
  memset(Link, 0, sizeof(Link));
  for(int i = 1; i <= M; i++)
  {
    memset(vis, 0, sizeof(vis));
    if(dfs(i)) ans++;
  }
  printf("%d\n", ans + N);
  for(int i = 1; i <= N; i++)
  {
    printf("%d %d", A[i].x, A[i].y);
    if(i == N) printf("\n");
    else
    {
      printf(" ");
      if(Link[i]) printf("%d %d ", B[Link[i]].x, B[Link[i]].y);
    }
  }
  return 0;
}
