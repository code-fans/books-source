#include < bits/stdc++.h >
using namespace std;

void fun(int n,int &s)//&s表示取s的地址
{
  int i;
  for(i=1; i<=n; i++)
    s+=i;
}

int main()
{
  int n=10,s=0;
  fun(n,s);
  cout<<"s="<<s<<endl;
  return 0;
}

