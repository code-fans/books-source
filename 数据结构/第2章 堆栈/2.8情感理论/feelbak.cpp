#include <bits/stdc++.h>
using namespace std;
int pos[100005],n;//pos��¼Ԫ���������е�ԭʼλ��
long long Stack[100005],sum[100005];

int main()
{
  //freopen("feel.in","r",stdin);
  //freopen("feel.out","w",stdout);
  int i,s=0,t=0,top=0;
  long long a,ans=0;
  scanf("%d",&n);
  for (i=1; i<=n ; i++ )
  {
    scanf("%lld",&a);
    sum[i]=sum[i-1]+a;                            //�����к�
    while (top && a<=Stack[top])                  //ջδ������Ԫ�ر�ջԪ��С
    {
      if (ans<(sum[i-1]-sum[pos[top-1]])*Stack[top])
      {
        ans=(sum[i-1]-sum[pos[top-1]])*Stack[top];//���½��
        s=pos[top-1]+1;                           //ȷ����߽�
        t=i-1;                                    //ȷ���ұ߽�
      }
      top--;//��ջ
    }
    top++;
    Stack[top]=a;                                 //��ջ
    pos[top]=i;                                   //��¼��ԭʼλ��
  }
  while (top)                                     //ͳ��ջ��ʣ���Ԫ��
  {
    if (ans<=(sum[n]-sum[pos[top-1]])*Stack[top])//������<=���У�Ϊʲô��
    {
      ans=(sum[n]-sum[pos[top-1]])*Stack[top];
      s=pos[top-1]+1;
      t=n;
    }
    top--;
  }
  printf("%lld\n%d %d\n",ans,s,t);
  return 0;
}

