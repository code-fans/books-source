//数字三角形 - 记忆化递归搜索
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100;

int a[MAXN][MAXN],N,used[MAXN][MAXN];

int Fun(int i,int j)
{
  if (i==N-1)
    return a[i][j];
  if (used[i][j])          //如果已有值，直接返回值
    return used[i][j];
  used[i][j]=max(Fun(i+1,j),Fun(i+1,j+1))+a[i][j];
  return used[i][j];
}

int main()
{
  freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout);
  scanf("%d",&N);
  for (int i=0; i<N; i++)
    for (int j=0; j<=i; j++)
      scanf("%d",&a[i][j]);
  printf("%d\n",Fun(0,0));
  return 0;
}

