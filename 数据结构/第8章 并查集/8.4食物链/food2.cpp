//食物链——种类并查集
#include<bits/stdc++.h>
using namespace std;

int n,k,X,Y,D,ans;
int father[150010];

int Find(int x)
{
  return father[x]==x?x:father[x]=Find(father[x]);
}

int Union(int x,int y)
{
  int a = Find(father[x]);
  int b = Find(father[y]);
  father[a] = b;
}

int main()
{
  cin>>n>>k;
  for(int i=3*n; i>=1; i--)
    father[i]=i;
  for(int i=1; i<=k; i++)
  {
    cin>>D>>X>>Y;
    if(D==1)
      if(X>n || Y>n || Find(X+n)==Find(Y) || Find(X+2*n)==Find(Y))
        ans++;
      else
      {
        Union(X,Y);
        Union(X+n,Y+n);
        Union(X+2*n,Y+2*n);
      }
    else if(D==2)
      if(X>n || Y>n || X==Y || Find(X)==Find(Y) || Find(X+n)==Find(Y))
        ans++;
      else
      {
        Union(X+2*n,Y);
        Union(X+n,Y+2*n);
        Union(X,Y+n);
      }
  }
  cout<<ans<<endl;
  return 0;
}
