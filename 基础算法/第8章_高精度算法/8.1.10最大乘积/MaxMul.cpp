//���˻�
//�˻�����Ӧ�����ܽ�n����Ĳ�֣�1�϶����У���2��ʼ
//��2��3��4��5��6...�������n,��ȥ����������ɣ��ٸ߾���
#include<bits/stdc++.h>
using namespace std;

int len=1,sum,num,n;
int a[10001],ans[10001]= {0,1};//�߾��������ʼΪ1

void Mul(int x)
{
  for(int i=1; i<=len; i++)
    ans[i]=ans[i]*x;
  for(int i=1; i<=len; i++)
    if(ans[i]>=10)
    {
      ans[i+1]+=ans[i]/10;
      ans[i]=ans[i]%10;
      len=max(i+1,len);
    }
}

int main()
{
  freopen("MaxMul.in","r",stdin);
  freopen("MaxMul.out","w",stdout);
  cin>>n;
  for(int i=2; n>a[num]; i++)
  {
    a[++num]=i;
    n-=i;
  }
  if(n==a[num])           //���ʣ�µ��������һ������Ԫ��ֵ���
    a[num]++;             //���һ������Ԫ��ֵ+1
  for(int i=0; i<n; i++)  //ʣ�µ��������ÿ������Ԫ��+1
    a[num-i]++;
  for(int i=1; i<=num; i++)
    if(a[i])
    {
      cout<<a[i]<<(i==num?'\n':' ');
      Mul(a[i]);
    }
  for(int i=len; i>=1; i--)
    cout<<ans[i];
  cout<<endl;
  return 0;
}
