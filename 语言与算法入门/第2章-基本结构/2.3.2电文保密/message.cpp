//电文保密
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char c;
  while((c=getchar())!='\n')//getchar：从键盘获取一个字符
  {
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))//当字符为英文字母时
    {
      c+=4;
      if(c>'Z' && c<='Z'+4 || c>'z') //参照Ascii码表，考虑为什么这样写
        c-=26;
    }
    cout<<c;
  }
  cout<<endl;
  return 0;
}

