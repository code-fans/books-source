//极值问题 —暴力枚举
#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int n=1; n<=100; n++)
    for(int m=1; m<=100; m++)
      if((n*n-m*n-m*m)*(n*n-m*n-m*m)==1)
        cout<<n<<" "<<m<<endl;
  return 0;
}
