//最长公共子序列 - 算法1
#include <bits/stdc++.h>
using namespace std;
#define M 501

int n1,n2;
int a[M],b[M];
char s1[M],s2[M];

void Dp()
{
  for(int i=1; i<=n1; i++)           //遍历S1
  {
    int Max=b[0];
    for(int j=1; j<=n2; j++)         //遍历S2
    {
      if(s1[i]==s2[j])
        a[j]=Max+1;
      Max=max(Max,b[j]);             //小优化,记录数组b的0~j-1的最大值
    }
    memcpy(b,a,sizeof(a));           //数组复制
  }
}

int main()
{
  //freopen("LCS.in","r",stdin);
  //freopen("LCS.out","w",stdout);
  scanf("%d%*c",&n1);                //*表示读入（换行符）不赋予任何变量
  for(int i=1; i<=n1; ++i)
    scanf("%c",&s1[i]);
  scanf("%d%*c",&n2);
  for(int i=1; i<=n2; ++i)
    scanf("%c",&s2[i]);
  Dp();                              //动规
  int ans=0;
  for(int i=1; i<=n2; i++)
    ans=max(ans,a[i]);
  printf("%d\n",ans);
  return 0;
}

