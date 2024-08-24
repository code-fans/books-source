//修补栅栏
//要使总费用最小，那么每次只选取最小长度的两块木板相加，再把这些“和”累加到总费用中即可
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >wood;

int main()
{
  //freopen("repair.in","r",stdin);
  //freopen("repair.out","w",stdout);
  int n,l;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>l;
    wood.push(l);
  }
  long long ans=0;
  while(wood.size()>1)           //堆中元素大于1个
  {
    int l1=wood.top();           //取出堆顶元素作为左儿子
    wood.pop();
    int l2=wood.top();           //取出后一个堆顶元素作为右儿子
    wood.pop();
    ans+=l1+l2;                  //父节点作为非叶子节点,权值为a+b
    wood.push(l1+l2);            //父节点权值放回堆中
  }
  printf("%lld\n",ans);
  return 0;
}
