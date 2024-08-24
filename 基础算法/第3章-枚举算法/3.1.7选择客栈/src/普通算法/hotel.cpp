//选择客栈 - 朴素算法
#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, k, price, Ans, c[N], v[N];

int main()
{
  freopen("hotel.in","r",stdin);
  freopen("hotel.out","w",stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++)
    scanf("%d %d", c+i, v+i);                //输入数组元素c[i]
  for(int i=1; i<n; i++)
  {
    int m = v[i];
    for(int j=i+1; j<=n; j++)
    {
      if(m > v[j])                           //找出区间消费值最小的饭店
        m = v[j];
      Ans += (c[i] == c[j] && m <= price);   //如满足条件则加1
    }
  }
  printf("%d\n", Ans);
  return 0;
}

