//广告问题
#include<bits/stdc++.h>
using namespace std;

struct Region
{
  int a,b;
} p[1010];

bool Cmp(const Region &p1,const Region &p2) //按右端排序
{
  return (p1.b < p2.b);
}

void Calc(int k,int n)
{
  set <int> s;
  sort(p,p+n,Cmp);                          //按区间右端快排
  for(int i=0; i<n; i++)                    //枚举n个区间
  {
    int ad=0;                               //ad为该区间已出现的广告个数
    for(int j=p[i].b; j>=p[i].a; j--)       //统计广告数
      if(s.find(j) != s.end())              //如果该位置有广告
        ad++;
    int len=min(p[i].b-p[i].a+1,k);         //len为区间的长度,最多为k
    if(ad>=len)                             //如广告数足够，则跳过
      continue;
    for(int j=p[i].b,cnt=0; cnt<len-ad; j--)//从后往前推,放置剩余的广告
      if(s.find(j)==s.end())                //如果该位置没有广告
      {
        s.insert(j);                        //插入新广告
        cnt++;                              //广告数++
      }
  }
  printf("%d\n",s.size());                  //输出结果
  for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
    printf("%d\n",*it);
}

int main()
{
  //freopen("ad.in","r",stdin);
  //freopen("ad.out","w",stdout);
  int t,k,n;
  for(scanf("%d",&t); t; t--)
  {
    scanf("%d %d",&k,&n);
    for(int i=0; i<n; i++)
    {
      scanf("%d %d",&p[i].a,&p[i].b);
      if(p[i].a>p[i].b)
        swap(p[i].a,p[i].b);
    }
    Calc(k,n);                              //执行核心代码
  }
  return 0;
}
