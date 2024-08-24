//等级划分
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char grade;//注意此处是字符型
  cin>>grade;
  switch(grade)  //比较grade值，grade值为一个字符
  {
    case 'A':
      cout<<"Very good!\n";
      break;
    case 'B':
      cout<<"Good!\n";
      break;
    case 'C':
      cout<<"OK!\n";
      break;
    case 'D':
      cout<<"Bad!\n";
      break;
    default:
      cout<<"Too bad!\n"; // 此处可以不加break语句
  }
  return 0;
}

