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
      while (q.size()>=t)   //eָ���������x-1��Ԫ��
        q.pop();
  }
  cin>>c>>t;
  if (q.size()<t)           //�ж�����Ƿ���x��Ԫ��
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
