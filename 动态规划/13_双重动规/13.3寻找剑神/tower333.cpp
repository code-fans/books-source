#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;

int a[MAXN][MAXN],f[MAXN][MAXN];
int n;

int main()
{
  freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++)
      cin>>a[i][j];
  f[1][1]=a[1][1];               //终点处就直接是该点时间
  for(int i=2; i<=n; i++)        //一层一层往下推
  {
    for(int j=2; j<i; j++)       //先求出从上一层推出来的最小值
      f[i][j]=min(f[i-1][j],f[i-1][j-1])+a[i][j];
    f[i][1]=min(f[i-1][1],f[i-1][i-1])+a[i][1];//特殊边界点处理
    f[i][i]=min(f[i-1][1],f[i-1][i-1])+a[i][i];//特殊边界点处理
    //同一层更新最优解
    for(int k=i-1; k>0; k--)     //从右往左推 从右往左走的情况更新
      f[i][k]=min(f[i][k],f[i][k+1]+a[i][k]);
    f[i][i]=min(f[i][i],f[i][1]+a[i][i]);
    for(int l=2; l<=i; l++) //从左往右推 从左往右走的情况更新
      f[i][l]=min(f[i][l],f[i][l-1]+a[i][l]);
    f[i][1]=min(f[i][1],f[i][i]+a[i][1]);

    for(int k=i-1; k>0; k--) //再推一遍从右往左推 从右往左走的情况更新
      f[i][k]=min(f[i][k],f[i][k+1]+a[i][k]);
    f[i][i]=min(f[i][i],f[i][1]+a[i][i]);
    for(int l=2; l<=i; l++) //再推一遍从左往右推 从左往右走的情况更新
      f[i][l]=min(f[i][l],f[i][l-1]+a[i][l]);
    f[i][1]=min(f[i][1],f[i][i]+a[i][1]);
  }
  cout<<f[n][1]<<endl;
}
