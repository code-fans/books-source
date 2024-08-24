//魔法石矿
#include <bits/stdc++.h>
using namespace std;

int a[1001];
int g[1001][1001];

inline bool isNumber(char c)
{
  return (c>='0' && c<='9');
}

void GetNum(int n)
{
  char c;
  for(int i=1; i<=n; i++)
  {
    int x;
    cin>>x;
    do
    {
      int num=0;
      while(isNumber(c=getchar()))
        num=num*10+c-'0';
      g[x][num]=1;
    }
    while(c!='\n');                         //一直读到换行
  }
}

int main()
{
  freopen("Mine.in","r",stdin);
  freopen("Mine.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  GetNum(n);

  int maxn,Ans=0;
  for(int i=n; i>=1; i--)                   //从后往前扫描
  {
    maxn=0;
    for(int j=i+1; j<=n; j++)               //找连通路线中的最多魔法石
      if(g[i][j] && a[j]>maxn)              //连接且值最大
        maxn=a[j];
    a[i]+=maxn;
    Ans=Ans>a[i]?Ans:a[i];
  }
  printf("%d\n",Ans);
  return 0;
}


