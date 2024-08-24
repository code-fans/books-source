#include <bits/stdc++.h>
using namespace std;
int pos[100005],n;//pos记录元素在序列中的原始位置
long long Stack[100005],sum[100005];

int main()
{
  //freopen("feel.in","r",stdin);
  //freopen("feel.out","w",stdout);
  int i,s=0,t=0,top=0;
  long long a,ans=0;
  scanf("%d",&n);
  for (i=1; i<=n ; i++ )
  {
    scanf("%lld",&a);
    sum[i]=sum[i-1]+a;                            //求序列和
    while (top && a<=Stack[top])                  //栈未空且新元素比栈元素小
    {
      if (ans<(sum[i-1]-sum[pos[top-1]])*Stack[top])
      {
        ans=(sum[i-1]-sum[pos[top-1]])*Stack[top];//更新结果
        s=pos[top-1]+1;                           //确定左边界
        t=i-1;                                    //确定右边界
      }
      top--;//出栈
    }
    top++;
    Stack[top]=a;                                 //入栈
    pos[top]=i;                                   //记录其原始位置
  }
  while (top)                                     //统计栈中剩余的元素
  {
    if (ans<=(sum[n]-sum[pos[top-1]])*Stack[top])//必须是<=才行，为什么？
    {
      ans=(sum[n]-sum[pos[top-1]])*Stack[top];
      s=pos[top-1]+1;
      t=n;
    }
    top--;
  }
  printf("%lld\n%d %d\n",ans,s,t);
  return 0;
}

