//平衡
#include<bits/stdc++.h>
using namespace std;
const int MAXN=20050;
int head[MAXN],n,cnt,AnsNode,AnsNum;
struct node
{
  int v,next;
} e[MAXN<<1];

void AddEdge(int u,int v)                  //使用前向星表示法，请参见第五章
{
  e[cnt].v=v;
  e[cnt].next=head[u];
  head[u]=cnt++;
}

int dfs(int node,int father)
{
  int sum=1,SonMax=0,SonNum;
  for(int i=head[node]; i!=-1; i=e[i].next)
    if(e[i].v!=father)
    {
      SonNum=dfs(e[i].v,node);
      SonMax=max(SonMax,SonNum);            //更新子树最大结点值
      sum+=SonNum;                          //统计出node结点的规模值
    }
  SonMax=max(n-sum,SonMax);                 //上方子树结点数=n-sum
  if((SonMax<AnsNum)||(SonMax==AnsNum && node<AnsNode)) //更新最优解
  {
    AnsNode=node;
    AnsNum=SonMax;
  }
  return sum;
}

int main()
{
  //freopen("banance1.in","r",stdin);
  //freopen("banance1.ans","w",stdout);
  int T,a,b;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    memset(head,-1,sizeof(int)*(n+1));
    cnt=0;
    AnsNode=AnsNum=0x3f3f3f3f;
    for(int i=1; i<=n-1; i++)
    {
      scanf("%d%d",&a,&b);
      AddEdge(a,b);
      AddEdge(b,a);
    }
    dfs(1,-1);
    printf("%d %d\n",AnsNode,AnsNum);
  }
  return 0;
}

