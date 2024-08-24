//哈密尔顿环
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;

int start,lent,g[MAXN][MAXN],num[MAXN],ans[MAXN];
bool val[MAXN],visit[MAXN];

void Out(int len)
{
  for(int i=1; i<=len; i++)
    printf("%d%c",ans[i],i==len?'\n':' ');
}

void Dfs(int last, int cur,int len)   //last:上次访问的点,cur:正访问的点
{
  visit[cur]=true;                    //当前点设置为已访问过
  ans[++len]=cur;                     //将该点加到答案里,lenth为环的长度
  for(int i=1; i<=num[cur]; i++)      //寻找i点连接的所有边
  {
    if(g[cur][i]==start && g[cur][i]!=last)//回到起点且不是第二个点即是环
    {
      ans[++len]=g[cur][i];
      Out(len--);                     //输出答案后len--
      //break;                        //此处不要break,因为要找所有环
    }
    if(!visit[g[cur][i]] && g[cur][i]>cur)//遍历与i关联的未访问点
      Dfs(cur,g[cur][i],len);         //g[cur][i]>cur保证后面数字大于前面才不重复
  }
  visit[cur]=false;                   //回溯
}

int main()
{
  //freopen("circle.in","r",stdin);
  //freopen("circle.out","w",stdout);

  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1,u,v; i<=m; i++)
  {
    scanf("%d%d",&u,&v);
    g[u][++num[u]]=v;                 //num[u]统计u点的连接边数
    g[v][++num[v]]=u;
  }
  for(start=1; start<=n; start++)     //尝试每一个点做为起始点
    Dfs(0,start,0);
  return 0;
}

