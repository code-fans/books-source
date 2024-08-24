//信息共享 -方法2
#include <bits/stdc++.h>
using namespace std;

bool a[255];                         //统计每个点的入度

int main()
{
  //freopen("Msg.in","r",stdin);
  //freopen("Msg.out","w",stdout);
  int n,x,ans=0;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&x);
    while(x)                         //读取该行数据直到0
    {
      a[x]=true;                     //入度为真,说明会有人传递资料给x
      scanf("%d",&x);
    }
  }
  for(int i=1; i<=n; i++)
    if(!a[i])                        //如果入度为0,答案加1
      ans++;
  printf("%d\n",ans==0?1:ans);
  return 0;
}

