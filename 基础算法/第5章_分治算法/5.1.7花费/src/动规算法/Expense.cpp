//���ѣ������㷨
//��̬ת�Ʒ���
//f[i][j]=min(f[i-1][k],sum[j]-sum[k])�� f[i][j]��ʾ�ֳ�i�ݣ�����j��Ľ�
//Ч�ʲ�����ַ�
#include <bits/stdc++.h>
using namespace std;

int f[1000][1000];
int sum[10000],money[10000];

int main()
{
  freopen("Expense.in","r",stdin);
  freopen("Expense.out","w",stdout);
  int n,m;
  while(~scanf("%d%d",&n,&m) && n)
  {
    memset(f,0,sizeof(f));
    memset(sum,0,sizeof(sum));
    memset(money,0,sizeof(money));
    for(int i=1; i<=n; i++)
    {
      scanf("%d",&money[i]);
      f[1][i]=f[1][i-1]+money[i];       //�߽�����
      sum[i]=sum[i-1]+money[i];         //ǰ׺��
    }
    for(int M=2; M<=m; M++)
    {
      int maxn=-1;
      for(int day=1; day<=M; ++day)
        maxn=max(money[day],maxn);
      for(int day=1; day<=M; ++day)
        f[M][day]=maxn;
      for(int LastDay=M+1; LastDay<=n; ++LastDay)
      {
        int minx=0x7fffffff;
        for(int day=M-1; day<LastDay; ++day)
        {
          int t=max(f[M-1][day],sum[LastDay]-sum[day]);//�������Сֵ
          minx=min(t,minx);
        }
        f[M][LastDay]=minx;
      }
    }
    printf("%d\n",f[m][n]); //m��,n��
  }
  return 0;
}

