#include <bits/stdc++.h>
using namespace std;

int cnt,a[1000001]= {0,1};//存储每一个节点的深度，由于1是根节点，所以深度为1
pair<int,int>p[1000001];//pair容器存储每一轮的信息

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n,ans=1;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>p[i].first>>p[i].second;//读入
  while(cnt<n-1)//n-1(此处不包括根节点)个节点都赋了深度
  {
    for(int i=1; i<=n; i++)
      if(a[i])//如果第i个节点已经赋了深度
      {
        a[p[i].first]=a[i]+1;
        a[p[i].second]=a[i]+1;//左右儿子深度：父亲深度+1
        if(p[i].first>0)//如果有左儿子(或右儿子),则cnt++(又给一个节点赋了深度)
          cnt++;
        if(p[i].second>0)
          cnt++;
        if(p[i].first!=0||p[i].second!=0)
          ans=max(a[p[i].first],ans);//由于深度最大的节点便是整棵树的深度，所以刷新最大值
        a[i]=0;//为了防止深度多次赋值，把当前节点赋为0
      }
    cout<<ans<<endl;//输出
  }
  return 0;
}
