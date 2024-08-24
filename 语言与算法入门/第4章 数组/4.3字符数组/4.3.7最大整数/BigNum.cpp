//最大整数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("BigNum.in","r",stdin);
  //freopen("BigNum.out","w",stdout);
  char s[101][30],t1[65],t2[65];
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%s",&s[i]);
  for(int i=1; i<n; i++)             //冒泡排序
    for(int j=1; j<=n-i; j++)
    {
      strcpy(t1,s[j]);
      strcpy(t2,s[j+1]);
      strcat(t1,s[j+1]);             //s[i]+s[j+1]
      strcat(t2,s[j]);               //s[j+1]+s[i]
      if(strcmp(t1,t2)<0)
        swap(s[j],s[j+1]);
    }
  for(int i=1; i<=n; ++i)
    printf("%s",s[i]);
  printf("\n");
  return 0;
}

