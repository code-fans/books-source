//素数和组合
#include<bits/stdc++.h>
using namespace std;

int a[1000],b[1000];
int n,k,ans;

bool Prime(int t)
{
  for(int i=sqrt(t); i>=2; i--)
    if(t%i==0)
      return 0;
  return 1;
}

void Dfs(int dep)
{
  if(dep>k)
  {
    int sum=0;
    for(int i=1; i<=k; i++)
      sum+=b[a[i]];
    if(Prime(sum))
      ans++;
    return;
  }
  for(int i=a[dep-1]+1; i<=n; i++)
  {
    a[dep]=i;
    Dfs(dep+1);
  }
}

int main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  cin>>n>>k;
  for(int i=1; i<=n; i++)
    cin>>b[i];
  Dfs(1);
  cout<<ans<<endl;
  return 0;
}
