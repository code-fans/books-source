//和为0的最长连续子序列
//先求前序和到dp[]
//例如有数组a[]:  7 -7 8 6   5 -5 -5 0 -6 11
//得前缀数组dp[]: 7  0 8 14 19 14  9 9  3 14
//dp[]中，除0外,相同dp值即14和14,9和9，这几个区间的和均为０
//而14有3个值，显然选最左边的14和最右边的14的区间
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  int n,Max=0;
  cin>>n;
  vector<int> dp(n+1);           //多定义一个0
  for (int i=1,v; i<=n; i++)
  {
    cin>>v;
    dp[i]=dp[i-1]+v;
  }
  map<int, int> m;               //dp[i]值为key,value为下标i
  for (int i=1; i<=n; i++)
    if (m[dp[i]]==0 && dp[i]!=0) //第一次出现这个值
      m[dp[i]]=i;                //将该值的下标存入map
    else                         //第二次出现或者是０
      Max=max(Max,i-m[dp[i]]);   //如果出现相同的值了，相减
  cout<<Max<<endl;
  return 0;
}
