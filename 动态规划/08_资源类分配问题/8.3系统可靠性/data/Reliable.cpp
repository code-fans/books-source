//ϵͳ�ɿ���
#include<bits/stdc++.h>
using namespace std;
#define N 110

double M;
double f[N][N],p[N][N];
int cost[N];

int main()
{
  //freopen("Reliable.in","r",stdin);
  //freopen("Reliable.out","w",stdout);
  int n,c;
  scanf("%d%d",&n,&c);
  for(int i=1; i<=n; i++)
  {
    cin>>cost[i];
    for(int j=0; j*cost[i]<=c; j++)
      scanf("%lf",&p[i][j]);
  }
  for(int j=0; j<=c; j++)
    f[0][j]=1;
  for(int i=1; i<=n; i++)                   //ö�ٲ���
    for(int j=0; j<=c; j++)                 //ö��Ǯ��
      for(int k=0; k<=j; k++)               //ö���и��
        f[i][j]=max(f[i][j],f[i-1][k]*p[i][(j-k)/cost[i]]);
  printf("%.4lf\n",f[n][c]);
  return 0;
}

