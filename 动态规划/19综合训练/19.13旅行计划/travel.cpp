#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int du[N],Ans[N];
vector <int> f[N];
stack <int> s;

int main()
{
  //freopen("travel1.in","r",stdin);
  //freopen("travel1.ans","w",stdout);

  int m,n,u,v;
  cin>>n>>m;//输入城市和道�?�?
  while(m--)
  {
    cin>>u>>v;
    f[u].push_back(v);
    ++du[v];//入度�?1
  }
  for(int i=1; i<=n; i++)
    if(du[i]==0) //当入度为0存入堆栈
      Ans[i]=1,s.push(i);
  while(!s.empty())//边拓扑边动�??
  {
    u=s.top();
    s.pop();
    int k=f[u].size()-1;
    for(int i=0; i<=k; i++)//查找所有u东面的连线城市v
    {
      v=f[u][i];
      --du[v];
      Ans[v]=max(Ans[v],Ans[u]+1);//动�?�找最长路�?
      if(du[v]==0)//如果入度�?0则入�?
        s.push(v);
    }
  }
  for(int i=1; i<=n; i++)
    cout<<Ans[i]<<endl;
  return 0;
}
