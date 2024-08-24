//»úÆ÷°²ÅÅ
//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=1001;
int map[N][N],vis[N],link[N];
int n1,n2,k;

int DFS(int x)
{
  for(int i=1; i<=n2; i++)
    if(map[x][i]&&!vis[i])
    {
      vis[i]=1;
      if(!link[i]||DFS(link[i]))
      {
        link[i]=x;
        return 1;
      }
    }
  return 0;
}

int main()
{
  //freopen("m.in","r",stdin);
  //freopen("m.out","w",stdout);
  int a,b,c,i,sum;
  while(~scanf("%d",&n1))
  {
    if(!n1)
      break;
    scanf("%d%d",&n2,&k);
    sum=0;
    memset(map,0,sizeof(map));
    memset(link,0,sizeof(link));
    while(k--)
    {
      scanf("%d%d%d",&a,&b,&c);
      if(b*c)
        map[b][c]=1;
    }
    for(i=1; i<=n1; i++)
    {
      memset(vis,0,sizeof(vis));
      if(DFS(i))
        sum++;
    }
    printf("%d\n",sum);
  }
  return 0;
}
