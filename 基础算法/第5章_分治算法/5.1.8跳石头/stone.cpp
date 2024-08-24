//跳石头
#include <bits/stdc++.h>
using namespace std;

int L,m,n;
int a[50010];

int Check(int len)
{
  int ans = 0;
  int last = 0;               //上一块石头距起点的位置
  for(int i = 1; i <= n; i++)
    if(a[i] - last < len)     //如果这两块石头相距小于当前值
      ans++;                  //就要把这块石头移走
    else
      last = a[i];
  return ans > m?0:1;         //移走的数目多于m，说明答案取大了
}

int main()
{
  freopen("stone.in","r",stdin);
  freopen("stone.out","w",stdout);
  cin>>L>>n>>m;
  for(int i = 1; i <= n; i++)
    cin>>a[i];
  a[++n] = L;
  int l = 0, r = L;
  while(l <= r)
  {
    int mid = (l + r)>>1;
    Check(mid)?l = mid + 1:r = mid - 1;
  }
  cout<<r<<endl;
  return 0;
}

