//黑白涂色-最大团算法
#include <bits/stdc++.h>
using namespace std;

int Edg[110][110],Set[505],tmp[505];
int n,m,cnt,maxx;

void dfs(int x)
{
  if(x>n)                                       // 如果枚举了所有的结点
  {
    maxx=cnt;
    memcpy(Set,tmp,sizeof(tmp));   //用一个更大的极大团替代原有的极大团
    return;
  }
  bool flag=true;
  for(int i=1; i<x; i++)//检测新加入的点是否到团中的其它结点都存在一条边
    if(tmp[i] && !Edg[i][x])              //如果i点在团中，但两点没有边
    {
      flag=false;
      break;
    }

  if(flag)                              //如果该结点满足在这个团中
  {
    tmp[x]=1,cnt++;                     //该结点被加入到完全子图中去
    dfs(x+1);
    tmp[x]=0,cnt--;                     //恢复原值
  }
  if (cnt+n-x>maxx)                     //否则不加入x，剪枝,保证团元素个数递增
    dfs(x+1);
}

int main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    memset(Set,0,sizeof(Set));
    memset(tmp,0,sizeof(tmp));
    maxx=cnt=0;
    for(int i=0; i<110; i++)
      fill(Edg[i],Edg[i]+110,1);        //将每一行数据元素全部填充为1
    for(int i=1; i<=m; i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      Edg[a][b]= Edg[b][a]=0;           //构建补图
    }
    dfs(1);                             //从结点1开始搜索
    printf("%d\n",maxx);
    for(int i=1,k=0; i<=n; i++)
      if(Set[i])
        k++==0? printf("%d",i):printf(" %d",i);
    printf("\n");
  }
  return 0;
}

