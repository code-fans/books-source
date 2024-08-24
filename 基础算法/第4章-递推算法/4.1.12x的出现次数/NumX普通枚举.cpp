//x的出现次数-普通枚举
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("NumX.in","r",stdin);
  //freopen("NumX.out","w",stdout);
  long long n,x,t=0;
  cin>>n>>x;
  for(int i=1; i<=n; i++)
    for(int b=i; b; b/=10)
      if(b%10==x)
        t++;
  cout<<t<<endl;
  return 0;
}
