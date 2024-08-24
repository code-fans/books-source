#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5+10;
const int seed = 31;

char s[maxn];
int m,l;
ull h[maxn];
ull base[maxn];
map<ull, int> mp;

ull Get(int l, int r)
{
  return h[r] - h[l-1]*base[r-l+1];
}

int main()
{
  freopen("string21.in","r",stdin);
  freopen("string21.ans","w",stdout);
  base[0] = 1;
  for(int i = 1; i < maxn; ++i) base[i] = base[i-1]*seed;
  while(~scanf("%d%d",&m,&l))
  {
    scanf("%s",s+1);
    int len = strlen(s+1);
    h[0] = 0;
    for(int i = 1; i <= len; ++i)
      h[i] = h[i-1]*seed + s[i] - 'a';

    int ans = 0;
    for(int i = 1; i <= l&&i + m*l<= len; ++i)
    {
      mp.clear();
      for(int j = i; j < i + m*l ; j+=l)
      {
        ull x = Get(j,j+l-1);
        mp[x]++;
      }
      if(mp.size() == m) ans++;
      for(int j = i + m*l; j + l-1 <= len; j += l)
      {
        ull x = Get(j,j+l-1);
        mp[x]++;
        ull y = Get(j-m*l,j-m*l+l-1);
        mp[y]--;
        if(mp[y] == 0) mp.erase(y);
        if(mp.size() == m) ans++;
      }
    }
    printf("%d\n",ans);
  }
}
