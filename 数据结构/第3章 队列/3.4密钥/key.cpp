//√‹‘ø
#include <bits/stdc++.h>
using namespace std;

struct man
{
  int index,val;
} t;
deque <man> dq;

int main()
{
  //freopen("key.in","r",stdin);
  //freopen("key.out","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int Time=1; Time<=n; Time++)
  {
    scanf("%d",&t.val);
    t.index=Time;
    while(!dq.empty() && t.val>=dq.back().val)
      dq.pop_back();
    dq.push_back(t);
    if (Time-dq.front().index>=m)
      dq.pop_front();
    if(Time>=m)
      printf("%d",dq.front().val);
  }
  printf("\n");
  return 0;
}
