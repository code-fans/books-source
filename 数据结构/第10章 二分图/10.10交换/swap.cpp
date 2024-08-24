//交换
#include<bits/stdc++.h>
using namespace std;
#define N 1100
int Link[N], G[N][N], vis[N], n;

int DFS(int u)
{
  for(int i=1; i<=n; i++)
    if(!vis[i] && G[u][i])
    {
      vis[i] = 1;
      if(!Link[i] || DFS(Link[i]))
      {
        Link[i] = u;
        return 1;
      }
    }
  return 0;
}

int main()
{
  freopen("swap10.in","r",stdin);
  freopen("swap10.ans","w",stdout);
  while(scanf("%d", &n) != EOF)
  {
    memset(G, 0,sizeof(G));
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        scanf("%d",&G[i][j]);
    int ans = 0;
    memset(Link, 0,sizeof(Link));
    for(int i=1; i<=n; i++)
    {
      memset(vis, 0,sizeof(vis));
      ans += DFS(i);
    }
    if(ans < n)
      printf("-1\n");
    else
    {
      int cnt = 0, a[N][2]= {0};
      for(int i=1; i<=n; i++)                 //对数组Link排序的过程
        while(i != Link[i])                   //当前位置不是正确的数时
        {
          a[cnt][0] = i,a[cnt][1]=Link[i];
          swap(Link[i],Link[Link[i]]);        //把i位置上的数放到应放的位置
          cnt ++;
        }
      printf("%d\n", cnt);
      for(int i=0; i<cnt; i++)
        printf("C %d %d\n", a[i][0], a[i][1]);//只交换行或只交换列都可以换出来
    }
  }
  return 0;
}

