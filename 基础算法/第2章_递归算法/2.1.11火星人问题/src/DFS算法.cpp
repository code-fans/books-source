#include <bits/stdc++.h>
using namespace std;
int ans=-1,a[10001],m,n,s[10001];
bool used[10001];

void Out()
{
  cout<<a[1];
  for(int i=2; i<=n; i++)
    cout<<" "<<a[i];
  cout<<endl;
  exit (0);
}

int DFS(int pos,int k)
{
  if(pos==0)
  {
    ans++;
    if(ans==m)
      Out();
  }
  else
    for(int i=s[k]; i<=pos; i++)//从当前数向后扫描
      if(!used[i])            //如果当前数没用过
      {
        s[k]=1;
        a[k]=i;
        used[i]=true;
        DFS(pos-1,k+1);
        used[i]=false;
      }
}

int main()
{
  freopen("martian.in","r",stdin);
  freopen("martian.out","w",stdout);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>s[i];
  DFS(n,1);
  return 0;
}
