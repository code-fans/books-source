//穿越时空
//贪心策略是遍历每一列，把不合格的列中往右延伸最长的墙去掉
#include <bits/stdc++.h>
using namespace std;

struct Wall
{
  int y,L,R;
} wall[101];

int main()
{
  freopen("Siworae.in","r",stdin);
  freopen("Siworae.out","w",stdout);
  int t,n,k;
  for(scanf("%d",&t); t; t--)
  {
    vector<int> vec[101];
    int wall_cnt[101]= {0};
    int wall_use[101]= {0};
    int maxy=0,miny=1e9;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
      scanf("%d%d%d%d",&wall[i].L,&wall[i].y,&wall[i].R,&wall[i].y);
      if(wall[i].L>wall[i].R)
        swap(wall[i].L,wall[i].R);
      miny=min(wall[i].L,miny);                           //更新最左边界
      maxy=max(wall[i].R,maxy);                           //更新最右边界
      for(int j=wall[i].L; j<=wall[i].R; j++)
      {
        vec[j].push_back(i);                              //vector保存墙的编号
        wall_cnt[j]++;                                    //统计当前列有多少障碍
      }
      wall_use[i]=1;
    }
    int ans=0;
    for(int j=miny; j<=maxy; j++)                           //扫描每一列
      while(wall_cnt[j]>k)
      {
        int flag;
        int Max=0;
        for(int x=0; x<vec[j].size(); x++)
          if(wall[vec[j][x]].R>=Max && wall_use[vec[j][x]]>0)//找最长且没删除
          {
            flag=vec[j][x];
            Max=wall[vec[j][x]].R;
          }
        wall_use[flag]=0;                                  //标记删除
        for(int x=wall[flag].L; x<=wall[flag].R; x++)
          wall_cnt[x]--;
        ans++;
      }
    printf("%d\n",ans);
  }
  return 0;
}
