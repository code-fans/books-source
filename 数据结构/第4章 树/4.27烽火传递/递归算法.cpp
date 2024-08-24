//·é»ğ´«µİµİ¹éËã·¨
#include <bits/stdc++.h>
using namespace std;
int n,m;
int *v,*b;

int f(int i)
{
  int j,minxx=INT_MAX,sum;
  if(i+m>n)
    return 0;
  else if(b[i])return b[i];
  else
    for(j=i+1; j<=i+m; j++)
    {
      if(minxx>(sum=f(j)+v[j]))
        minxx=sum;
    }
  b[i]=minxx;
  return minxx;
}

int main()
{
  cin>>n>>m;
  v=new int [n+1];
  b=new int [n+1];
  for(int i=1; i<=n; i++)
  {
    cin>>v[i];
    b[i]=0;
  }
  v[0]=b[0]=0;
  cout<<f(0)<<endl;
  return 0;
}

