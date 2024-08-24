//截铁丝
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  long long d[100]= {1,1};
  int total,i,sum=2;         //sum为已截的铁丝长度和，初始为2
  scanf("%d",&total);
  for(i=2; ; i++)
  {
    d[i]=d[i-1]+d[i-2];
    if(total-sum>=d[i])
      sum+=d[i];             //已经截去的铁丝总长
    else
      break;
  }
  printf("%d\n",i);
  return 0;
}

