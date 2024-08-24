#include <bits/stdc++.h>
#define MAX 2000010
#define BASE 23333
using namespace std;

int length, mid;
char s[MAX];

unsigned long long _hash[MAX];
unsigned long long power[MAX];

int cnt;
char ans[MAX], now[MAX];
unsigned long long h_ans, h_now;

inline unsigned long long GetHash(int l, int r)
{
  return _hash[r] - _hash[l - 1] * power[r - l + 1];
}

inline bool Judge(int dismiss)
{
  static unsigned long long front, tail;
  if(dismiss < mid)
  {
    front = GetHash(1, dismiss - 1) * power[mid - dismiss] + GetHash(dismiss + 1, mid);
    tail = GetHash(mid + 1, length);
  }
  else if(dismiss == mid)
  {
    front = GetHash(1, mid - 1);
    tail = GetHash(mid + 1, length);
  }
  else
  {
    front = GetHash(1, mid - 1);
    tail = GetHash(mid, dismiss - 1) * power[length - dismiss] + GetHash(dismiss + 1, length);
  }
  if(front == tail)
  {
    if(h_ans == front)  return false;
    h_ans = front;
    int top = 0;
    if(dismiss <= mid)
      for(int i = mid + 1; i <= length; ++i)
        ans[++top] = s[i];
    else
      for(int i = 1; i < mid; ++i)
        ans[i] = s[i];
    return true;
  }
  return false;
}

int main()
{
  freopen("friends.in","r",stdin);
  freopen("friends.ans","w",stdout);
  cin >> length;
  if(!(length&1))
  {
    puts("NOT POSSIBLE");
    return 0;
  }
  mid = (length >> 1) + 1;
  scanf("%s", s + 1);
  power[0] = 1;
  for(int i = 1; i <= length; ++i)
    power[i] = power[i - 1] * BASE;
  for(int i = 1; i <= length; ++i)
    _hash[i] = _hash[i - 1] * BASE + s[i];
  for(int i = 1; i <= length; ++i)
  {
    cnt += Judge(i);
    if(cnt > 1) break;
  }
  if(!cnt)
    puts("NOT POSSIBLE");
  if(cnt == 1)
    puts(ans + 1);
  if(cnt > 1)
    puts("NOT UNIQUE");
  return 0;
}
