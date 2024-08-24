//»¥ËÍÀñÎï
#include <bits/stdc++.h>
using namespace std;

map<string,int>ans;

int main()
{
  //freopen("gift.in","r",stdin);
  //freopen("gift.out","w",stdout);
  int n,money;
  cin>>n;
  string name[15],s,p;
  for(int i=1; i<=n; i++)
    cin>>name[i];
  for(int i=1,num; i<=n; i++)
  {
    cin>>s>>money>>num;
    for(int j=1; j<=num; j++)
    {
      cin>>p;
      ans[p]+=money/num;
    }
    if(num!=0)
      ans[s]=ans[s]-money+money%num;
  }
  for(int i=1; i<=n; i++)
    cout<<name[i]<<' '<<ans[name[i]]<<endl;
  return 0;
}

