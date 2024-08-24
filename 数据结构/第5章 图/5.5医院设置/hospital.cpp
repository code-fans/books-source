//医院设置
#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int a[101][101],b[101];                     //用邻接矩阵a[][]保存

int main()
{
  freopen("hospital.in","r",stdin);
  freopen("hospital.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      a[i][j]=INF;
  for(int i=1; i<=n; i++)
  {
    a[i][i]=0;
    int left,right;
    cin>>b[i]>>left>>right;
    if(left)
      a[i][left]=a[left][i]=1;
    if(right)
      a[i][right]=a[right][i]=1;
  }

  for(int k=1; k<=n; k++)                   //Floyd
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if(a[i][j]>a[i][k]+a[k][j])
          a[i][j]=a[i][k]+a[k][j];

  int minn=INF;
  for(int i=1; i<=n; i++)
  {
    int sum=0;
    for(int j=1; j<=n; j++)
      sum+=a[i][j]*b[j];
    if(sum<minn)
      minn=sum;
  }
  cout<<minn<<endl;
  return 0;
}

