//神经网络
//注意第一层不适用公式，因为题目里有一句话叫"在输入层神经元被激发之后"
//此外，求和公式不包括减掉的阀值,BFS也可以
#include <bits/stdc++.h>
using namespace std;

int w[110][110],c[110],rd[110],cd[110];

int main()
{
  //freopen("NETWORK.in","r",stdin);
  //freopen("NETWORK.out","w",stdout);
  int n,p,outs=0;
  cin>>n>>p;
  for(int i=1,u; i<=n; i++)
  {
    cin>>c[i]>>u;
    if(c[i]==0)                        //非输入层
      c[i]-=u;                      //按公式要求先把每一个状态减掉阈值
  }
  for(int i=1,s,t; i<=p; i++)
  {
    cin>>s>>t;
    cin>>w[s][t];
    rd[t]++;                           //入度++
    cd[s]++;                           //出度++
  }
  queue <int> q;                       //队列先进先出,先放入的节点层数一定>=后放入的节点层数
  for(int i=1; i<=n; i++)
    if(rd[i]==0)                       //把入度为0的第一层点入队列,准备拓扑排序
      q.push(i);
  while(!q.empty())
  {
    int head=q.front();
    q.pop();
    for(int i=1; i<=n; i++)
      if(c[head]>0 && w[head][i]!=0)   //兴奋则传递
      {
        c[i]+=w[head][i]*c[head];      //按公式传递
        q.push(i);                     //传完入队列
      }
    if(cd[head]!=0)                    //除了最后一层，传完之后都要状态清空
      c[head]=0;
  }
  for(int i=1; i<=n; i++)
    if(c[i]>0)
    {
      outs=1;
      cout<<i<<" "<<c[i]<<endl;
    }
  if(outs==0)
    cout<<"NULL"<<endl;
  return 0;
}
