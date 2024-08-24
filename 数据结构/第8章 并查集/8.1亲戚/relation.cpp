//亲戚
#include <bits/stdc++.h>
using namespace std;

int father[20001];
int n,m,q,x,y;

int Find(int x)
{
  while(father[x]!=x)
    x=father[x];        //路径压缩
  return x;
}

void Union(int X,int Y)//合并两个集合
{
  father[Y]=X;
}

int main()
{
  //freopen("relation.in","r",stdin);
  //freopen("relation.out","w",stdout);
  cin>>n>>m>>q;
  for(int i=1; i<=n; i++) //初始化
    father[i]=i;//建立新的集合，其仅有的成员是i
  for(int i=1; i<=m; i++)
  {
    scanf("%d%d",&x,&y);
    int X=Find(x);
    int Y=Find(y);
    if(X!=Y)
      Union(X,Y);
  }
  for(int i=1; i<=q; i++)
  {
    scanf("%d%d",&x,&y);
    printf("%s\n",Find(x)==Find(y)?"YES":"NO");
  }
  return 0;
}
