//素数和组合
#include<bits/stdc++.h>
using namespace std;

int b[1000];
int n,k,ans,sum;

bool Prime(int t)
{
  for(int i=sqrt(t); i>=2; i--)
    if(t%i==0)
      return 0;
  return 1;
}

void Dfs(int s,int dep)
{
  if(dep>k)
  {
    if(Prime(sum))
      ans++;
    return;
  }
  for(int i=s; i<=n; i++)
  {
    sum+=b[i];
    Dfs(i+1,dep+1);
    sum-=b[i];
  }
}

int main()
{
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  cin>>n>>k;
  for(int i=1; i<=n; i++)
    cin>>b[i];
  Dfs(1,1);  //从第几位开始选数，填充第几位数
  cout<<ans<<endl;
  return 0;
}
