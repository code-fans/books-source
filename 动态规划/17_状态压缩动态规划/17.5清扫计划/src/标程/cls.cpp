//��ɨ�ƻ�
#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)

int dis[12][12],dp[1<<11][12];

int main()
{
  freopen("cls.in","r",stdin);
  freopen("cls.out","w",stdout);
  int n;
  while(scanf("%d",&n) && n)
  {
    for(int i=0; i<=n; ++i)
      for(int j=0; j<=n; ++j)
        scanf("%d",&dis[i][j]);
    for(int k=0; k<=n; ++k)                //Floyd�㷨
      for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)
          if(dis[i][k]+dis[k][j]<dis[i][j])
            dis[i][j]=dis[i][k]+dis[k][j];
    for(int S=0; S<=(1<<n)-1; ++S)         //ö������״̬��λ�����ʾ
      for(int i=1; i<=n; ++i)              //ö��n������
        if(S & (1<<(i-1)))                 //״̬S���Ѿ���������i
          if(S==(1<<(i-1)))                //״̬Sֻ��������i
            dp[S][i]=dis[0][i];            //���Ž���Ȼ��dis[0][i]
          else                             //���S�о����������
          {
            dp[S][i]=INF;
            for(int j=1; j<=n; ++j)       //Ѱ��jʹ�þ������,��floydһ��
              if(S & (1<<(j-1)) && j!=i)  //j�ѵ������j������i
                dp[S][i]=min(dp[S^(1<<(i-1))][j]+dis[j][i],dp[S][i]);
          }
    int ans=dp[(1<<n)-1][1]+dis[1][0];
    for(int i=2; i<=n; ++i)               //�ҵ����Ž�
      ans=min(ans,dp[(1<<n)-1][i]+dis[i][0]);
    printf("%d\n",ans);
  }
  return 0;
}

