#include<bits/stdc++.h>
using namespace std;
int a[505], b[505], c[505];

int main()
{
  freopen("book.in","r",stdin);
  freopen("book.out","w",stdout);
  int n, k, i, j;
  while(scanf("%d%d",&n,&k)==2)
  {
    if(n == 0 && k == 0)
    {
      cout << endl;
      continue;
    }
    int sum = 0;
    for(i = 1; i <= n; ++ i)
    {
      cin >> a[i];
      sum += a[i];
    }
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int l = 1, r = sum, mid;
    while(l <= r)
    {
      mid = (l + r) / 2;
      j = n;
      for(i = 1; i <= k; ++ i)
      {
        int tmp = 0;
        for(; j >= 1; j --)
          if(tmp + a[j] <= mid)
            tmp += a[j];
          else break;
        b[i] = j;
        if(j == 0) break;
      }
      if(j == 0 && i <= k)
      {
        r = mid - 1;
        for(i = 1; i <= k; ++ i)
          c[i] = b[i];
      }
      else l = mid + 1;
    }
    c[0] = n;
    for(i = k; i > 0; -- i)
      cout << c[i] + 1 << ' ' << c[i-1] << endl;
  }
  return 0;
}

