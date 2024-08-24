//没有上司的舞会
#include <bits/stdc++.h>
using namespace std;

int N,f[6001][2],parent[6001];
bool visited[6001];

void Dp(int man)
{
  if(!visited[man])                        //没有访问过
  {
    visited[man]=1;
    for(int i=1; i<=N; i++)
      if(parent[i]==man)
      {
        if(!visited[i])
          Dp(i);
        f[man][1]+=f[i][0];
        f[man][0]+=max(f[i][0],f[i][1]);
      }
  }
}

int main()
{
  //freopen("party.in","r",stdin);
  //freopen("party.out","w",stdout);
  int man,leader,Max=0;
  cin>>N;
  for(int cnt=1; cnt<=N; cnt++)       //输入每个人的价值
    cin>>f[cnt][1];
  while(cin>>man>>leader, man|leader)
    parent[man]=leader;
  for(int i=1; i<=N; i++)                   //保证每个人都被搜索到
    Dp(i);
  for(int i=1; i<=N; i++)                   //选最优解
    Max=max(max(f[i][0],f[i][1]),Max);
  cout<<Max<<endl;
  return 0;
}

