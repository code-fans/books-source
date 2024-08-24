//神经网络
//注意第一层不适用公式，因为题目里有一句话叫"在输入层神经元被激发之后"，此外，求和公式不包括减掉的阀值
#include <bits/stdc++.h>
using namespace std;

int n,p,c[110],u[110],rd[110],cd[110];
int g[110][110];//100的数据考虑邻接矩阵
int q[2000010];
int main()
{
  freopen("NETWORKS.in","r",stdin);
  freopen("NETWORKS.out","w",stdout);
  cin>>n>>p;
  for(int i=1,u; i<=n; i++)
  {
    cin>>c[i]>>u;
    c[i]-=u;        //按公式要求把每一个状态减掉阈值
  }
  for(int i=1,s,t; i<=p; i++)
  {
    cin>>s>>t;
    cin>>g[s][t];
    rd[t]++;         //记录入度
    cd[s]++;         //记录出度
  }
  int head=0,tail=1;
  for(int i=1; i<=n; i++)
    if(rd[i]==0)   //输入层是入度为0的结点
      q[++tail]=i;//把入度为0的第一层点入队列,准备拓扑排序
  while(head<tail)
  {
    head++;
    if(c[q[head]]>0)                        //兴奋则传递
    {
      for(int i=1; i<=n; i++)
        if(g[q[head]][i]!=0)
        {
          c[i]+=g[q[head]][i]*c[q[head]];   //按公式传递
          q[++tail]=i;                      //传完入队列
        }
      if(cd[q[head]]!=0)//除了最后一层的点，传完之后都要把状态清空
        c[q[head]]=0;
    }
  }
  int flag=0; //记录有没有c>0的输出
  for(int i=1; i<=n; i++)
    if(c[i]>0)
      flag=1,cout<<i<<" "<<c[i]<<endl;
  if(flag==0)
    cout<<"NULL"<<endl;
  return 0;
}

