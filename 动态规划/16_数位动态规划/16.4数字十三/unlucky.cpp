//����ʮ��
#include <bits/stdc++.h>
using namespace std;
const int N=12;

int md[12]= {1},dp[12][13][3]; //��ǰλ��ģ13��ֵ,��13/��3/��13

void Init()
{
  for(int i=1; i<N; i++)
    md[i]=((md[i-1]<<3)+(md[i-1]<<1))%13; //��1,10,100,1000,10000%13������
  memset(dp,0,sizeof(dp));
  dp[0][0][0]=1;
  for(int i=0; i<N-1; i++)                      //ö��ÿһλ
    for(int j=0; j<13; j++)                     //ö��ģ13��ֵ
    {
      for(int k=0; k<10; k++)                   //��i+1λ��kȡ0~9
      {
        dp[i+1][(j+md[i]*k)%13][0]+=dp[i][j][0];//��iλ������13����ǰ���k
        dp[i+1][(j+md[i]*k)%13][2]+=dp[i][j][2];//iλ��13����ǰ���k
      }
      dp[i+1][(j+md[i])%13][0]-=dp[i][j][1];//Ҫ��ȥi-1λΪ3��������Ϊiλ����Ϊ1
      dp[i+1][(j+md[i]*3)%13][1]+=dp[i][j][0];//��3��ͷ����
      dp[i+1][(j+md[i])%13][2]+=dp[i][j][1];//��13����,iλΪ3��ǰ��1
    }
}

int Count(int n)
{
  int digit[11]= {0},len=0,ans=0,mod=0;
  for(int i=n; i; i/=10)                    //����
    digit[len++]=i%10;
  bool flag=false;
  for(int i=len-1; i>=0; mod=(mod+digit[i]*md[i])%13,i--)
  {
    for(int j=0; j<digit[i]; j++)   //ö�ٵ�ǰλj��ֵ
      ans+=dp[i][(13-(mod+j*md[i])%13)%13][2];
    if(flag)                        //�ѳ��ְ���13�����
    {
      for(int j=0; j<digit[i]; j++) //���ۺ�������ʲô��������13
        ans+=dp[i][(13-(mod+j*md[i])%13)%13][0];
      continue;
    }
    if(digit[i+1]==1 && digit[i]>3)//i+1λȡ1��iλȡ3�����
      ans+=dp[i+1][(13-mod)%13][1];
    if(digit[i]>1)
      ans+=dp[i][(13-(mod+md[i])%13)%13][1];
    if(digit[i+1]==1 && digit[i]==3)//���ְ���13���������
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
