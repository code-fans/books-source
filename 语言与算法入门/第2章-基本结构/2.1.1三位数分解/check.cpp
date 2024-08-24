//三位数分解
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num;
  cin>>num;                  //输入一个三位数
  cout<<"Hundreds is "<<num/100<<endl;
  cout<<"Tens is "<<num/10%10<<endl;
  cout<<"Ones is "<<num%10<<endl;
  return 0;
}

