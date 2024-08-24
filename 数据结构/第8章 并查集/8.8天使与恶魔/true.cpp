#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN=600;

int fa[MAXN],Rank[MAXN],sets[MAXN],tag[MAXN][2],path[MAXN][MAXN],man[MAXN][2];

int Find(int x)
{
  if(x!=fa[x])
  {
    int px=Find(fa[x]);
    Rank[x]^=Rank[fa[x]];               //x->z=(x->y)^(y->z)
    fa[x]=px;                           //路径压缩
  }
  return fa[x];
}

void Union(int x, int y, int d)
{
  int px=Find(x);
  int py=Find(y);
  if(px!=py)
  {
    fa[py]=px;
    Rank[py]=Rank[x]^Rank[y]^d;          //yes同类，no为异类
  }
}

int main()
{
  int m,p,q,x,y;
  while(scanf("%d%d%d",&m,&p,&q)==3 && m || p || q)
  {
    memset(sets, 0, sizeof(sets));
    memset(path, 0, sizeof(path));
    memset(tag, 0, sizeof(tag));
    memset(man, 0, sizeof(man));
    for(int i=1; i<=p+q; i++)
    {
      Rank[i]=0;                         //Rank=0表示同类，=1表示异类
      fa[i]=i;                           //并查集初始化
    }
    while(m--)
    {
      char ch[5];
      scanf("%d%d%s", &x, &y, ch);
      Union(x, y, ch[0]=='y' ? 0 : 1);
    }
    int tot=0;
    for(int i=1; i<=p+q; i++)             //统计最后生成的并查集个数并且编号
      if(Find(i)==i)                      //如果不等于自身，说明已经链到别的集合了
        sets[i]=++tot;
    for(int i=1; i<=p+q; i++)             //统计每个集合两种类的数目并存储到tag中
      tag[sets[Find(i)]][Rank[i]]++;      //用Find(i)找到i属于的sets集合
    int dp[MAXN][MAXN]= {1};                          //dp[i][j]:在前i个集合中选择j个好人的方案数
    for(int i=1; i<=tot; i++)             //枚举每个集合
      for(int j=0; j<=p+q; j++)           //枚举j
      {
        if(j-tag[i][0]>=0 && dp[i-1][j-tag[i][0]])//如果可以添加这1类
        {
          dp[i][j]+=dp[i-1][j-tag[i][0]];
          path[i][j]=tag[i][0];           //数组记录路径，即选的是1还是0
        }
        if(j-tag[i][1]>=0 && dp[i-1][j-tag[i][1]])
        {
          dp[i][j]+=dp[i-1][j-tag[i][1]];
          path[i][j]=tag[i][1];
        }
      }
    if(dp[tot][p]!=1)                     //如果找到的方案数不唯一
      printf("no\n");
    else
    {
      for(int i=tot,j=p; j>0 && i>0; i--) //倒推出标记路径
      {
        if(path[i][j]==tag[i][0])
          man[i][0]=1;
        else
          man[i][1]=1;
        j-=path[i][j];
      }
      for(int i=1; i<=p+q; i++)
        if(man[sets[Find(i)]][Rank[i]])
          printf("%d\n", i);
      printf("end\n");
    }
  }
  return 0;
}
