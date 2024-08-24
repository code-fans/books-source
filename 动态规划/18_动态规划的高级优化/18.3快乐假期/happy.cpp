/*
���ּ���
DP+��������.
����һ��ǰ׺��sum.
Ҫ��ans=sum[i]-min{sum[k]}(i-Q<=k<=i-P)
Ҫʹans���,��sum[k]��С
��������ά�������������䱣��sum��ֵ��ÿ�ζ���ȡ����Сֵ
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define LL long long

LL n,ans=-1e18,head,tail,P,Q;
LL q[MAXN],sum[MAXN];

inline LL Read(LL x=0)                   //���ַ�����ʽ�������ֿ�����
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
  return x;
}

int main()
{
  //freopen("happy.in","r",stdin);
  //freopen("happy.out","w",stdout);
  n=Read();
  P=Read();
  Q=Read();
  for(int i=1; i<=n; i++)
  {
    sum[i]=Read();
    sum[i]+=sum[i-1];            //ǰ׺��
  }
  for(int i=P; i<=n; i++)        //��P��ʼ
  {
    while(head<tail && sum[i-P]<sum[q[tail-1]])//�������� 
      tail--;
    q[tail++]=i-P;               //�������,��Ϊ��p��ʼ������-p 
    while(head<tail&&i-q[head]>Q)  //�������г��Ȳ�����Q 
      head++;
    ans=max(ans,sum[i]-sum[q[head]]);
  }
  printf("%lld\n",ans);
  return 0;
}
