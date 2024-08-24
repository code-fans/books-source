//¾ù·ÖÖ½ÅÆ
#include <bits/stdc++.h>
using namespace std;

int a[101];

int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  int n,sum=0;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  int ave=sum/n;
  int count=0;
  for(int i=1; i<=n-1; i++)
    if(a[i]!=ave)
    {
      a[i+1]+=a[i]-ave;
      count++;
    }
  printf("%d\n",count);
  return 0;
}
