//�ӷֶ�����
#include <bits/stdc++.h>
using namespace std;

long long f[35][35];
int root[35][35];                            //root[x][y]����x,y����ĸ����

void Out(int x,int y)                        //�ݹ����
{
  if(x<=y)
  {
    printf("%d ",root[x][y]);
    Out(x,root[x][y]-1);
    Out(root[x][y]+1,y);
  }
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      f[i][j]=1,root[i][i]=i;
  for(int i=1; i<=n; i++)
    scanf("%d",&f[i][i]);
  for(int i=n; i>=1; i--)                          //i�ݼ��Կ������䷶Χ����
    for(int j=i+1; j<=n; j++)
      for(int k=i; k<=j; k++)
        if(f[i][j]<(f[i][k-1]*f[k+1][j]+f[k][k]))//����и��Ž�
        {
          f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
          root[i][j]=k;                          //��Ǹ��Ž�ĸ�
        }
  printf("%lld\n",f[1][n]);
  Out(1,n);
  return 0;
}
