//�������
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll st[100100],a[100100],sum[100100];                 //st:��ջ���±꣬sum:ǰ׺��
int n,top,l,r;

int main()
{
  freopen("feel.in","r",stdin);
  freopen("feel.out","w",stdout);
  scanf("%d", &n);
  for (int i=1; i<=n; i++)                           //���±�1��ʼ����
  {
    scanf("%lld", &a[i]);
    sum[i]=sum[i-1]+a[i];
  }
  a[n+1]=-1;                                         //���-1��֤ȫ����ջ 
  ll tmp,ans=-1;
  for (int i=1; i<=n+1; i++)
  {
    for(; top!=0 && a[st[top]]>a[i]; top--)          //ά������ջ
    {
      tmp=(sum[i-1]-sum[st[top-1]])*a[st[top]]; //��Ϊ֮ǰ������Ķ�����ȥ��,������ߵ�ֵ���ǵ�һ������С���±� 
      if(tmp>ans)
      {
        ans=tmp;
        l=st[top-1]+1;                          //��ô��һ������С���±���ұ�һ����������߽���            
        r=i-1;
      }
    }
    st[++top]=i;                                //����������ջ��ֵ��ջ,���±�
  }
  printf("%lld\n%d %d\n",ans,l,r);
  return 0;
}
