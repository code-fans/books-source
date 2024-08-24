//预算
#include<bits/stdc++.h>
using namespace std;

double d[10],p[10];
double d1,c,d2,oil,go,ans;   //oil:油箱中的油量，go:行走里程
int n,now;                   //now:当前位置

int main()
{
//  //freopen("budget.in","r",stdin);
//  //freopen("budget.out","w",stdout);
  cin>>d1>>c>>d2>>p[0]>>n;        //距离,油箱容量,每升油行驶距离,起点油价,油站数
  double Power=c*d2;              //Power指的是加满油最多能走的里程
  for(int i=1; i<=n; i++)
  {
    cin>>d[i]>>p[i];
    if(d[i]-d[i-1]>Power)
    {
      cout<<"No Solution\n";      //跑不到加油站，无解
      return 0;
    }
  }
  for(double cheap=1e9; go!=d1; cheap=1e9)//cheap为能找到的最便宜的油
  {
    for(int i=now+1; d[i]-go<=Power && i<=n; i++)//找到能到达的最便宜的油站
      if(p[i]<cheap)
      {
        cheap=p[i];
        now=i;
      }
    if(cheap<=p[0])               //范围内的加油站比现在的油价还便宜
    {
      ans+=((d[now]-go)/d2-oil)*p[0];//加的油刚好能到达这个加油站
      oil=(d[now]-go)/d2;
    }
    else if(d1-go>Power)          //范围内的加油站都比现在的油价贵，且无法一次到达终点
    {
      ans+=(c-oil)*p[0];          //在现在这个最便宜的加油站加满
      oil=c;
    }
    else                          //范围内的加油站比现在的油价贵，但能一次到达终点
    {
      ans+=((d1-go)/d2-oil)*p[0]; //开到终点
      break;
    }
    oil-=(d[now]-go)/d2;          //更新油量
    go=d[now];                    //走到d[now]
    p[0]=cheap;
  }
  printf("%.2lf\n",ans);
  return 0;
}
