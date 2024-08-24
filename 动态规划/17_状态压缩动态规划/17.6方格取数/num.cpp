//����ȡ��
#include <bits/stdc++.h>
using namespace std;

int a[22][22];
int dp[22][20000], sum[22][20000];  //��ʾ��i��ʹ�õ�j�ַ����õ������ֵ,��
int state[20000];                   //��ʾ���е�״̬�������е�ȡ������
int len, n;

int GetSum(int pos, int x)          //���pos�У�ʹ��x������ȡ�õĺ�
{
  int sum=0;
  for(int cnt=n-1; x; x>>=1)
    sum+=(x&1)*a[pos][cnt--];       //Ҫ���߲�Ҫ��01��ʾ�����԰�ԭֵ���
  return sum;
}

void Init(int m)
{
  len=0;
  for(int i=0; i<(1<<m); i++)        //Ԥ�����һ�е����з���
    if((i&(i<<1))==0)
      state[len++]=i;
  for(int i=0; i<n; i++)
    for(int j=0; j<len; j++)
      sum[i][j]=GetSum(i, state[j]);//��i�У�����j���ܺ�
  memset(dp, 0, sizeof(dp));
  for(int i=0; i<len; i++)
    dp[0][i]=sum[0][i];
}

int main()
{
  freopen("num.in","r",stdin);
  freopen("num.out","w",stdout);
  while(cin>>n)
  {
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    Init(n);
    for(int i=1; i<n; i++)            //�����i��
      for(int j=0; j<len; j++)        //��ȡ��j�ַ���
        for(int k=0; k<len; k++)      //ö����һ������ȡ�ķ���k
          if((state[j] & state[k])==0)//���·�������ͻ
            dp[i][j]=max(dp[i][j], dp[i-1][k]+sum[i][j]);//״̬ת�Ʒ���
    int ans = 0;
    for(int i = 0; i < len; i++)      //�ҳ����ֵ
      if(dp[n-1][i]>ans)
        ans = dp[n-1][i];
    cout<<ans<<endl;
  }
  return 0;
}
