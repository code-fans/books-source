//最大乘积_ —高精度
#include <bits/stdc++.h>
using namespace std;

string str,f[41][41];

string g(int start,int end)
{
  return str.substr(start,end-start+1);
}

string Mul(string a,string b)
{
  string ans(a.size()+b.size(),'0');
  for(int i=b.size()-1; i>=0; i--)
    for(int j=a.size()-1; j>=0; j--)
    {
      int t=(ans[i+j+1]-'0')+(b[i]-'0')*(a[j]-'0');
      ans[i+j+1]=t%10+'0';
      ans[i+j]=(ans[i+j]-'0'+t/10)+'0';
    }
  for(; ans[0]=='0' && ans.size()>1; ans.erase(0,1));
  return ans;
}

string GetMax(string x,string y)
{
  return (x.size()==y.size() && x>=y || x.size()>y.size()?x:y);
}

int main()
{
  freopen("product.in","r",stdin);
  freopen("product.out","w",stdout);
  int n,k;
  cin>>n>>k>>str;
  for(int i=0; i<n; i++)
    f[i][0]=g(0,i);
  for(int i=1; i<=k; i++)                 //枚举乘号
    for(int j=i; j<n; j++)                //枚举字符串
    {
      f[j][i]=Mul(f[j-1][i-1],g(j,j));
      for(int h=j-1; h>=i; h--)           //枚举切割点
        f[j][i]=GetMax(Mul(f[h-1][i-1],g(h,j)),f[j][i]);
    }
  cout<<f[n-1][k]<<endl;
  return 0;
}

