#include <bits/stdc++.h>
using namespace std;

int ACK(int M,int N)
{
  int v;
  if(M==0)      v=N+1;
  else if(N==0) v=ACK(M-1,1);
  else          v=ACK(M-1,ACK(M,N-1));
  return v;
}

int main()
{
  printf("%d\n",ACK(1,1));
  return 0;
}

