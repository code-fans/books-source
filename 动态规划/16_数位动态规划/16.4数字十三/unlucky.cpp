//数字十三
#include <bits/stdc++.h>
using namespace std;
const int N=12;

int md[12]= {1},dp[12][13][3]; //当前位，模13的值,无13/有3/有13

void Init()
{
  for(int i=1; i<N; i++)
    md[i]=((md[i-1]<<3)+(md[i-1]<<1))%13; //求1,10,100,1000,10000%13的余数
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(int i=0; i<N-1; i++)                      //枚举每一位
    for(int j=0; j<13; j++)                     //枚举模13的值
    {
      for(int k=0; k<10; k++)                   //在i+1位的k取0~9
      {
        dp[i+1][(j+md[i]*k)%13][0]+=dp[i][j][0];//第i位不包含13的数前面加k
        dp[i+1][(j+md[i]*k)%13][2]+=dp[i][j][2];//i位含13的数前面加k
      }
      dp[i+1][(j+md[i])%13][0]-=dp[i][j][1];//要减去i-1位为3的数，因为i位可能为1
      dp[i+1][(j+md[i]*3)%13][1]+=dp[i][j][0];//求3开头的数
      dp[i+1][(j+md[i])%13][2]+=dp[i][j][1];//求含13的数,i位为3的前加1
    }
}

int Count(int n)
{
  int digit[11]= {0},len=0,ans=0,mod=0;
  for(int i=n; i; i/=10)                    //拆数
    digit[len++]=i%10;
  bool flag=false;
  for(int i=len-1; i>=0; mod=(mod+digit[i]*md[i])%13,i--)
  {
    for(int j=0; j<digit[i]; j++)   //枚举当前位j的值
      ans+=dp[i][(13-(mod+j*md[i])%13)%13][2];
    if(flag)                        //已出现包含13的情况
    {
      for(int j=0; j<digit[i]; j++) //无论后面再添什么数都包含13
        ans+=dp[i][(13-(mod+j*md[i])%13)%13][0];
      continue;
    }
    if(digit[i+1]==1 && digit[i]>3)//i+1位取1，i位取3的情况
      ans+=dp[i+1][(13-mod)%13][1];
    if(digit[i]>1)
      ans+=dp[i][(13-(mod+md[i])%13)%13][1];
    if(digit[i+1]==1 && digit[i]==3)//出现包含13的情况则标记
      flag=true;
  }
  return ans;
}

int main()
{
  freopen("unlucky.in","r",stdin);
  freopen("unlucky.out","w",stdout);
  Init();
  int n;
  while(~scanf("%d",&n))
    printf("%d\n",Count(n+1));
  return 0;
}
