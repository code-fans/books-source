//�����Ƽ�����Ϸ
//����Ϊi�Ķ��������ɷ�Ϊ��iλΪ0�͵�iλΪ1�����ࡣ��F[i][j]��ʾ
//���г���Ϊi�ģ�1�ĸ���������j�Ķ�������������������Ȼ�е��ƹ�ʽ��
//F[i][j]=f[i��1][j]+f[i��1][j��1]
//��ʼ�������߽�������Ϊ��
//F[0][j]=1��F[j][0]=1������j��0
//��Ȼ���Ե��Ƴ������

#include <bits/stdc++.h>
using namespace std;
const int M=65;
long long n,s,t;
long long f[M][M];

long long cal(long long x)                //����0~x֮���ж��ٷ���Ҫ�����
{
  int len,b[M];
  for(len=0; x>0; x/=2)              //תΪ��������
    b[len++]=x%2;
  long long ans=0;
  /*
  ����x=1001000��n=3ʱ����Ҫ�ۼ�f[6][3]��f[[3][2]��ֵ
  f[6][3]�Ǽ������λΪ0������6λ��3��1�����
  f[3][2]�Ǽ������λΪ1�������λֻʣ2��1���õ����
  */
  for(int i=0,c=0; i<len &&  c<n; ++i)   //cͳ��n�ĸ���
    if(b[len-i-1]==1)
    {
      ans+=f[len-i-1][n-c];
      c++;
    }
  return ans;
}

int main()
{
//  freopen("num.in","r",stdin);
//  freopen("num.out","w",stdout);
  cin>>n>>s>>t;
  for(int i=0; i<M; ++i)
    f[i][0]=1,f[0][i]=1;
  for(int i=1; i<M; ++i)
    for(int j=1; j<M; ++j)
      f[i][j]=f[i-1][j]+f[i-1][j-1];
  cout<<cal(t)-cal(s-1)<<endl;
  return 0;
}

