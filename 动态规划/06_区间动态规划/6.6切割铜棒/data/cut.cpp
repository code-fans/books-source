//�и�ͭ��
#include <bits/stdc++.h>
using namespace std;

int cut[55],dp[55][55];

int main()
{
  //freopen("cut.in","r",stdin);
  //freopen("cut.out","w",stdout);
  int L,N;
  while (cin>>L>>N)
  {
    for (int i=1; i<=N; ++i)
      cin>>cut[i];
    cut[0]=0;
    cut[N+1]=L;
    memset(dp,127/2,sizeof(dp));
    for (int i=0; i<=N; ++i)
      dp[i][i+1]=0;
    for (int i=2; i<=N+1; ++i)          //ö�ٿ��
      for (int s=0; s+i<=N+1; ++s)      //ö����ʼ��
        for (int k=s+1; k<s+i; ++k)     //k�ֳ�������
          dp[s][s+i]=min(dp[s][s+i],dp[s][k]+dp[k][s+i]+cut[s+i]-cut[s]);
    cout<<"The minimum cutting is "<<dp[0][N+1]<< "."<<endl;
  }
  return 0;
}

