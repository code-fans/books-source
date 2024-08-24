//两实数排序
#include <bits/stdc++.h>
using namespace std;

int main()
{
  float a,b,t; //a:酱油瓶b:醋瓶t:空瓶
  cin>>a>>b;
  if(a>b)
  {
    t=a;  //酱油倒入空瓶
    a=b;  //醋倒入酱油瓶
    b=t;  //保存在空瓶的酱油倒入醋瓶
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}

