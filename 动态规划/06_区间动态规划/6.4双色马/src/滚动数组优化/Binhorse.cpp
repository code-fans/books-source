//˫ɫ��
#include <bits/stdc++.h>
using namespace std;
#define dp(i,j) dp[(i)%2][j]

int dp[2][510],b[510];

int main()
{
  //freopen("Binhorse.in","r",stdin);
  //freopen("Binhorse.out","w",stdout);
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0; i<2; i++)            //�����Ҫ���ڵ�������
    for(int j=i+1; j<501; j++)
      dp[i][j]=1<<30;               //��������Ϊ�����
  for(int i=1,x; i<=N; i++)
  {
    scanf("%d",&x);
    b[i]=b[i-1]+x;                  //�����ǰ׺������
  }
  for(int i=1; i<=K; i++)           //ö�����
    for(int j=i; j<=N-(K-i); j++)   //ö��ǰi����Ƿŵ���ƥ��
      for(int k=i-1; k<j; k++)      //ǰ�����Ƿ�����kƥ��
        dp(i,j)=min(dp(i,j),dp(i-1,k)+(b[j]-b[k])*(j-k-(b[j]-b[k])));
  printf("%d\n",dp(K,N));
  return 0 ;
}
