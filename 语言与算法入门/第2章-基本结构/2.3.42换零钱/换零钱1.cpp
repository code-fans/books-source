//»»ÁãÇ®»ù±¾Ëã·¨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,j,k,count=0;
  for(i=1; i<=9; i++)
    for(j=1; j<=17; j++)
      for(k=1; k<=85; k++)
        if((i*10+j*5+k)==100)
          count++;
  cout<<count<<endl;
  return 0;
}

