//·é»ð´«µÝ»ØËÝËã·¨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,k,num,n,m,sum,Min=100000;
  int a[121],d[121];
  cin>>n>>m;
  memset(d,0,sizeof(d));
  for(i=1; i<=n; i++)
    cin>>a[i];
  num=sum=0;
  k=0;
  while(k>=0)
  {
    d[k]++;
    if(num>=n-m+1)
    {
      if(sum<Min)
        Min=sum;
      sum-=a[num];
      d[k]=0;
      k--;
      num-=d[k];
    }
    else
    {
      if(sum>=Min)
      {
        d[k]=0;
        sum-=a[num];
        k--;
        num-=d[k];
      }
      else if(d[k]<=m)
      {
        num+=d[k];
        sum+=a[num];
        k++;
      }
      else
      {
        sum-=a[num];
        d[k]=0;
        k--;
        num-=d[k];
      }
    }
  }
  cout<<Min<<endl;
  return 0;
}

