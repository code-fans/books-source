//»¬¶¯´°¿Ú
#include <bits/stdc++.h>
using namespace std;

int n,k;
int q1[1000010],q2[1000010],w[1000010];

int Min_deque()
{
  int head=1,tail=0;
  for(int i=1; i<=n; i++)
  {
    for(; head<=tail && q1[head]+k<=i; head++);
    for(; head<=tail && w[i]<w[q1[tail]]; tail--);
    q1[++tail]=i;
    if(i>=k)
      printf("%d ",w[q1[head]]);
  }
}

int Max_deque()
{
  int head=1,tail=0;
  for(int i=1; i<=n; i++)
  {
    for(; head<=tail && q2[head]+k<=i; head++);
    for(; head<=tail && w[i]>w[q2[tail]]; tail--);
    q2[++tail]=i;
    if(i>=k)
      printf("%d ",w[q2[head]]);
  }
}

int main()
{
  //freopen("window.in","r",stdin);
  //freopen("window.out","w",stdout);
  cin>>n>>k;
  for(int i=1; i<=n; i++)
    scanf("%d",&w[i]);
  Min_deque();
  cout<<endl;
  Max_deque();
  cout<<endl;
  return 0;
}
