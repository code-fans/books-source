//������� ���߾���
//�ڶ��ʣ�����5 3 1 5 3 1 �������ظ������Զ���num[],num[i]��ʾ��a[i]Ϊ��β��LIS������ͬ��������
//������ɨ������У��������LIS������ͬ��������ַ�һ���ģ�������ͳ�ƾͿ�
#include<bits/stdc++.h>
using namespace std;

int n,mx;
int a[5005]= {0x7ffffff}; //a[0]=OO
int dp[5005];             //dp[0]==0
string num[5005]= {"1"};  //num[0]=1  num[i]:��a[i]Ϊ��β��LIS������ͬ��������

string Add(string a,string b)
{
  string ans(max(a.size(),b.size())+1,'0');//��ans�ĳ��ȣ���ȫ�����0
  for(int i=ans.size()-1,l1=a.size(),l2=b.size(); i>=0; i--)//�������
  {
    int t=(ans[i]-'0')+(l1<1?0:a[--l1]-'0')+(l2<1?0:b[--l2]-'0');//ת��������λ���
    ans[i]=t%10+'0';//����תΪ�ַ�����
    ans[i-1]=(ans[i-1]-'0'+t/10)+'0';//��λ
  }
  for(; ans[0]=='0' && ans.size()>1; ans.erase(0,1));//ɾ��ǰ��0
  return ans;
}

int main()
{
  freopen("shares.in","r",stdin);
  freopen("shares.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  for(int i=1; i<=n; i++)
  {
    for(int j=i-1; j>=0; j--)            //���������
      if(a[j]>a[i] && dp[i]<=dp[j])
        dp[i]=dp[j]+1;
    for(int j=i-1; j>=0; j--)
    {
      if(a[j]>a[i] && dp[j]+1==dp[i])    //���ǰ��ĵ��Ӵ��������ϵ�ǰ��a[i]�Ҳ�һ�������
        num[i]=Add(num[i],num[j]);       //����a[i]��β����ͬ���ȵķ�����ͳ�Ƶ�num[i]��
      else if(a[i]==a[j] && dp[i]==dp[j])//���һ���ľ�ֹͣ����ֹͣͳ�ƣ������ظ�
        break;                           //���治��������������
    }
  }
  string nums="0";
  for(int i=1; i<=n; i++)
    if(mx<dp[i])
    {
      mx=dp[i];
      nums=num[i];
    }
    else if(mx==dp[i])
      nums=Add(nums,num[i]);
  cout<<mx<<" "<<nums<<endl;
  return 0;
}
