//��Խʱ��
//̰�Ĳ����Ǳ���ÿһ�У��Ѳ��ϸ�����������������ǽȥ��
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
      miny=min(wall[i].L,miny);                           //��������߽�
      maxy=max(wall[i].R,maxy);                           //�������ұ߽�
      for(int j=wall[i].L; j<=wall[i].R; j++)
      {
        vec[j].push_back(i);                              //vector����ǽ�ı��
        wall_cnt[j]++;                                    //ͳ�Ƶ�ǰ���ж����ϰ�
      }
      wall_use[i]=1;
    }
    int ans=0;
    for(int j=miny; j<=maxy; j++)                           //ɨ��ÿһ��
      while(wall_cnt[j]>k)
      {
        int flag;
        int Max=0;
        for(int x=0; x<vec[j].size(); x++)
          if(wall[vec[j][x]].R>=Max && wall_use[vec[j][x]]>0)//�����ûɾ��
          {
            flag=vec[j][x];
            Max=wall[vec[j][x]].R;
          }
        wall_use[flag]=0;                                  //���ɾ��
        for(int x=wall[flag].L; x<=wall[flag].R; x++)
          wall_cnt[x]--;
        ans++;
      }
    printf("%d\n",ans);
  }
  return 0;
}
