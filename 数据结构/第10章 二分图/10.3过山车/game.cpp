//过山车
#include<bits/stdc++.h>
using namespace std;
#define N 510
int n,m,k;
bool Graphi[N][N];
int Boy[N],Girl[N];            //Boy[x]=y表示男x连女y，Giry[x]=y表示女x连男y
int pre[N],visit[N];           //pre[]存上一结点,visit[x]=y表示女x被男y访问过

int FindMatch(int iBoy)
{
  queue<int> q;
  q.push(iBoy);                    //男生iBoy入队列
  pre[iBoy]=-1;
  bool flag=0;
  while(!q.empty()&&!flag)         //当队列不为空并且未找到匹配时
  {
    int boy=q.front();             //取出队首男生
    q.pop();
    for(int girl=1; girl<=m && !flag; girl++) //未找到匹配时，枚举所有女生
      if(Graphi[boy][girl]&&visit[girl]!=iBoy)//如果男女有连边且未被iboy访问过
      {
        visit[girl]=iBoy;          //标记girl为已访问
        q.push(Girl[girl]);        //与girl相关联的男运动员入队列（可能为-1）
        if(Girl[girl]>=0)          //如没有增广路径,就回到循环枚举下个女生
          pre[Girl[girl]]=boy;     //标记位置以便后面回推更改交错轨状态
        else                       //如果有增广路
        {
          flag=1;
          int bb=boy,gg=girl;
          while(bb!=-1)            //回推，更改交错轨的状态
          {
            int t=Boy[bb];
            Boy[bb]=gg,Girl[gg]=bb;
            bb=pre[bb],gg=t;
          }
        }
      }
  }
  return Boy[iBoy]!=-1;
}

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  while(~scanf("%d",&k) && k)
  {
    memset(Boy,-1,sizeof(Boy));
    memset(Girl,-1,sizeof(Girl));
    memset(visit,-1,sizeof(visit));
    memset(Graphi,0,sizeof(Graphi));
    scanf("%d%d",&n,&m);
    int a,b;
    while(k--)
    {
      scanf("%d%d",&a,&b);
      Graphi[a][b]=1;
    }
    int ans=0;
    for(int i=1; i<=n; i++)        //枚举每个男生i
      if(Boy[i] == -1)             //如果男i没有匹配
        if(FindMatch(i))           //如果男i发现一条增广路径
          ans++;                   //匹配数++
    printf("%d\n",ans);
  }
  return 0;
}

