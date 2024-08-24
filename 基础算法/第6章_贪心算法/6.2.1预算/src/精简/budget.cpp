#include<bits/stdc++.h>
using namespace std;

double d1,c,d2,oil,ans;	//oil:剩下的油量 ans:最小费用 其他变量均为输出数据
double d[10],p[10];
int n,j;

int main()
{
  freopen("budget.in","r",stdin);
  freopen("budget.out","w",stdout);
  cin>>d1>>c>>d2>>p[0]>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>d[i]>>p[i];
    if(d[i]-d[i-1]>c*d2)
    {
      cout<<"No Solution\n";
      return 0;
    }
  }
  d[n+1]=d1;
  for(int i=0; i<=n; i=j)               //i为当前出发点
  {
    for(j=i+1; d[j]-d[i]<=c*d2 && j<=n+1; j++)
      if(p[j]<p[i]) 		            //有找到更便宜的加油站
      {
        ans+=((d[j]-d[i])/d2-oil)*p[i]; //加刚好足够到达第j个加油站的油
        oil=0;
        break;
      }
    if(d[j]-d[i]>c*d2)                  //没找到更便宜的加油站，当前油价最便宜
    {
      ans+=(c-oil)*p[i];			    //加满油箱尽量开
      oil=c-(d[--j]-d[i])/d2;           //开到j处剩下的油 
    }
  }
  printf("%.2lf\n",ans);
  return 0;
}
