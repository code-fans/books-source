//���ҵĶ���
#include <bits/stdc++.h>
using namespace std;

int N,K;
int a[17];
long long dp[16][1<<16];

int main()
{
  freopen("emmm.in","r",stdin);
  freopen("emmm.out","w",stdout);
  scanf("%d%d",&N,&K);
  for(int i=0; i<N; i++)
    scanf("%d",&a[i]);
  for(int i=0; i<N; i++)
    dp[i][1<<i]=1;                               //��ʼֻ��һֻ��ţ�ķ�����Ϊ1
  for(int state=0; state<(1<<N); state++)        //ö������״̬
    for(int j=0; j<N; j++)                       //ö��ĩβ���ܵ���ţ
      if(state & (1<<j))                         //�������ţ�����ڴ�״̬��
        for(int i=0; i<N; i++)                   //ö��ĩβҪ�������ţi
          if(!(state&(1<<i)) && abs(a[j]-a[i])>K)//�������ţ֮ǰû�зŲ��ҿɷ�
            dp[i][state|(1<<i)]+=dp[j][state];   //�������ţkΪĩβ�ķ�����
  long long ans=0;
  for (int i=0; i<N; i++)
    ans+=dp[i][(1<<N)-1];                        //�ۼӻ��ҵķ�����
  printf("%lld\n",ans);
  return 0;
}
