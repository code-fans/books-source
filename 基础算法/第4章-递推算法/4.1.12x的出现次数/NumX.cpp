//�磺
//n=728��x=7
//���԰���������˼·��
//��λ7:73�� 7,17,...,727
//ʮλ7:70�� 70~79,170~179,...,670~679
//��λ7:29�� 700~728
//����172

#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("NumX.in","r",stdin);
  //freopen("NumX.out","w",stdout);
  long long n,x,m=1,ans=0;
  scanf("%lld%lld",&n,&x);
  while(m<=n)
  {
    int L=n/(m*10),P=n/m%10,R=n%m;
    if(x)                          //x��Ϊ0ʱ
      if(P>x)//���P>x��˵����(L+1)*m��x������1~728�и�λ7�ĸ�������Ϊ��72+1��*1=73��
        ans+=(L+1)*m;
      else if(P==x)
        ans+=L*m+R+1; //���P=x��˵����L*m+R+1��x������1~728�а�λ7�ĸ�������Ϊ0*100+28+1=29��
      else
        ans+=L*m; //���P<x��˵����L*m��x������1~728��ʮλ7�ĸ�������Ϊ7*10����
    else  //x=0�������x��=0�����������ͬ
      ans+=P?L*m:(L-1)*m+R+1;
    m*=10;
  }
  printf("%lld\n",ans);
  return 0;
}
