//Ѱ�ҽ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("tower.in","r",stdin);
  //freopen("tower.out","w",stdout);
  int n;
  cin>>n;
  int a[n+1][n+1];
  int f[n+1][n+1];
  for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++)
      cin>>a[i][j];
  f[1][1]=a[1][1];                                 //�Դ�Ϊ���
  for(int i=2; i<=n; i++)
  {
    for(int j=2; j<i; j++)
      f[i][j]=min(f[i-1][j-1],f[i-1][j])+a[i][j];  //������һ�㵽��һ�����̾���
    f[i][1]=min(f[i-1][i-1],f[i-1][1])+a[i][1];
    f[i][i]=min(f[i-1][i-1],f[i-1][1])+a[i][i];    //�ر��
    for(int j=2; j<=i; j++)
      f[i][j]=min(f[i][j],f[i][j-1]+a[i][j]);      //�����Ҽ���ͬһ����̾���
    f[i][1]=min(f[i][1],f[i][i]+a[i][1]);
    for(int j=i-1; j>=1; j--)
      f[i][j]=min(f[i][j],f[i][j+1]+a[i][j]);
    f[i][i]=min(f[i][i],f[i][1]+a[i][i]);          //���ҵ������ͬһ����̾���
  }
  cout<<f[n][1]<<endl;
  return 0;
}
