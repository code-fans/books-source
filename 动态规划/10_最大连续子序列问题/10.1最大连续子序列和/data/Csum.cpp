//求最大子序列和
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("Csum.in","r",stdin);
  //freopen("Csum.out","w",stdout);
  int n,s[100005]= {0},a[100005]= {0},MAX=-2147483647;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    MAX=max(MAX,a[i]);      //找到最大值的元素
  }
  int Min=a[1],ans=a[1];    //Min用来保存到目前为止的元素最小值
  for(int i=1; i<=n; i++)
  {
    Min=min(Min,s[i]);      //min(a,b)可得到a,b的最小值
    ans=max(ans,s[i]-Min);  //更新最大值给ans
  }
  printf("%d\n",ans?ans:MAX);//元素如果全是负数，则输出最大元素
  return 0;
}

