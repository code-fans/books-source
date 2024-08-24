//国王游戏
#include <bits/stdc++.h>
using namespace std;

struct data
{
  int a,b;
} man[10005];

int CMP(data a,data b)
{
  return a.a*a.b<b.a*b.b;
}

string MAX(string a,string b)
{
  if(a.size()!=b.size())
    return a.size()>b.size()?a:b;
  return a>b?a:b;
}

string ToString(int num, string ans="")
{
  for(; num; num/=10)
    ans+=num%10+'0';
  reverse(ans.begin(),ans.end());
  return ans;
}

int temp[20005];
string Multi(string a,string b)  //高精度乘
{
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  for(int i=0; i<a.size(); i++)
    for(int j=0; j<b.size(); j++)
      temp[i+j]+=(a[i]-'0')*(b[j]-'0');
  for(int i=0; i<a.size()+b.size(); i++)
    if(temp[i]>=10)
    {
      temp[i+1]+=temp[i]/10;
      temp[i]%=10;
    }
  string ans="";
  int len=a.size()+b.size()-1;
  for(; temp[len]==0; len--);
  for(int i=len; i>=0; i--)
    ans+=temp[i]+'0';
  return ans;
}

int dividend[20005],result[20005];
string Div(string a,int b)       //高精度除
{
  for(int i=0; i<a.size(); i++)
    dividend[i+1]=a[i]-'0';
  for(int i=1,rem=0; i<=a.size(); i++)
  {
    result[i]=(rem*10+dividend[i])/b;
    rem=(rem*10+dividend[i])%b;
  }
  int len=1;
  string ans="";
  for(; result[len]==0&& len<a.size(); ++len);
  for(int i=len; i<=a.size(); i++)
    ans+=result[i]+'0';
  return ans;
}

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<=n; i++)
    scanf("%d%d",&man[i].a,&man[i].b);
  sort(man+1,man+n+1,CMP);             //对后面的大臣排序
  string ans="0";
  string mul=ToString(man[0].a);
  for(int i=1; i<=n; i++)
  {
    ans=MAX(ans,Div(mul,man[i].b));
    mul=Multi(mul,ToString(man[i].a));
  }
  cout<<ans<<endl;
  return 0;
}

