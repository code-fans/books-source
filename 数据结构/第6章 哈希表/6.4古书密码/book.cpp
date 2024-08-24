//¹ÅÊéÃÜÂë
#include <bits/stdc++.h>
using namespace std;
#define maxn 16000005

bool Hash[maxn];
int name[260];
int n, nc;
char st[maxn];

int main()
{
  freopen("book.in","r",stdin);
  freopen("book.out","w",stdout);
  cin>>n>>nc>>st;
  memset(name, 0, sizeof(name));
  memset(Hash, 0, sizeof(Hash));
  int len = strlen(st);
  int t =0;
  for (int i =0; i < len; i++)
    if (name[st[i]] ==0)
      name[st[i]] = t++;
  int temp =0;
  t = nc;
  for (int i =0; i < n -1; i++)
  {
    temp = temp * nc + name[st[i]];
    t *= nc;
  }
  int ans =0;
  for (int i = n -1; i < len; i++)
  {
    temp = (temp * nc + name[st[i]]) % t;
    if (!Hash[temp])
    {
      ans++;
      Hash[temp] =true;
    }
  }
  cout<<ans<<endl;
  return 0;
}
