//���ξ���1
#include <bits/stdc++.h>
#define N 101
using namespace std;

int main()
{
  //freopen("snake1.in","r",stdin);
  //freopen("snake1.out","w",stdout);
  int x=1,y,n,num=1;
  int a[N][N]= {0};
  cin>>n;
  y=n;
  a[x][y]=num;//��1�����һ�����һ��
  while(num<n*n)
  {
    while(x+1<=n && !a[x+1][y])//����
      a[++x][y]=++num;
    while(y-1>0 && !a[x][y-1])//����
      a[x][--y]=++num;
    while(x-1>0 && !a[x-1][y])//����
      a[--x][y]=++num;
    while(y+1<=n && !a[x][y+1])//����
      a[x][++y]=++num;
  }
  for(int i=1; i<=n; ++i) //��ӡ
  {
    for(int j=1; j<=n; ++j)
      printf("%5d",a[i][j]);
    printf("\n");
  }
  return 0;
}

