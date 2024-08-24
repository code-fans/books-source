//Í£µç
#include <bits/stdc++.h>
using namespace std;
int m,n,k;

int Josephus(int m,int n,int star)
{
  int k=star;
  for(int i=1; i<=m; i++)
    k=(k+n-1)%i+1;
  return k;
}

int main()
{
  scanf("%d%d",&m,&k);
  n=2;
  while(Josephus(m,n,1)!=k)
    n++;
  printf("%d\n",n);
  return 0;
}

