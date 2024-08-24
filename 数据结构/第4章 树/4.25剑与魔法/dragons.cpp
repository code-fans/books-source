#include <bits/stdc++.h>
using namespace std;

int n,t,sum;
char c;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
  freopen("dragons.in","r",stdin);
  freopen("dragons.out","w",stdout);
  scanf("%d",&n);
  for (int i=1; i<n; i++)
  {
    cin>>c>>t;
    if (c=='c')
      q.push(t);
    else
      while (q.size()>=t)   //e指令，留下最大的x-1个元素
        q.pop();
  }
  cin>>c>>t;
  if (q.size()<t)           //判断最后是否有x个元素
    sum=-1;
  else
    while (q.size())
    {
      sum+=q.top();
      q.pop();
    }
  printf("%d\n",sum);
  return 0;
}
