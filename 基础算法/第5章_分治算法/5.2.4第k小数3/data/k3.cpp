//��kС��3  - ����2
#include <bits/stdc++.h>
using namespace std;

long long a[109999],b[109999];
long long n,m;

long long Cal(long long MID)         //����x���������е�������
{
  long long Mid,Min,Max,Cnt=0;
  for(int i=1; i<=n; i++)
  {
    Min=a[i]+b[1];                   //�Ͻ�
    Max=a[i]+b[m];                   //�½�
    if(MID<Min)                      //���������е������Ͷ���MIDҪ��
      break;                         //�����ۼӣ�������ѭ��
    if(MID>=Max)                     //���������е������Ͷ���MIDҪС
    {
      Cnt+=m;                        //���ۼ�m
      continue;
    }
    long long ll=1,rr=m;
    while(ll<=rr)                    //���ֿ��ٶ�λ
    {
      Mid=(ll+rr)>>1;
      MID<a[i]+b[Mid]?rr=Mid-1:ll=Mid+1;
    }
    if(MID!=(a[i]+b[ll]))            //��������ȷ��λ��
      ll--;
    Cnt+=ll;
  }
  return Cnt;
}

long long FindKth(long long ll,long long rr,long long k)
{
  long long Mid;
  while(ll<=rr)
  {
    Mid=(ll+rr)>>1;
    k<=Cal(Mid)?rr=Mid-1:ll=Mid+1;
  }
  return ll;
}

int main()
{
  freopen("k3.in","r",stdin);
  freopen("k3.out","w",stdout);
  long long k;
  while(scanf("%lld%lld%lld",&n,&m,&k)!=EOF)
  {
    for(int i=1; i<=n; i++)
      scanf("%lld",&a[i]);
    for(int i=1; i<=m; i++)
      scanf("%lld",&b[i]);
    printf("%lld\n",FindKth(a[1]+b[1],a[n]+b[m],k));
  }
  return 0;
}

