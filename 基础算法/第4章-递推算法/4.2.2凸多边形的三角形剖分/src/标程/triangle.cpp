//凸多边形的三角形剖分
#include <bits/stdc++.h>
using namespace std;
int  c[50];

int main()
{
  freopen("triangle.in","r",stdin);
  freopen("triangle.out","w",stdout);
  int n;
  cin>>n;
  c[2]=1;
  for(int i=3; i <= n; i ++)
    for(int k=2; k <= i-1; k ++)
      c[i]+=c[k]*c[i-k+1];
  cout<<c[n]<<endl;
  return 0;
}

