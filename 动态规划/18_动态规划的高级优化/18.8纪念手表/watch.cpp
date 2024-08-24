//�����ֱ�
#include <bits/stdc++.h>
using namespace std;

bool dp[100005];
int ans,n,m;
int a[150],c[150],que[100005];

inline int Read(int x=0)                 //���ַ�����ʽ�������ֿ�����
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
  return x;
}

void Dp()
{
  dp[0] = true;
  for(int i = 1; i <= n ; i ++)
  {
    if(c[i] == 1)                               //01����
    {
      for(int s = m ; s>=a[i]; s-- )
        if(!dp[s] && dp[s-a[i]])
          dp[s] = true;
    }
    else if(a[i]*c[i]>=m)                       //��ȫ����������
    {
      for(int s = a[i]; s<=m ; s++)
        if(!dp[s] && dp[s-a[i]])
          dp[s] = true;
    }
    else
      for(int b = 0 ; b < a[i]; b++)            //�����Ż�,ö������
      {
        int head = 1,tail = 1;
        for(int t=0; t*a[i]+b<=m; t++)          //ö��Ӳ�Ҹ���
        {
          while(head<tail && t-que[head]>c[i])  //��i��Ӳ��ȫ����Ҳ�޷�ת�Ƶ�t 
            head++;                             //���׵��������ϵ�Ԫ��
          if(dp[t*a[i]+b])                      //DPֵΪ��,�����Ż������ֵ 
            que[tail++]=t;                      //����Ӳ�Ҹ������
          else if(head<tail)                    //������������Ԫ�� 
            dp[t*a[i]+b] = true;                //����ת��
        }
      }
  }
}

int main()
{
  freopen("watch.in","r",stdin);
  freopen("watch.out","w",stdout);
  while(cin>>n>>m && n>0)
  {
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n ; i ++)  //������ֵ
      a[i] = Read();
    for(int i = 1; i <= n ; i ++)  //��������
      c[i] = Read();
    Dp();
    ans=0;
    for(int i = 1; i <= m ; i ++)
      if(dp[i])
        ans++;
    printf("%d\n",ans);
  }
  return 0;
}

