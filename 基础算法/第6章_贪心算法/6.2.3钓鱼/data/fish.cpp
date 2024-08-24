//钓鱼
#include <bits/stdc++.h>
using namespace std;

int n,h;
int fish[30],d[30],WalkTime[30];    //WalkTime[i]为走到i池塘花费的时间

struct LAKE
{
  int max;                           //保存钓鱼的总数
  int tim[30];
} lake[30];

int GetMax(int p[], int i, int j)    //返回数组p中最大数的编号
{
  int Max=p[i], loc=i;
  for(int m=i+1; m<=j; m++)
    if(Max<p[m])
    {
      Max=p[m];
      loc=m;
    }
  return loc;
}

void GetFish(int T)
{
  for(int i=1; i<=n; i++)            //结构体数组初始化
  {
    lake[i].max=0;
    memset(lake[i].tim,0,sizeof(lake[i].tim));
  }
  int f[30];                         //保存fish数组的值,以便修改
  for(int i=1; i<=n; i++)            //枚举最后走到i池塘的情况
  {
    int RealTime=T-WalkTime[i];      //除去走路，能钓鱼的真正时间
    int FishTime=0;                  //实际钓鱼时间初始为0
    for(int j=1; j<=i; j++)
      f[j]=fish[j];                  //将fish数组的值拷贝到f数组中
    while(FishTime<RealTime)         //当时间没用完时
    {
      int k=GetMax(f,1,i);           //找到1~i池塘中钓鱼量最多的编号
      lake[i].max+=f[k];             //更新钓鱼总量
      lake[i].tim[k]+=5;             //停在k湖的时间增加一个单位时间
      f[k]>=d[k]?f[k]-=d[k]:f[k]=0;  //更新第k个湖在下一时间能钓到的鱼
      FishTime+=5;                   //时间增加一个单位时间
    }
  }
  for(int i=1; i<=n; i++)
    f[i]=lake[i].max;
  int loc=GetMax(f,1,n);             //找到最优解下标
  for(int i=1; i<=n; i++)
    printf("%d%s",lake[loc].tim[i],i==n?"\n":", ");
  printf("Number of fish expected: %d\n\n", lake[loc].max);
}

int main()
{
  //freopen("fish.in","r",stdin);
  //freopen("fish.out","w",stdout);
  while(scanf("%d", &n) && n)
  {
    scanf("%d", &h);
    for(int i=1; i<=n; i++)
      scanf("%d", &fish[i]);
    for(int i=1; i<=n; i++)
      scanf("%d", &d[i]);
    for(int i=2,t; i<=n; i++)
    {
      scanf("%d", &t);
      WalkTime[i]=WalkTime[i-1]+5*t;  //预处理走到第i个池塘花费的时间
    }
    GetFish(h*60);
  }
  return 0;
}

