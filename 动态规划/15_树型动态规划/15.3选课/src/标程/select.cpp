//选课
#include <bits/stdc++.h>
using namespace std;

const int MAXN=301;
struct tree
{
  int l,r,c;
} node[MAXN];
int f[MAXN][MAXN];

int DFS(int x,int y)
{
  if(!y || x<0)
    return 0;
  if(!x)
    return DFS(node[x].l,y);                  //根节点是没有兄弟的
  if(f[x][y]>=0)
    return f[x][y];
  f[x][y]=DFS(node[x].r,y);
  for(int i=1; i<=y; i++)
    f[x][y]=max(f[x][y],DFS(node[x].l,i-1)+node[x].c+DFS(node[x].r,y-i));
  return f[x][y];
}

int main()
{
  freopen("select.in","r",stdin);
  freopen("select.out","w",stdout);
  int M,N,a,b;
  scanf("%d %d\n",&N,&M);
  memset(node,-1,sizeof(node));
  memset(f,-1,sizeof(f));
  for(int i=1; i<=N; i++)
  {
    scanf("%d %d\n",&a,&b);
    node[i].r=node[a].l;                      //多叉树转二叉树
    node[a].l=i;
    node[i].c=b;
  }
  printf("%d\n",DFS(0,M));
  return 0;
}

