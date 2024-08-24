//唯一最短路 —次小生成树2
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int n,m;
bool InMST[110][110];                   //InMST[i][j]表示边(i,j)是否在MST中
int G[110][110],Max[110][110],dad[110],mincount[110];

int Prim()                              //Prim算法
{
  int ans=0,k;
  for(int i=1; i<=n; i++)
  {
    mincount[i]=G[1][i];
    dad[i]=1;                           //初始时MST中只有结点1
  }
  mincount[1]=0;                        //结点1放入集合
  for(int i=1; i<n; i++)
  {
    int Min=INF;
    for(int j=1; j<=n; j++)
      if(mincount[j] && mincount[j]<Min)//寻找集合外最小的边
      {
        k=j;
        Min=mincount[j];
      }
    mincount[k]=0;                      //k点加入集合
    ans+=Min;
    InMST[dad[k]][k]=InMST[k][dad[k]]=1;//边加入MST
    for(int j=1; j<=n; j++)             //遍历所有的点,求其余点到k的最大权值
      Max[j][k]=max(Min,Max[j][dad[k]]);//Max[j][k]:新边或j到k父结点最大权值
    for(int j=1; j<=n; j++)
      if(mincount[j]>G[k][j])           //有更小的集合内k点到集合外的j点的连边
      {
        mincount[j]=G[k][j];            //修正k点到集合外点的最小权值
        dad[j]=k;                       //标记集合外j点离集合内的k点最近
      }
  }
  return ans;                           //返回最小生成树的权值
}

int main()
{
  //freopen("OnePath.in","r",stdin);
  //freopen("OnePath.out","w",stdout);
  memset(G,INF,sizeof(G));              //设所有边初始值为无穷大
  scanf("%d %d",&n,&m);
  for(int u,v,w; m; m--)
  {
    scanf("%d %d %d",&u,&v,&w);
    G[u][v]=G[v][u]=w;
  }
  int mst=Prim();
  for(int i=1; i<=n; i++)               //从全部边中枚举出不在MST上的边添加
    for(int j=1; j<=n; j++)
      if(!InMST[i][j] && G[i][j]!=INF && G[i][j]==Max[i][j])//和删除边等价
      {
        printf("Not Unique!\n");        //添加边和删除边等价，MST不唯一
        exit(0);
      }
  printf("%d\n",mst);
  return 0;
}

