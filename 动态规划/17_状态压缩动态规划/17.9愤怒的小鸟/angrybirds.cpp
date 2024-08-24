//愤怒的小鸟
#include <bits/stdc++.h>
using namespace std;

double x[20],y[20];               //猪的坐标
int Bird[405],f[1048580];

int main()
{
  //freopen("angrybirds.in","r",stdin);
  //freopen("angrybirds.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m,cnt=0;                 //cnt统计方程数量
    memset(Bird,0,sizeof(Bird));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
      scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1; i<=n; ++i)        //枚举所有的抛物线
      for(int j=i+1; j<=n; ++j)
        if(x[i]!=x[j])             //优化：x值相同的两坐标不可能在同一抛物线上
        {
          double a=(x[i]*y[j]-x[j]*y[i])/(x[j]*x[i]*x[j]-x[j]*x[i]*x[i]);
          double b=(x[i]*y[j]*x[i]-x[j]*x[j]*y[i])/(x[j]*x[i]*x[i]-x[j]*x[j]*x[i]);
          if(a<0)
          {
            ++cnt;                 //方程数加一
            for(int k=1; k<=n; ++k)
              if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<1e-6)//如可以消灭第k只猪
                Bird[cnt]+=1<<k-1;
          }
        }
    memset(f,0x3f,sizeof(f));     //f[i]表示达到i状态需要的最少方程数
    f[0]=0;
    for(int i=0; i<(1<<n); ++i)   //从小到大枚举每个状态
    {
      for(int j=1; j<=cnt; ++j)   //枚举方程
        f[i|Bird[j]]=min(f[i]+1,f[i|Bird[j]]);
      for(int j=1,t=1; j<=n; t=1<<j,++j)//枚举下一只猪
        f[i|t]=min(f[i]+1,f[i|t]);
    }
    printf("%d\n",f[(1<<n)-1]);
  }
  return 0;
}

