#include<bits/stdc++.h>
using namespace std;

long long a,b;
long long POW[20]= {1},dp[20],A[20],B[20];

void Count(long long x,long long *cnt,int len=0)
{
  long long digit[20]= {0};
  for(; x; x/=10)              //������ֵ�digit[]
    digit[++len]=x%10;
  for(int i=len; i>=1; i--)    //�Ӹ�λ����λö��
  {
    for(int j=0; j<=9; j++)    //������ǰ��0,ͳ��ÿ�����ֳ��ִ���
      cnt[j]+=dp[i-1]*digit[i];
    for(int j=0; j<digit[i]; j++)//��ǰ��һλ��Ϊj
      cnt[j]+=POW[i-1];
    long long num=0;
    for(int j=i-1; j>=1; j--)  //������λ��,��λ��x,����x000~xBCDҪͳ��
      num=(num<<3)+(num<<1)+digit[j];
    cnt[digit[i]]+=num+1;      //����Ҫ��BCD+1
    cnt[0]-=POW[i-1];          //��ȥǰ��0�����0
  }
}

int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%lld %lld",&a,&b);
  for(int i=1; i<=15; i++)
  {
    dp[i]=(dp[i-1]<<3)+(dp[i-1]<<1)+POW[i-1];
    POW[i]=(POW[i-1]<<3)+(POW[i-1]<<1);
  }
  Count(a-1,A);//ͳ��0~a-1��ÿ�������ִ�������A[]
  Count(b,B);  //ͳ��0~b��ÿ�������ִ�������B[]
  for(int i=0; i<=9; i++)
    printf("%lld ",B[i]-A[i]);//ǰ׺��˼��
  return 0;
}
