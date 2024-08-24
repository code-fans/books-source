//树根和宝藏
#include <bits/stdc++.h>
using namespace std;
int father[105];

int main()
{
  freopen("treasure.in","r",stdin);
  freopen("treasure.out","w",stdout);
  int n,m,x,y,Root,sum,Max=0,MaxRoot;
  cin>>n>>m;
  for(int i=1; i<=m; ++i)
  {
    cin>>x>>y;
    father[y]=x;    //y的父亲结点是x,结点的父亲结点是唯一的
  }
  for(int i=1; i<=n; i++)
  {
    if(father[i]==0)
      Root=i;
    sum=0;
    for(int j=1; j<=n; ++j)
      if(father[j]==i)
        sum++;
    if(sum>Max)
      MaxRoot=i,Max=sum;
  }
  cout<<Root<<" "<<MaxRoot<<endl;
  return 0;
}

