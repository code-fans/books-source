//�Ӽ�ȡ��
#include <bits/stdc++.h>
using namespace std;

int dp[10010][110],a[10010];

int main()
{
  //freopen("Divisibility.in","r",stdin);
  //freopen("Divisibility.out","w",stdout);
  int t,n,k;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++)
    {
      scanf("%d",&a[i]);
      a[i]=(a[i]%k+k)%k;          //�����и���
    }
    memset(dp,0,sizeof(dp));
    dp[0][a[0]]=1;
    for(int i=1; i<n; ++i)        //ö��n����
      for(int j=0; j<k; ++j)
        if(dp[i-1][j])            //���ģk������Ϊj
        {
          dp[i][(j+a[i])%k]=1;
          dp[i][(j-a[i]+k)%k]=1;
        }
    printf("%s%s",dp[n-1][0]?"Divisible":"Not divisible",t?"\n\n":"\n");
  }
  return 0;
}

