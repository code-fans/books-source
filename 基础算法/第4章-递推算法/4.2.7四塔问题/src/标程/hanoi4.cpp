//ËÄËşÎÊÌâ
#include <bits/stdc++.h>
using namespace std;

int ans[50001]= {0,1},i,d=2,t=2,r=2;

int main()
{
  freopen("hanoi4.in","r",stdin);
  freopen("hanoi4.out","w",stdout);
  for(i=2; i<=50000; i++)
  {
    ans[i]=(ans[i-1]+d)%10000;
    if(r>1)
      r--;
    else
    {
      d=(d<<1)%10000;
      t++;
      r=t;
    }
  }
  scanf("%d",&i);
  printf("%d\n",ans[i]);
  return 0;
}

