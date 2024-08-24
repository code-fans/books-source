#include <bits/stdc++.h>
using namespace std;

void Sub(int s[])
{
  static int t=0;
  s[t]++;
  t++;
}

int main()
{
  int a[]= {1,2,3,4},i;
  for(i=0; i<4; i++)
    Sub(a);
  for(i=0; i<4; i++)
    cout<<a[i]<<" ";
  return 0;
}

