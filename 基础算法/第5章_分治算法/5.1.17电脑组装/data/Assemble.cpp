//电脑组装
//排序+二分，输入不要一个字符一个字符处理，排序的时候尽量避免字符串比较，
//把“种类”的字符串映射成整数
//对每一类组件按照质量从小到大排序，然后二分答案quality，
//每一种组件中选一个品质不低于quality的最便宜的，跟预算比较即可。
#include <bits/stdc++.h>
using namespace std;

struct computer
{
  int type,price,quality;
} d[1005];

int have[1005],n,budget,t,Count;

int Cmp(computer a,computer b)
{
  return a.quality<b.quality;
}

int Judge(int middle)
{
  memset(have,-1,sizeof(have));
  for(int i=middle; i<n; i++)        //从满足middle质量的开始选
  {
    if(have[d[i].type]==-1)          //如果该类型还没有统计
      have[d[i].type]=d[i].price;    //则添加该类型的一个组件的价值
    else if(have[d[i].type]>d[i].price)
      have[d[i].type]=d[i].price;    //选取部件选给定quality的最便宜的部件
  }
  int sum=0;
  for(int i=0; i<Count; i++)         //看是否所有类型都选上
    if(have[i]==-1)                  //若有没选的，则失败
      return 0;
    else
      sum+=have[i];                  //否则累加
  return sum>budget?0:1;             //若超过预算，失败
}

int Binary(int left,int right)       //按质量二分
{
  while(left<right)
  {
    int middle=(left+right+1)>>1;    //要加1，否则遇到8,9就成死循环
    Judge(middle)?left=middle:right=middle-1;
  }
  return d[left].quality;
}

int main()
{
  //freopen("Assemble.in","r",stdin);
  //freopen("Assemble.out","w",stdout);
  char a[25];
  for(cin>>t; t; t--)
  {
    Count=0;
    scanf("%d%d",&n,&budget);        //组件数，预算
    map<string,int> MAP;             //将string映射为数字
    for(int i=0; i<n; i++)
    {
      string type,name;              //名称是没有用的
      cin>>type>>name>>d[i].price>>d[i].quality;
      if(MAP.find(type)==MAP.end())     //如果该类型还没有
        MAP[type]=Count++;           //该类别映射为某个数字
      d[i].type=MAP[type];           //标记归类
    }
    sort(d,d+n,Cmp);                 //按质量排序
    cout<<Binary(0,n-1)<<endl;
  }
  return 0;
}
