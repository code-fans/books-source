#include <bits/stdc++.h>
using namespace std;
const int MAXN=51;

int n,k,f[MAXN]= {0,1},stamp[MAXN],MAX;

void Dfs(int idx)
{
  if(idx>k)                               //������Ʊ��������
  {
    int dp[5100]= {0};
    int i=0;
    while(dp[i]<=n)                       //���֮ǰ����Ʊ������n��������,��û��Ҫ������
    {
      i++;                                //�¸�λ��
      dp[i]=0x3f3f3f3f;                   //dp[i]��ʾ��֪��ֵ����Ʊ��ϳ���ֵΪi����Ҫ����С��Ʊ��
      for(int j=1; j<=k && i-f[j]>=0; j++)//ö��k����Ʊ,���ҿ��Գ���������Ʊ
        dp[i]=min(dp[i],dp[i-f[j]]+1);
    }
    if(i-1>MAX)
    {
      memcpy(stamp,f,sizeof(f));          //���Ƶ�ǰ�����Ž�
      MAX=i-1;
    }
    return;
  }
  for(int i=f[idx-1]+1; i<=f[idx-1]*n+1; i++)
  {
    f[idx]=i;                               //������һ����ֵ
    Dfs(idx+1);
  }
}

int main()
{
  scanf("%d%d",&n,&k);
  Dfs(2);                                   //��һ����Ʊ��1,�ӵڶ�����Ʊ��ʼ
  for(int i=1; i<=k; i++)
    printf("%d ",stamp[i]);
  printf("\nMAX=%d\n",MAX);
  return 0;
}
//����1
//��n=3,k=3Ϊ��:��һ����ֵ�϶�Ϊ1�����ǵڶ�����ֵֻ����2��3��4����Ϊ��ֵΪ1�������3��
//���������ֵΪ3��Ҫ��֤��������,��ô�ڶ������������4
//�������ǿ��Եõ����ɣ������Ʊ����Ϊn������Ϊk,��ô��С�����˳����Ʊa[i]����һ����ֵ��ȡֵ��Χ��Ȼ��f[i]+1��f[i]*n+1
