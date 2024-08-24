//选择客栈 - 优化算法2
#include <bits/stdc++.h>
using namespace std;
const int K = 60;
int n, k, price, c, v, Ans, later;
int hotel[K], fit[K], last[K];

int main()
{
  //freopen("hotel.in","r",stdin);
  //freopen("hotel.out","w",stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++)
  {
    scanf("%d %d", &c, &v);
    if(v <= price)                       //如该饭店符合最低消费
      later = i;                         //最近符合要求的客栈later=该客栈
    if(later >= last[c])                 //如later>=存储上一个颜色为c的客栈
      fit[c] = hotel[c];                 //颜色c且符合消费的客栈数fit[c]=至今颜色为c的客栈数hotel[c]
    Ans += fit[c];
    hotel[c]++;                          //颜色为 c 的客栈数加一
    last[c] = i;                         //更新存储上一个颜色为 c 的客栈编号
  }
  printf("%d\n", Ans);
  return 0;
}

