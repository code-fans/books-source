//цэт©╤тед
#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
  //freopen("key10.in","r",stdin);
  //freopen("key10.ans","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  for(int i=1; i<=n-m+1; i++)
  {
    int Max=-100000000;
    for(int j=i; j<=i+m-1; j++)
      Max=max(a[j],Max);
    cout<<Max;
  }
  printf("\n");
  return 0;
}
