//幂次方
#include<bits/stdc++.h>
using namespace std;

string Dg(int n)
{
  string s;
  if(n==0)
    return "0";
  for(int i=0; n; n>>=1,i++)    //从右到左逐位扫描
    if(n&1)                     //当前二进制位是1
    {
      if(s!="")                 //字符串不为空则加个加号 
        s="+"+s;
      if(i==1)
        s="2"+s;
      else
        s="2("+Dg(i)+")"+s;
      cout<<i<<' '<<s<<endl;
    }
  return s;
}

int main()
{
//  //freopen("pow.in","r",stdin);
//  //freopen("pow.out","w",stdout);
  int n;
  cin>>n;
  cout<<Dg(n)<<endl;
  return 0;
}
