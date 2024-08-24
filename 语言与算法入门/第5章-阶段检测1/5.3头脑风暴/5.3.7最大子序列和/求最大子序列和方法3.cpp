//求最大子序列和 - 方法3
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,Min,MaxN,s[35005]= {0},a[35005]= {0},ma=-2147483647;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    if(ma<=a[i])
      ma=a[i];
  }
  Min=a[1];                    //注意此处
  MaxN=a[1];
  for(int j=1; j<=n; j++)
  {
    if(s[j]<Min)
      Min=s[j];
    if(s[j]-Min>MaxN)
      MaxN=s[j]-Min;
  }
  if(!MaxN)
    printf("%d\n",ma);
  else
    printf("%d\n",MaxN);
  return 0;
}

