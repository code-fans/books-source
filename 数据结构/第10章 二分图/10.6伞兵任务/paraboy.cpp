//É¡±øÈÎÎñ
#include <bits/stdc++.h>
using namespace std;
int g[125][125];
bool visit[125];
int Link[125];
int m,n;

int Find(int x)
{
  for (int i=1; i<=m; i++)
    if (g[x][i] && !visit[i])
    {
      visit[i]=1;
      if (!Link[i] || Find(Link[i]))
      {
        Link[i]=x;
        return 1;
      }
    }
  return 0;
}

int main ()
{
  //freopen("paraboy.in","r",stdin);
  //freopen("paraboy.out","w",stdout);
  int t,x,y;
  scanf("%d",&t);
  while (t--)
  {
    scanf("%d %d",&m,&n);
    memset(g,0,sizeof(g));
    for (int i=0; i<n; i++)
    {
      scanf("%d %d",&x,&y);
      g[x][y]=1;
    }
    int sum=0;
    memset(Link,0,sizeof(Link));
    for (int i=1; i<=m; i++)
    {
      memset(visit,0,sizeof(visit));
      sum+=Find(i);
    }
    printf ("%d\n",m-sum);
  }
  return 0;
}

