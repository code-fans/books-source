//������� ��ʹ����long double ����߾���
//�ڶ��ʣ�����5 3 1 5 3 1 �������ظ������Զ���num[],
//num[i]��ʾ��a[i]Ϊ��β��LIS������ͬ��������
//������ɨ������У��������LIS������ͬ��������ַ�һ���ģ�������ͳ�ƾͿ�
#include<bits/stdc++.h>
using namespace std;

int n,mx;
int a[5005]= {0x7ffffff}; //a[0]=OO
int dp[5005];             //dp[0]==0
long double num[5005]= {1}; //num[0]=1  num[i]:��a[i]Ϊ��β��LIS������ͬ��������

int main()
{
  freopen("shares.in","r",stdin);
  freopen("shares.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  for(int i=1; i<=n; i++)
  {
    for(int j=i-1; j>=0; j--) //���������
      if(a[j]>a[i] && dp[i]<=dp[j])
        dp[i]=dp[j]+1;
    for(int j=i-1; j>=0; j--)
    {
      if(a[j]>a[i] && dp[j]+1==dp[i])//���ǰ��ĵ��Ӵ��������ϵ�ǰ��a[i]�Ҳ�һ�������
        num[i]+=num[j];              //����a[i]��β����ͬ���ȵķ�����ͳ�Ƶ�num[i]��
      else if(a[i]==a[j] && dp[i]==dp[j])//���һ���ľ�ֹͣ����ֹͣͳ�ƣ������ظ�
        break;                           //���治��������������
    }
  }
  long double nums=0;
  for(int i=1; i<=n; i++)
    if(mx<dp[i])
    {
      mx=dp[i];
      nums=num[i];
    }
    else if(mx==dp[i])
      nums+=num[i];
  cout<<mx<<" "<<setprecision(0)<<fixed<<nums<<endl;
  return 0;
}
