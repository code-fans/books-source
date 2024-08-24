//递增
//直接求最长上升序列是不对的,例如2 3 4 4 4 5
//最长上升序列为2,3,4,5,只需要修改2个,但实际要修改3个数
//方法是将a[i]-i,如上面为2，2，2，1，0，0
//求非递减序列,因为a[i]<a[i+1]，且a[i],a[i+1]都是整数，
//所以有a[i+1]-1>=a[i]，整理得a[i+1]-(i+1)>=a[i]-i。(这就是元素值-下标的差)
//这样做到第i个位置最少要比i+1个位置少1，而i最少要比i+2的位置少2，
//这样的话，直接处理好了所有的位置关系
//令b[i]=a[i]-i。则可以求出b[i]的最长不下降子序列的长度len，
//最后用n-len即为需要改变的最少的元素个数。
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;

int T,n,m;
int a[N],b[N];
int cas=1;

int Solve(int n)
{
  int longest=1;
  b[0]=a[0];
  for(int i=1; i<n; i++)
    if(a[i]>=b[longest-1])
      b[longest++]=a[i];
    else
    {
      int pos=upper_bound(b,b+longest,a[i])-b;
      b[pos]=a[i];
    }
  return longest;
}

int main()
{
  freopen("increase.in","r",stdin);
  freopen("increase.out","w",stdout);
  for(scanf("%d",&T); T; T--)
  {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
      scanf("%d",&a[i]);
      a[i]-=i;
    }
    printf("Case #%d:\n%d\n",cas++,n-Solve(n));
  }
  return 0;
}

