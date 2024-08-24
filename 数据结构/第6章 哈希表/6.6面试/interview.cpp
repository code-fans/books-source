//面试
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define p 1000000009
#define mod 1000000007

int c[260];
int cnt[20000];
char ch[MAXN];
long long H[MAXN];

void init()                                //字符映射到整数
{
  for (int i='a'; i<='z'; ++i)
    c[i]=i-'a'+1;
  for (int i='A'; i<='Z'; ++i)
    c[i]=i-'A'+27;
  for (int i='0'; i<='9'; ++i)
    c[i]=i-'0'+53;
}

int main()
{
  freopen("interview.in","r",stdin);
  freopen("interview.out","w",stdout);
  init();
  int num;
  cin>>num;
  for (int i = 0; i < num; ++i)
  {
    scanf("%s",ch);
    int n = strlen(ch);
    for (int j=1; j<=n; ++j)               //计算每个字符串的哈希值
      H[j]=(H[j-1]*p+c[ch[j-1]]) % mod;
    cnt[i]=H[n];                           //将每个字符串的哈希值存入cnt[]
  }
  sort(cnt, cnt + num);//必须排序才能用unique去重,重复元素将藏在后面
  printf("%d\n",unique(cnt,cnt+num)-cnt);  //输出去重后的数组长度
  return 0;
}

