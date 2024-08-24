//一元三次方程－二分法
#include <bits/stdc++.h>
using namespace std;

double a,b,c,d;
double ans[4];
int n;

double Fun(double x)          //代入x求方程根
{
  return ((a*x+b)*x+c)*x+d;
}

void Calc(double l,double r)  //二分查找解
{
  if(n>2 || l>r || (Fun(l)*Fun(r)>0 && r-l<1))
    return ;                  //找到全部解或此区间无解退出
  double mid=(l+r)/2;
  if(fabs(Fun(mid))<=1e-4)    //找到一个解
  {
    ans[++n]=mid;             //依次存入解
    Calc(l,mid-1);            //根与根之差的绝对值≥1
    Calc(mid+1,r);
  }
  else
  {
    Calc(l,mid);
    Calc(mid,r);
  }
}

int main()
{
  freopen("equation.in","r",stdin);
  freopen("equation.out","w",stdout);
  cin>>a>>b>>c>>d;
  Calc(-100,100);
  sort(ans+1,ans+4);          //三个根从小到大排序
  cout<<setprecision(2)<<fixed<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<'\n';
  return 0;
}
