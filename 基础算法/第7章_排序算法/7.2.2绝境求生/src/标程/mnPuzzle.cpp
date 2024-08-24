//绝境求生
//计算初始状态和目标状态的逆序对数同奇或同偶即有解
//此处用的是树状数组求逆序对
#include <stdio.h>
#include <string.h>

#define lowbit(i) (i) & (-i)
#define N 1000007
int a[N],b[N],k;
void update(int i)
{
  for(; i <=k; i += lowbit(i))
    b[i] ++;
}

int sum(int i)
{
  int ans = 0;
  for(; i > 0; i -= lowbit(i))
    ans += b[i];
  return ans;
}

int cal()
{
  int res = 0;
  for(int i = 0; i < k; ++i)
  {
    update(a[i]);
    res += i + 1 - sum(a[i]);
  }
  return res;
}

int main()
{
  freopen("mnPuzzle.in","r",stdin);
  freopen("mnPuzzle.out","w",stdout);
  int n,m,cnt,step,s;
  while(scanf("%d%d",&m,&n) && m)
  {
    memset(b,0,sizeof(b));
    k = 0;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
      {
        scanf("%d",&s);
        if(s == 0)
          step = m - i - 1;
        else
          a[k++] = s;
      }
    cnt = cal();
    if(n & 1)
      step = 0;
    printf(step % 2 == cnt % 2? "YES\n" : "NO\n");
  }
  return  0;
}
