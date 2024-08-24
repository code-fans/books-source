//最长前缀
#include <bits/stdc++.h>
using namespace std;

int f[200005]= {1},MaxLen,ans;
set<string> P[20];

int main()
{
  //freopen("Prefix.in","r",stdin);
  //freopen("Prefix.out","w",stdout);
  for (string s; cin>>s,s!=".";)
  {
    P[s.size()].insert(s);          //存入长度相同的的集合中
    MaxLen=max(MaxLen,int(s.size()));
  }
  string S=" ";
  for(string s; cin>>s; S+=s);
  for (int i=1; i<S.size(); i++)    //枚举S串
    for (int j=min(i,MaxLen); j>=1; j--)
    {
      string t=S.substr(i-j+1,j);   //截除子串
      if (f[i-j]==1 && P[t.size()].count(t))
      {
        f[i]=true;
        ans=i;
        break;
      }
    }
  cout<<ans<<endl;
  return 0;
}
