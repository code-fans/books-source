//������-λ���㷨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  int n,t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    if((n&(n-1))==0)//"=="��"&"���ȼ���
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}

