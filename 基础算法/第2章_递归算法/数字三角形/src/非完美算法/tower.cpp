//数字三角形 — 非完美算法
#include <bits/stdc++.h>
using namespace std;
#define maxn 100

int a[maxn][maxn],n;

int main()
{
  srand(time(0));
  clock_t Time;
  Time=clock();                     //获取程序开始运行的时间
  scanf("%d",&n);
  for (int i=0; i<n; i++)
    for (int j=0; j<=i; j++)
      scanf("%d",&a[i][j]);

  int result=0,t=0;
  while(1)
  {
    if(t++%10==0)                   //此处调节获取时间的频率
      if(clock()-Time>950)          //如累计运行时间已接近1秒
        break;
    int j=0,v=a[0][j];
    for (int k=1; k<n; k++)
    {
      int m1=a[k][j];
      int m2=a[k][j+1];
      int p=rand()%10;
      if(m1>m2)
      {
        if (p>=4)                   //大值优先
          v+=a[k][j];
        else
          v+=a[k][++j];
      }
      else
      {
        if (p<4)
          v+=a[k][j];
        else
          v+=a[k][++j];
      }
    }
    if (v>result)
      result=v;
  }
  printf("%d\n",result);
  return 0;
}
