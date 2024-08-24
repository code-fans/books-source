//添加号问题 —高精度
#include <bits/stdc++.h>
using namespace std;

string str,f[41][201];

string g(int start,int end)
{
  return str.substr(start,end-start+1);
}

string Add(string a,string b)
{
  string ans(max(a.size(),b.size())+1,'0');
  for(int i=ans.size()-1,l1=a.size(),l2=b.size(); i>=0; i--)
  {
    int t=(ans[i]-'0')+(l1<1?0:a[--l1]-'0')+(l2<1?0:b[--l2]-'0');
    ans[i]=t%10+'0';
    ans[i-1]=(ans[i-1]-'0'+t/10)+'0';
  }
  for(; ans[0]=='0' && ans.size()>1; ans.erase(0,1));
  return ans;
}

string GetMin(string x,string y)
{
  return (x.size()==y.size() && x>=y || x.size()>y.size()?y:x);
}

int main()
{
  //freopen("parentheses.in","r",stdin);
  //freopen("parentheses.out","w",stdout);
  int m;
  cin>>str>>m;
  for(int i=0; i<str.size(); i++)
    f[i][0]=g(0,i);
  for(int i=1; i<=m; i++)                 //枚举乘号
    for(int j=i; j<str.size(); j++)       //枚举字符串
    {
      f[j][i]=Add(f[j-1][i-1],g(j,j));
      for(int h=j-1; h>=i; h--)           //枚举切割点
        f[j][i]=GetMin(Add(f[h-1][i-1],g(h,j)),f[j][i]);
    }
  cout<<f[str.size()-1][m]<<endl;
  return 0;
}

