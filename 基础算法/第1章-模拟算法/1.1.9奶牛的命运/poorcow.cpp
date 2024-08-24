//奶牛的命运—Multiset优化
#include <bits/stdc++.h>
using namespace std;

int GCD(int m,int n)
{
  return n==0?m:GCD(n,m%n);
}

inline int Read(int x=0)                 //以字符串形式读入数字可提速
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
  return x;
}

int main()
{
  freopen("poorcow.in","r",stdin);
  freopen("poorcow.out","w",stdout);
  int n,T=Read();
  while(T--)
  {
    cin>>n;
    multiset <pair<int ,int> >cow[11][11];//pair保存产奶量和牛的编号
    int Milk[1001][11]= {0};
    int Zq[11]= {0};               //Zq[i]表示有周期为i的牛
    for(int i=1,zq; i<=n; i++)
    {
      zq=Read();
      Zq[zq]=1;//标示这个周期
      for(int j=1,m; j<=zq; j++)
      {
        Milk[i][j]=Read();
        cow[zq][j].insert(make_pair(Milk[i][j],i));
      }
    }
    int count=1;
    for(int i=1; i<10; i++)       //求所有周期的最小公倍数
      if(Zq[i])                   //如果有这个周期
        count=count*i/GCD(count,i);
    int last = 0, cnt = n;
    count<<=1;                    //天数为两倍的最小公倍数
    for(int k=1; k<=count && cnt!=0; k++)
    {
      int Minpos = -1,MinI=-1, Min = 0x7FFFFFFF;
      for(int i=1; i<=10; i++)    //枚举10个周期的牛群
      {
        int j=(k-1)%i+1;
        if(Zq[i] && cow[i][j].size()>0)
        {
          multiset<pair<int ,int> >::iterator ii=cow[i][j].begin();
          if((*ii).first<Min )    //更新最少产奶量的牛
          {
            Minpos=(*ii).second;//编号
            Min=(*ii).first;//产量
            MinI=i;//周期
            if(cow[i][j].size()>1) //同周期的牛群中，最少产奶量相同的可能有多头
            {
              ii++;
              if((*ii).first==Min)
                Minpos=-1;
            }
          }
          else if((*ii).first==Min)//其它周期的牛群中有相同最少产奶量的牛
            Minpos=-1;
        }
      }
      if(Minpos!=-1)               //找到了当天产奶量最少的唯一一头牛
      {
        last=k;
        for(int i=1; i<=MinI; i++) //删除产量最少的牛
          cow[MinI][i].erase(cow[MinI][i].find(make_pair(Milk[Minpos][i],Minpos)));
        cnt--;
      }
    }
    printf("%d %d\n", cnt,last);
  }
  return 0;
}

