//情感理论
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll st[100100],a[100100],sum[100100];                 //st:堆栈存下标，sum:前缀和
int n,top,l,r;

int main()
{
  freopen("feel.in","r",stdin);
  freopen("feel.out","w",stdout);
  scanf("%d", &n);
  for (int i=1; i<=n; i++)                           //从下标1开始保存
  {
    scanf("%lld", &a[i]);
    sum[i]=sum[i-1]+a[i];
  }
  a[n+1]=-1;                                         //最后-1保证全部出栈 
  ll tmp,ans=-1;
  for (int i=1; i<=n+1; i++)
  {
    for(; top!=0 && a[st[top]]>a[i]; top--)          //维护单调栈
    {
      tmp=(sum[i-1]-sum[st[top-1]])*a[st[top]]; //因为之前比它大的都弹出去了,所以左边的值就是第一个比它小的下标 
      if(tmp>ans)
      {
        ans=tmp;
        l=st[top-1]+1;                          //那么第一个比它小的下标的右边一个不就是左边界吗？            
        r=i-1;
      }
    }
    st[++top]=i;                                //所以现在入栈的值入栈,存下标
  }
  printf("%lld\n%d %d\n",ans,l,r);
  return 0;
}
