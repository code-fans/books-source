//调度问题
#include<bits/stdc++.h>
using namespace std;

int n,suma,sumb,ans=1e9;
int p[2000],A[201],B[201];

int main()
{
  //freopen("Sched.in","r",stdin);
  //freopen("Sched.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>A[i];
    suma+=A[i];
  }
  for(int i=1; i<=n; i++)
  {
    cin>>B[i];
    sumb+=B[i];
  }
  for(int k=1; k<=n; k++)
    for(int i=suma; i>=0; i--)
      if(i>=A[k])
        p[i]=min(p[i-A[k]],p[i]+B[k]);
      else
        p[i]=p[i]+B[k];

  for(int i=0; i<=suma; i++)
    ans=min(ans,max(i,p[i]));
  cout<<ans<<endl;
  return 0;
}
