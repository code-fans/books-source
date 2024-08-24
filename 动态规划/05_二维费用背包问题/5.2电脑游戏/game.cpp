//game
#include <bits/stdc++.h>
using namespace std;
int f[200][200];

int main()
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int n,m,k,s;
  int a[105],b[105];
  while(~scanf("%d%d%d%d",&n,&m,&k,&s))
  {
    memset(f,0,sizeof(f));
    for(int i=1; i<=k; i++)
      scanf("%d%d",&a[i],&b[i]);
    for(int i=1; i<=k; i++)                      //遍历每个物品（怪物）
      for(int v=1; v<=s; v++)                    //怪物可以无限刷，为完全背包
        for(int u=b[i]; u<=m; u++)               //遍历容忍度
          f[v][u]=max(f[v][u],f[v-1][u-b[i]]+a[i]);
    int flag=-1;
    for(int u=0; u<=m; u++)                      //先遍历忍耐度,因为忍耐度是先决条件
      for(int v=1; v<=s; v++)                    //再遍历杀怪数
        if(f[v][u]>=n)                           //如果可能升级
        {
          flag=m-u;
          u=m+1;
          break;
        }
    printf("%d\n",flag);
  }
  return 0;
}

