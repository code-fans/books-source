//˿��֮· ��DP1
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;

int D[1002],C[1002],f[1002][1002];

int main()
{
  int N,M;
  scanf("%d%d",&N,&M);
  for(int i=1; i<=N; i++)
    scanf("%d",&D[i]);
  for(int i=1; i<=M; i++)
  {
    scanf("%d",&C[i]);
    f[1][i]=D[1]*C[i];//��ʼ����һ�����е�
  }
  for(int i=2; i<=N; i++) //�ӵ�2�����п�ʼ
    for(int j=i; j<=M-(N-i); j++) //��i��������Ҫ�ڵ�i��,����������M-(N-i)��
    {
      int Min=INF;
      for(int k=j-1; k>=i-1; k--)
        Min=min(Min,f[i-1][k]);
      f[i][j]=Min+D[i]*C[j];//����ټ�D[i]*C[j]�����Ż�ʱ��
    }
  int ans=INF;
  for(int i=N; i<=M; i++)
    ans=min(ans,f[N][i]);
  printf("%d",ans);
  return 0;
}
