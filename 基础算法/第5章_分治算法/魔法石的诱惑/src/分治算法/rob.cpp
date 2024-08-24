//魔法石的诱惑 - 分治算法
#include <bits/stdc++.h>
using namespace std;

int ZeroTrail (int n)
{
  int ans = 0;
  while(n > 0)
  {
    ans+=n/5;
    n/=5;
  }
  return ans;
}

int main()
{
  //freopen("rob.in","r",stdin);
  //freopen("rob.out","w",stdout);
  int Q;
  scanf("%d", &Q);
  int start = 1;                        //左边界
  int end = 500000000;                  //右边界
  int ans = 500000001;

  while (start <= end)                  //二分查找
  {
    int mid = (end +start)>>1;
    int t = ZeroTrail (mid);            //计算末尾0的个数
    if (t == Q && mid < ans)            //如果相等且有更小的值
      ans = mid;                        //更新为最小值
    if (t >= Q)
      end = mid - 1;
    else if ( t < Q )
      start = mid + 1;
  }
  ans != 500000001 ? printf("%d\n", ans):printf("No solution\n");
  return 0;
}

