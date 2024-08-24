//Ñ²ÊÓ ¡ªDFSËã·¨
#include <bits/stdc++.h>
using namespace std;

int a[11],T,n,m,Min;
bool used[100];

struct node
{
  int x,y;
} p[11];

int Calc(int ans=0)
{
  for(int i=0; i<n; i++)
    ans+=abs(p[a[i]].x-p[a[i+1]].x)+abs(p[a[i]].y-p[a[i+1]].y);
  ans+=abs(p[a[n]].x-p[a[0]].x)+abs(p[a[n]].y-p[a[0]].y);
  return ans;
}

void DFS(int k)
{
  if(k>n)
    Min=min(Min,Calc());
  else
    for(int i=1; i<=n; i++)
      if(used[i]==0)
      {
        used[i]=1;
        a[k]=i;
        DFS(k+1);
        used[i]=0;
      }
}

int main()
{
  //freopen("Patrol.in","r",stdin);
  //freopen("Patrol.out","w",stdout);
  cin>>T;
  while(T--)
  {
    Min=1e10;
    cin>>p[0].x>>p[0].y>>p[0].x>>p[0].y>>n;
    for(int i=1; i<=n; i++)
      cin>>p[i].x>>p[i].y;
    DFS(1);
    cout<<"The shortest path has length "<<Min<<endl;
  }
  return 0;
}
