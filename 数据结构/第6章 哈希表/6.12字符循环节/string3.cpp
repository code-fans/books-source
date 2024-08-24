#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 500009;
const ull P = 1000173169;

char S[maxn];
int check[maxn], prime[maxn], N = 0, n;
ull H[maxn], K[maxn];

void init()
{
  memset(check, 0, sizeof check);
  for(int i = 2; i <= n; i++)
  {
    if(!check[i])
      check[i] = prime[N++] = i;
    for(int j = 0; j < N && i * prime[j] <= n; j++)
    {
      check[i * prime[j]] = prime[j];
      if(i % prime[j] == 0) break;
    }
  }
  H[n] = 0;
  K[0] = 1;
  for(int i = n - 1; ~i; i--)
    H[i] = H[i + 1] * P + S[i];
  for(int i = 1; i <= n; i++)
    K[i] = K[i - 1] * P;
}

inline bool Get(int a, int b, int L)
{
  return H[a] - H[a + L] * K[L] == H[b] - H[b + L] * K[L];
}

void Read()
{
  cin >> n;
  char* t = S;
  for(; !islower(*t); *t = getchar());
  for(int i = 1; i < n; i++)
    *++t = getchar();
}

int main()
{
  //freopen("string35.in","r",stdin);
  //freopen("string35.ans","w",stdout);
  Read();
  init();
  int q;
  scanf("%d", &q);
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    int ans = r - l + 1, t = ans;
    while(t > 1)
    {
      int x = check[t];
      while(ans % x == 0 && Get(l, l + ans / x, r - l  + 1 - ans / x)) ans /= x;
      for(; t % x == 0; t /= x);
    }
    printf("%d\n", ans);
  }
  return 0;
}
