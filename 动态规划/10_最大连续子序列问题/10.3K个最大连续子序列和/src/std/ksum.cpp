//K��������������к�
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int f[11][1001];                            //ע��˴������ж������෴��

int main()
{
  //freopen("ksum.in","r",stdin);
  //freopen("ksum.out","w",stdout);
  int k,n;
  cin>>n>>k;
  for(int i=1; i<=n; ++i)
    cin>>a[i];
  for(int i=1; i<=k; ++i)
    for(int j=1; j<=n; ++j)
    {
      f[i][j]=f[i][j-1]+a[j];               //����j-1����
      for(int m=i-1; m<=j-1; ++m)           //����һ��
        f[i][j]=max(f[i-1][m]+a[j],f[i][j]);
    }
  int Max=f[k][k];
  for(int j=k; j<=n; ++j)                   //�ҳ����ֵ
    Max=max(Max,f[k][j]);
  cout<<Max<<endl;
  return 0;
}
