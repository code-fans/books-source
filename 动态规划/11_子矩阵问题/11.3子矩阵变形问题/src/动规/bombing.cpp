//�Ӿ���������⣭����
#include <bits/stdc++.h>
using namespace std;

int s[1001][1001];

int main()
{
  freopen("bombing.in","r",stdin);
  freopen("bombing.out","w",stdout);
  int m,n,h,w,a,Max=-INT_MAX;
  cin>>m>>n>>w>>h;
  for(int i=1; i<=m; ++i)
    for(int j=1; j<=n; ++j)
    {
      cin>>a;
      s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a;
    }
  for(int i=1; i<=m-w+1; ++i)                     //�����ΪW*H�ľ���֮��
    for(int j=1; j<=n-h+1; ++j)
      Max=max(Max,s[i+w-1][j+h-1]-s[i-1][j+h-1]-s[i+w-1][j-1]+s[i-1][j-1]);
  cout<<Max<<endl;
  return 0;
}
