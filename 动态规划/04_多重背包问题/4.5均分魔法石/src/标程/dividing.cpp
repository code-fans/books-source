//����ħ��ʯ
//������Ϊ����Ȼ���ܣ�ż��ʱֻҪ�ﵽsum/2�ı��������ˣ�
//ʣ�µ���Ȼ���������sum/2�ı�����
//��֪�������ر������Ӷ�ΪO((��N[i])V),����(��N[i])<=120000,V<=60000;
//���ֱ�ӽ��ж��ر����϶���ʱ�����������ö������Ż��Ķ��ر�����
#include <bits/stdc++.h>
using namespace std;

int num[7],dp[60010];
int dig[]= {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

int main()
{
  //freopen("dividing.in","r",stdin);
  //freopen("dividing.out","w",stdout);
  for(int ncase=1; ; ncase++)
  {
    int  sum = 0;
    for(int i=1; i<=6; i++)
    {
      scanf("%d",&num[i]);
      sum += i*num[i];
    }
    if(sum == 0)
      break;
    printf("Collection #%d:\n",ncase);
    if(sum&1)
    {
      printf("Can't be divided.\n\n");
      continue;
    }
    memset(dp,0,sizeof(dp));
    sum/=2;
    for(int i=1,v; i<=6; i++)
      for(int d=0; num[i]; d++)
      {
        if(num[i] >= dig[d])
        {
          v = i*dig[d];
          num[i] -= dig[d];
        }
        else
        {
          v = i*num[i];
          num[i] = 0;
        }
        for(int j=sum; j>=v; j--)
          dp[j] = max(dp[j],dp[j-v]+v);
      }
    if(dp[sum] == sum)
      printf("Can be divided.\n\n");
    else
      printf("Can't be divided.\n\n");
  }
  return 0;
}
