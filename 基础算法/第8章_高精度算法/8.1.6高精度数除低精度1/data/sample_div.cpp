//高精度数除以低精度数1
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

void Output(int c[],int len,int j=0)
{
  for(; c[j]==0 && j<len; j++); //消去前导无效的0
  for(int i=j; i<=len; ++i)
    cout<<c[i];
  cout<<'\n';
}

int main()
{
  freopen("sample_div.in","r",stdin);
  freopen("sample_div.out","w",stdout);
  int a[MAXN],c[MAXN];
  int x=0,b;             //x表示余数 
  string str;
  cin>>str>>b;
  for(int i=0; i<str.size(); ++i)
  {
    a[i]=str[i]-'0';     //先将字符转换为整数
    c[i]=(x*10+a[i])/b;  //模拟除法，将商存入c[i]
    x=(x*10+a[i])%b;     //余数乘以10后累计到x
  }
  Output(c,str.size()-1);
  return 0;
}
