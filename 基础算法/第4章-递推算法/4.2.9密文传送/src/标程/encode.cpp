//ÃÜÎÄ´«ËÍ
#include <bits/stdc++.h>
using namespace std;

char ss[21];
int num[21];

int Get_c(int n,int m)
{
  if(m==1)
    return n;
  else if(n==m)
    return 1;
  else
    return Get_c(n-1,m-1 )+ Get_c(n-1,m);
}

int main()
{
  //freopen("encode.in","r",stdin);
  //freopen("encode.out","w",stdout);
  scanf("%s",&ss);
  int n=strlen(ss);
  for (int i=1; i<=n; i++)
    num[i]=ss[i-1]-'a'+1;
  int ans=0;
  if (n>1)
  {
    for(int i=1; i<n; i++)
      ans+=Get_c(26,i);
    for(int i=1; i<n; i++)
      for(int j=num[i-1]+1; j<num[i]; j++)
        ans+=Get_c(26-j,n-i);
    ans+=num[n]-num[n-1];
  }
  else
    ans = num[1];
  printf("%d\n", ans);
  return 0;
}

