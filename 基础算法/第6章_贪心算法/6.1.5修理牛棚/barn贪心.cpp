//修理牛棚
//贪心算法，显然，当所有木板均用上时，长度最短。用上m块木板时有m-1个间隙。
//现在的目标是让总间隙最大。将相邻两个有牛的牛棚之间间隔的牛棚数排序，
//选取最大的m-1个作为间隙，其余地方用木板盖住即可。
//即总长度减去m-1个最大长度的空白
#include<bits/stdc++.h>
using namespace std;

int cow[210],gap[210];

int main()
{
  freopen("barn.in","r",stdin);
  freopen("barn.out","w",stdout);
  int m,s,c;
  scanf("%d%d%d",&m,&s,&c);     //m:木板最大数目,s:牛棚总数,c:牛的总数
  for (int i=1; i<=c; i++)
    scanf("%d",&cow[i]);
  sort(cow+1,cow+c+1);          //按编号从左到右排好牛棚
  int ans=cow[c]-cow[1]+1;      //全铺满的总长度
  for (int i=1; i<=c-1; i++)
    gap[i]=cow[i+1]-cow[i]-1;     //计算空隙的长度
  sort(gap+1,gap+c);
  for (int i=c-1; i>=c-m+1; i--)//从最大的空隙开始，共m-1块
    ans-=gap[i];
  printf("%d\n",ans);
  return 0;
}
