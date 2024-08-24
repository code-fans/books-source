//机器分配
#include<bits/stdc++.h>
using namespace std;

int m,n;
int f[11][16],value[11][16];

void Show(int x,int num)    //处理到第x个公司，剩num台机器没分配
{
  if (x==0)
    return;
  for (int i=0; i<=num; i++)//依次判断最优解是否是i产生的
    if (f[x][num]==f[x-1][i]+value[x][num-i])
    {
      Show(x-1,i);
      cout<<x<<' '<<num-i<<endl;
      break;                    //输出一个解就退出，以防多输出东西
    }
}

int main()
{
  freopen("machine.in","r",stdin);
  freopen("machine.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      scanf("%d",&value[i][j]);
  for(int i=1; i<=n; i++)              //枚举部门
    for(int j=1; j<=m; j++)            //枚举资源
      for(int k=0; k<=j; k++)          //枚举切割点
        f[i][j]=max(f[i-1][k]+value[i][j-k],f[i][j]);
  printf("%d\n",f[n][m]);              //输出最大盈利值
  Show(n,m);                           //输出分配情况
  return 0;
}

