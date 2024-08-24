//五分制
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int grade;//注意此处是整数
  cin>>grade;
  switch(grade)  //比较grade值，grade值为一个整数
  {
    case 5:
      cout<<"A\n";
      break;
    case 4:
      cout<<"B\n";
      break;
    case 3:
      cout<<"C\n";
      break;
    case 2:
      cout<<"D\n";
      break;
    default:
      cout<<"E\n"; // 此处可以不加break语句
  }
  return 0;
}

