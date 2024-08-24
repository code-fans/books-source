//理想收入问题 - 贪心算法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  double money=1,v[2];                       //滚动数组
  scanf("%d %lf",&n,&v[0]);
  for(int i=1; i<n; i++)                     //注意第一个数早已输入
  {
    scanf("%lf",&v[i&1]);
    if(v[i&1]>v[i-1&1])
      money*=v[i&1]/v[i-1&1];
  }
  printf("%.4lf\n",money);
  return 0;
}

