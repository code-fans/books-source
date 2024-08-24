//program2.cpp, 公式法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("in.txt","r",stdin); //读取的文件名相同，即in.txt
  freopen("out2.txt","w",stdout);//注意此处为out2.txt
  long long a,b,c;
  cin>>a>>b>>c;
  cout<<(a%c*b%c)%c<<endl;
  return 0;
}

