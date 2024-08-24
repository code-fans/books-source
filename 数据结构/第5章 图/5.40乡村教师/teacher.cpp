#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=5050;
struct node
{
  int v;
  int next;
} Edg[MAXN<<1];                   //有向图
int Stack[MAXN],top;
int dfn[MAXN],low[MAXN],index;//index用于记录次序编号
bool vis[MAXN];
int st[MAXN],cnt;
int color[MAXN],s[MAXN],num;  //染色并记录颜色种类

void build(int a,int b)
{
  Edg[++cnt].v=b;
  Edg[cnt].next=st[a];
  st[a]=cnt;
}//建图

void tarjan(int x)
{
  dfn[x]=++index;
  low[x]=index;
  vis[x]=true;
  Stack[++top]=x;//当前点入栈
  int i;
  for(i=st[x]; i!=0; i=Edg[i].next) //枚举以当前点为起点的边
  {
    int t=Edg[i].v;//当前被枚举边的终点
    if(!dfn[t])//如果当前边终点未被处理
    {
      tarjan(t);
      low[x]=min(low[x],low[t]);
    }
    else if(vis[t])low[x]=min(low[x],dfn[t]);
  }
  if(dfn[x]==low[x])
  {
    vis[x]=false;
    color[x]=++num;//给当前强连通分量染上新颜色
    s[num]++;//给当前强连通分量里的点染色
    while(Stack[top]!=x)//栈顶元素依次出栈
    {
      s[num]++;
      color[Stack[top]]=num;
      vis[Stack[top--]]=false;
    }
    top--;
  }
}

int main()
{
  freopen("teacher.in","r",stdin);
  freopen("teacher.out","w",stdout);
  int n,m,t,f;
  scanf("%d%d",&n,&m);
  int a,b;
  for(int i=1; i<=m; i++)
  {
    scanf("%d%d%d",&a,&b,&t);
    build(a,b);
    if(t-1)build(b,a);
  }
  for(int i=1; i<=n; i++)
    if(!dfn[i])
      tarjan(i);
  int ans=0;
  for(int i=1; i<=n; i++)
    if(s[color[i]]>ans)
    {
      ans=s[color[i]];
      f=i;
    }
  printf("%d\n",ans);
  for(int i=1; i<=n; i++)
    if(color[i]==color[f])
      printf("%d ",i);
  return 0;
}

