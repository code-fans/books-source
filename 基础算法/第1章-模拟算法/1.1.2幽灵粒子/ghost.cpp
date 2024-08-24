//幽灵粒子
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ////freopen("ghost.in","r",stdin);
  ////freopen("ghost.out","w",stdout);
  int n,L,Max=0,Min=0;
  scanf("%d%d",&n,&L);
  for(int i=1,temp; i<=n; i++)
  {
    scanf("%d",&temp);
    Max=max(Max,max(L-temp+1,temp));//对面碰到和对穿一样的
    Min=max(Min,min(L-temp+1,temp));//所以比较距左右两端距离就可以了
  }
  printf("%d %d\n",Min,Max);
  return 0;
}

