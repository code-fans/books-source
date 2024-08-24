//健康的奶牛 —DFS
#include <bits/stdc++.h>
using namespace std;

int V,G,need[30],feed[20][30],ansN=1e9,tmp[20],sum[30],ans[30];

bool OK()                           //判断是否满足
{
  for(int i=1; i<=V; i++)
    if(sum[i]<need[i])
      return false;
  return true;
}

void DFS(int cur)                   //选出第cur种饲料
{
  for(int i=tmp[cur-1]+1; i<=G; i++)//枚举所有编号比前一种大的饲料
  {
    tmp[cur]=i;                     //取该饲料
    for(int j=1; j<=V; j++)         //分类统计累加维他命
      sum[j]+=feed[i][j];
    if(OK() && cur<ansN)            //满足则更新最优解
    {
      ansN=cur;
      for(int j=1; j<=ansN; j++)
        ans[j]=tmp[j];
    }
    else if(cur+1<ansN)             //剪枝
      DFS(cur+1);                   //递归下一个
    for(int j=1; j<=V; j++)         //不要该饲料
      sum[j]-=feed[i][j];
  }
}

int main()
{
  freopen("holstein.in","r",stdin);
  freopen("holstein.out","w",stdout);
  cin>>V;
  for(int i=1; i<=V; i++)
    cin>>need[i];
  cin>>G;
  for(int i=1; i<=G; i++)
    for(int j=1; j<=V; j++)
      cin>>feed[i][j];
  DFS(1);
  cout<<ansN<<' ';
  for(int i=1; i<=ansN; i++)
    cout<<ans[i]<<(i==ansN?'\n':' ');
  return 0;
}
