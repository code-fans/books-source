//高精度加法　—string
#include <bits/stdc++.h>
using namespace std;

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

int main()
{
  freopen("add.in","r",stdin);
  freopen("add.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  cout<<Add(s1,s2)<<endl;
  return 0;
}

