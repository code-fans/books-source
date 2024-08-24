//被限制的最大连续子序列和
//普通的dp转移方程就是 dp[i] = sum[i] - min{sum[j]}  (i- m <= j <= i)
//但是这样的复杂度最坏会达到n^2，所以得优化，就用到了单调队列。
//单调队列：单调队列即保持队列中的元素单调递增（或递减）的这样一个队列，
//用单调队列来解决问题，一般都是需要得到当前的某个范围内的最小值或最大值
//插入新元素从队首插入，如果新元素比队首元素小，则大的队首元素逐个删除后再插入
//这样保证队首到队尾的元素由大到小递减，队尾的元素最小
//如果序列长度超过m,则删除队尾的元素，这样不断更新s[i]-最小数即sum[j]就可以了

#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL sum[1000010];

list<int> q;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  int n,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    while(!q.empty())            //清空队列
      q.pop_back();
    sum[0] = 0;
    for(int i=1; i<=n; i++)
    {
      scanf("%lld",&sum[i]);
      sum[i] += sum[i-1];
    }
    LL maxn = 0;
    q.push_front(0);             //保存下标,以方便计算序列长度
    for(int i=1; i<=n; i++)
    {
      while(!q.empty() && sum[q.front()] > sum[i])//递减队列,保证队尾尽量小
        q.pop_front();
      q.push_front(i);           //从队首插入新元素
      while(!q.empty() && i - q.back() > m)//如果长度已经超过m
        q.pop_back();
      maxn = max(maxn,sum[i] - sum[q.back()]);//减去最小的值（队尾）
    }
    cout << maxn << endl<<endl;
  }
  return 0;
}

