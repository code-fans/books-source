//��ʯ���
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL  n,m,s;
LL  Sum[200005],Sumv[200005];
int Value[200005],Weight[200005];
int ST[200005],END[200005];               //��������

void PreSum(LL S)                         //����ǰ׺��
{
  Sum[0]=Sumv[0]=0ll;                     //long long�͸�ֵ����Ҫ��ll
  for(int i=1; i<=n; i++)
    if(Weight[i]>=S)
    {
      Sum[i]=Sum[i-1]+1;                  //ǰ׺�ͼ���
      Sumv[i]=Sumv[i-1]+Value[i];
    }
    else
      Sumv[i]=Sumv[i-1],Sum[i]=Sum[i-1];
}

LL Calc(LL MID)                           //�����ֵ
{
  LL ans=0ll;
  for(int i=1; i<=m; i++)
    ans+=(Sum[END[i]]-Sum[ST[i]-1])*(Sumv[END[i]]-Sumv[ST[i]-1]);
  return ans;
}

int main()
{
  //freopen("qc.in","r",stdin);
  //freopen("qc.out","w",stdout);
  scanf("%lld %lld %lld",&n,&m,&s);
  LL Start=0ll,End=0ll;                   //�Ͻ���½�, long long�͸�ֵ����Ҫ��ll
  for(int i=1; i<=n; ++i)
  {
    scanf("%d %d",&Weight[i],&Value[i]);
    End=max(LL(Weight[i]),End);           //�ҳ����ص�,�Ƚϵ���������ΪLL����
  }
  for(int i=1; i<=m; ++i)
    scanf("%d %d",&ST[i],&END[i]);
  LL Ans=pow(2,63)-1;                     //�����ֵ9223372036854775807
  while(Start<=End)                       //���ֲ���
  {
    LL Mid=(Start+End)>>1;
    PreSum(Mid);                          //����ǰ׺��
    Ans=min(Ans,abs(Calc(Mid)-s));        //����Ans,�Ծ����ܱƽ���Сֵ
    if(Ans==0)
      break;
    s<Y ? Start=Mid+1:End=Mid-1;
  }
  printf("%lld\n",Ans);
  return 0;
}

