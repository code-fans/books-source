//选课
#include <bits/stdc++.h>
using namespace std;

struct tree
{
  int l,r,v;
} node[301];
int f[301][301];

int DFS(int x,int y)
{
  if(y==0 || x<0)                              //无课可选，或递归到0节点之上
    return 0;
  if(x==0)
    return DFS(node[x].l,y);                  //根节点是没有兄弟的
  if(f[x][y]>=0)                              //记忆化搜索
    return f[x][y];
  f[x][y]=DFS(node[x].r,y);                   //不选第i门课
  for(int i=1; i<=y; i++)                     //选第i门课，枚举如何分配最优
    f[x][y]=max(f[x][y],DFS(node[x].l,i-1)+node[x].v+DFS(node[x].r,y-i));
  return f[x][y];
}

int main()
{
  //freopen("select.in","r",stdin);
  //freopen("select.out","w",stdout);
  int M,N,a,b;
  scanf("%d %d\n",&N,&M);
  memset(node,-1,sizeof(node));
  memset(f,-1,sizeof(f));
  for(int i=1; i<=N; i++)
  {
    scanf("%d %d\n",&a,&b);
    node[i].r=node[a].l;                      //多叉树转二叉树
    node[a].l=i;
    node[i].v=b;
  }
  printf("%d\n",DFS(0,M));                   //从0节点开始，有M门课可选
  return 0;
}
