//传球游戏 - 组合公式法
#include <bits/stdc++.h>
using namespace std;

int m, n,Sum;

int C(int m, int n)                //计算C(m,i),公式为C(m,n)=m!/(n!(m-n)!)
{
  if (n == 0)                      //如果只取一个，方案数为1
    return 1;
  int Ans = 1;
  /*
  for (int i=m; i>=m-n+1;i--)//如5取3，则根据乘法原理先计算5*4*3的值
    Ans = Ans * i;
  for (int i=n; i>=2;i--)//除去相同排列，如123,132,321,312,213,231算一种
    Ans = Ans / i;
  */
  int p1 = 2;
  for(int p2=m; p2>=m-n+1; p2--)   //m!消去(m-n)!所以循环到m-n+1
  {
    Ans *= p2;
    if (Ans % p1 == 0 && p1<=n)    //分子整除n!
      Ans/=p1++;
  }
  return Ans;
}

int main()
{
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int i = 0; i <= m; i++)
  {
    int j = m - i;
    if (abs(j - i) % n == 0)       //如果球能传回起始点
      Sum+=C(m, i);
  }
  printf("%d\n",Sum);
  return 0;
}

