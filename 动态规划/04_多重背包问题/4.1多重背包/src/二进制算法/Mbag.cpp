//���ر��� - �������Ż��㷨
#include <bits/stdc++.h>
using namespace std;

int dp[201],c[50],w[50];

int main()
{
  freopen("Mbag.in","r",stdin);
  freopen("Mbag.out","w",stdout);
  int V, N,count=0;
  scanf("%d%d",&V,&N);
  for(int i=0,s,v,n; i<N; ++i)
  {
    scanf("%d%d%d",&s,&v,&n);
    for(int j=1; j<=n; j<<=1)         //j����һλ�����ж����Ʋ��
    {
      c[count]=j*s;                   //�ռ������Ӧ�Ķ�����ϵ��
      w[count++]=j*v;                 //��ֵ������Ӧ�Ķ�����ϵ��
      n-=j;
    }
    if(n>0)                           //ʣ��δ��ֵ�
    {
      c[count]=n*s;
      w[count++]=n*v;
    }
  }
  for(int i=0; i<count; ++i)          //01����
    for(int j=V; j>=c[i]; --j)
      dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
  printf("%d\n",dp[V]);
  return 0;
}

