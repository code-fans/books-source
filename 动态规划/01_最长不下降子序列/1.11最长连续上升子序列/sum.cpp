//最长连续上升子序列
//对每个数来说,左边的数要比右边的数至少小2,这样才可以拼合成一条链
//计算出左边数能连接的最长串,右边的数能连接的最长串,拼合找最优值
//即分别求以下标i元素为起始点和结束点的递增子序列长度。
//比较下标i-1和i+1位置的元素差值是否大于2，如果大于2则拼接长度。
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
int f[MaxN], a[MaxN], g[MaxN], ans, n;

inline void ReadIn(int& x)
{
  static char ch;
  while (!isdigit(ch=getchar()));
  for (x=ch-48; isdigit(ch=getchar()); (x*=10)+=ch-48);
}

int main()
{
  freopen("sum.in","r",stdin);
  freopen("sum.out","w",stdout);
  ReadIn(n);
  for (int i=0; i<n; ReadIn(a[++i]));
  for (int i=1; i<=n; ++i)                //正序求上升数列
    f[i]=(a[i-1]<a[i]) ? f[i-1]+1 : 1;
  for (int i=n; i>=1; --i)                //逆序求下降数列(正向就是上升数列)
    g[i]=(a[i]<a[i+1]) ? g[i+1]+1 : 1;
  for (int i=1; i<=n; ++i)                //拼接之后的最大值
    (a[i+1]>=a[i-1]+2) ? ans=max(ans,f[i-1]+g[i+1]+1) : 1;//左右差值为2
  printf("%d\n", ans);
  return 0;
}

