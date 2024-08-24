//烽火传递
#include <bits/stdc++.h>
using namespace std;

int head,tail;                          //队首指针和队尾指针
int q[1000010],w[1000010],f[1000010];   //数组模拟队列（也可用STL容器）

int main()
{
  //freopen("balefire.in","r",stdin);
  //freopen("balefire.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for (int i=1; i<=n; ++i)
    scanf("%d",&w[i]);
  for (int i=1; i<=n; ++i)
  {
    while (q[head]<i-m && head<=tail)    //维护区间大小，当队列不为空时
      head++;                            //队首指针后移，即队首元素出队
    f[i]=f[q[head]]+w[i];                //取最小值，即队首的元素值
    while (f[q[tail]]>f[i] && head<=tail)//维护单调性
      tail--;                            //队尾弹出影响单调性的值
    q[++tail]=i;                         //烽火台序号入队
  }
  int ans=0x7fffffff;
  for (int i=n-m+1; i<=n; ++i)
    ans=min(ans,f[i]);
  printf("%d\n",ans);
}

