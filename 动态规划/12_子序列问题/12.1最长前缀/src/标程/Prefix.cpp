//最长前缀
#include <bits/stdc++.h>
using namespace std;

int n,ans;
string P[201],S=" ";
bool f[200001]= {1};                        //f[0]=true

bool Check(int p)                           //查找集合中匹配的串
{
  for (int i=0; i<n; i++)                   //枚举集合中的单词
  {
    int t=P[i].size();
    if (p>=t && f[p-t] && P[i]==S.substr(p-t+1,t))
    {
      ans=p;
      return true;
    }
  }
  return false;
}

int main()
{
  //freopen("Prefix.in","r",stdin);
  //freopen("Prefix.out","w",stdout);
  for(string s; cin>>s,s!="."; P[n++]=s);   //读入P集合
  for(string s; cin>>s; S+=s);              //读入S
  for (int i=1; i<=S.size(); i++)
    f[i]=Check(i);
  cout<<ans<<endl;
  return 0;
}

