// ’π∫’‰÷È
#include<bits/stdc++.h>
using namespace std;

int sum[101],p[101];
int F[101];

int main()
{
  int n;
  cin>>n;
  for(int i=1,a; i<=n; i++)
  {
    cin>>a>>p[i];
    sum[i]=sum[i-1]+a;
  }
  for(int i=1; i<=n; i++)
  {
    F[i]=INT_MAX;
    for(int j=0; j<i; j++)
      F[i]=min(F[i],F[j]+(sum[i]-sum[j]+10)*p[i]);
  }
  cout<<F[n]<<endl;
  return 0;
}
