//数列极差问题
#include <bits/stdc++.h>
using namespace std;
#define MAX 0x7fffffff

int main()
{
  //freopen("Max_Min.in","r",stdin);
  //freopen("Max_Min.out","w",stdout);
  int n;
  while (scanf("%d", &n) == 1 && n)
  {
    priority_queue<int,vector<int>,greater<int> >a;
    priority_queue<int,vector<int>,less<int> >b;
    for (int i=0,val; i<n; i++)
    {
      cin>>val;
      a.push(val);
      b.push(val);
    }
    for(int i=1,x,y; i<n; i++)
    {
      x=a.top();
      a.pop();
      y=a.top();
      a.pop();
      a.push(x*y+1);
      x=b.top();
      b.pop();
      y=b.top();
      b.pop();
      b.push(x*y+1);
    }
    printf("%0.lf\n", fabs(a.top()-b.top()));
  }
  return 0;
}
