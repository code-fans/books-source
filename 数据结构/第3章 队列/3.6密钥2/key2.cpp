//√‹‘ø2
#include <bits/stdc++.h>
using namespace std;

struct man
{
  int val;
  int index;
} tmp;
deque <man> v;

int main()
{
  freopen("key2.in","r",stdin);
  freopen("key2.out","w",stdout);
  int n,m;
  cin>>n>>m;
  printf("0\n");
  for(int Time=1; Time<n; Time++)
  {
    scanf("%d",&tmp.val);
    tmp.index=Time;
    if (Time-v.front().index>=m)
      v.pop_front();
    while(!v.empty() && tmp.val<v.back().val)
      v.pop_back();
    v.push_back(tmp);
    printf("%d\n",v.front().val);
  }
  return 0;
}
