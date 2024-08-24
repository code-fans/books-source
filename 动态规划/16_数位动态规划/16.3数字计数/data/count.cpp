#include<bits/stdc++.h>
using namespace std;

long long a,b;
long long POW[20]= {1},dp[20],A[20],B[20];

void Count(long long x,long long *cnt,int len=0)
{
  long long digit[20]= {0};
  for(; x; x/=10)              //拆分数字到digit[]
    digit[++len]=x%10;
  for(int i=len; i>=1; i--)    //从高位往低位枚举
  {
    for(int j=0; j<=9; j++)    //不考虑前导0,统计每个数字出现次数
      cnt[j]+=dp[i-1]*digit[i];
    for(int j=0; j<digit[i]; j++)//当前这一位数为j
      cnt[j]+=POW[i-1];
    long long num=0;
    for(int j=i-1; j>=1; j--)  //例如四位数,首位是x,还有x000~xBCD要统计
      num=(num<<3)+(num<<1)+digit[j];
    cnt[digit[i]]+=num+1;      //所以要加BCD+1
    cnt[0]-=POW[i-1];          //减去前导0多余的0
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
  Count(a-1,A);//统计0~a-1，每个数出现次数存入A[]
  Count(b,B);  //统计0~b，每个数出现次数存入B[]
  for(int i=0; i<=9; i++)
    printf("%lld ",B[i]-A[i]);//前缀和思想
  return 0;
}
