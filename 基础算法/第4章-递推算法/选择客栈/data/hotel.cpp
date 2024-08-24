//选择客栈 - 优化算法1
#include <bits/stdc++.h>
using namespace std;

int n, k, price, c, v, Ans;
int a[60], f[60][200010];

int main()
{
  //freopen("hotel.in","r",stdin);
  //freopen("hotel.out","w",stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++)
  {
    scanf("%d %d", &c, &v);
    for(int j=0; j<k; j++)                 //穷举所有颜色
      f[j][i] = f[j][i-1] + (j == c);     //颜色相等则加一
    if(v <= price)                         //如饭店满足最低消费
    {
      a[i] = i;
      Ans += f[c][a[i]] - 1;
    }
    else
    {
      a[i] = a[i-1];
      Ans += f[c][a[i]];
    }
  }
  printf("%d\n", Ans);
  return 0;
}

