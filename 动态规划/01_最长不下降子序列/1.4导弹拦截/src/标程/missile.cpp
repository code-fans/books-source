//导弹拦截
#include <bits/stdc++.h>
using namespace std;
const int N=10001;
int f[N],a[N];

int main()
{
  //freopen("missile.in","r",stdin);
  //freopen("missile.out","w",stdout);
  int n=1,ans1=0,ans2=0;
  for(; scanf("%d",&a[n])!=EOF; n++);
  for(int i=1; i<n; i++)                 //第一问，反向LIS
  {
    f[i]=1;
    for(int j=1; j<=i; j++)
      if(a[i]<a[j] && f[i]<f[j]+1)
        f[i]=f[j]+1;
    ans1=max(f[i],ans1);
  }
  memset(f,0,sizeof(f));                 //数组各元素初始化为0
  for(int i=1; i<=n; i++)                //第二问,LIS
  {
    f[i]=1;
    for(int j=1; j<=i; j++)
      if(a[i]>a[j] && f[i]<f[j]+1)
        f[i]=f[j]+1;
    ans2=max(f[i],ans2);
  }
  printf("%d %d\n",ans1,ans2);
  return 0;
}

