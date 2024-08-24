//田忌赛马 - 动规法
#include <bits/stdc++.h>
using namespace std;

int tian[1001],king[1001];
int f[1001][1001];

int S(int i, int j)                      //得分
{
  if(tian[i]==king[j])
    return 0;
  return (tian[i]>king[j]?1:-1);
}

void Init(int n)
{
  memset(f,0,sizeof(f));
  for(int i=1; i<=n; i++)                //设置f[i][0]
    if(tian[i]>king[i])                  //因未用最慢的马，
      f[i][0]=f[i-1][0]+1;               //那必是依次用最快的马
    else if(tian[i]<king[i])
      f[i][0]=f[i-1][0]-1;
    else
      f[i][0]=f[i-1][0];                 //若相等就使用前一次的最优值
  for(int j=n,g=1; j>=1; j--,g++)        //设置f[i][i]
    if(tian[j]>king[g])                  //这说明田忌每一次都用最慢的马
      f[g][g]=f[g-1][g-1]+1;
    else if(tian[j]<king[g])
      f[g][g]=f[g-1][g-1]-1;
    else
      f[g][g]=f[g-1][g-1];
}

int main()
{
  freopen("horse.in","r",stdin);
  freopen("horse.out","w",stdout);
  for(int n; scanf("%d",&n) && n;)
  {
    for(int i=1; i<=n; i++)
      scanf("%d",&tian[i]);
    for(int x=1; x<=n; x++)
      scanf("%d",&king[x]);
    sort(tian+1,tian+n+1,greater<int>());//由大到小排序
    sort(king+1,king+n+1,greater<int>());
    Init(n);
    for(int j=2; j<=n; j++)              //动态规划递推关系
      for(int k=1; k<j; k++)
        f[j][k]=max((f[j-1][k-1]+S(n-k+1,j)),(f[j-1][k]+S(j-k,j)));
    int Max = f[n][0];
    for(int i=1; i<=n; ++i)              //找到最大收益
      if(f[n][i]>Max)
        Max=f[n][i];
    printf("%d\n",Max*200);
  }
}

