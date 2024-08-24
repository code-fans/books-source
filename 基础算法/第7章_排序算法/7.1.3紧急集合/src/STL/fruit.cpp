//紧急集合 —优先队列
#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;

int main()
{
  freopen("fruit.in","r",stdin);
  freopen("fruit.out","w",stdout);
  int n,ans=0;
  cin>>n;
  for(int i=1,t; i<=n; i++)
    cin>>t,q.push(t);
  while(q.size()>=2)
  {
    int a=q.top();
    q.pop();
    int b=q.top();
    q.pop();
    ans+=a+b;
    q.push(a+b);
  }
  cout<<ans<<endl;
  return 0;
}
