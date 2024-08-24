//随机生成数据的程序
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in.txt","r",stdin);//Dev-C++智能开发平台必须写这句
  //freopen("in.txt","w",stdout);//生成的随机数据写到in.txt
  srand(time(0));
  int a,b,c;//设为int类型，在小范围内验证即可
  a=rand();
  b=rand();
  c=rand();
  cout<<a<<" "<<b<<" "<<c<<endl;
  return 0;
}

