//���� �߾��˸߾�
#include <bits/stdc++.h>
using namespace std;
const int Max=1010;
string ss[1010];

int x[Max],K[Max],z[Max],sum[Max],len;

void Add(int x[],int ans[],int len)
{
  for(int j=0; j<len; ++j)
  {
    ans[j]+=x[j];
    for(int i=j; ans[i]>=10; ++i)
    {
      ans[i+1]++;
      ans[i]-=10;
    }
  }
}

void Init(int x[],string str, int len) //�ַ�������ת��Ϊ��������
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';
}

void Output(int ans[])                 //�����ӵĽ��
{
  int i=Max-1;
  for(; ans[i]==0 && i>0; i--);        //����ǰ��0
  for(; i>=0; i--)
    printf("%d",ans[i]);
  printf("\n");
}

void Mul(int a[],int b[],int c[])
{
  for(int i=0; i<Max; ++i)             //��һ���ˡ�
  {
    for(int j=Max-1; j>=0; --j)        //�ڶ�������
      c[j+i]+=b[i]*a[j];               //ע��˻������λ��
    for(int k=0; k<Max; ++k)
      if(c[k]>=10)
      {
        c[k+1]+=c[k]/10;
        c[k]%=10;
      }
  }
}

int main()
{
  //freopen("chat.in","r",stdin);
  //freopen("chat.out","w",stdout);
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>ss[i];
    int x[Max]= {0};
    Init(x,ss[i],ss[i].size());
    Add(x,sum,ss[i].size());
  }
  int k=(n-1)*(n-2)>>1;//����k*�����м�ֵ�ͣ���k�����õȲ�������
  for(int i=0; k!=0; i++)//��KתΪ�ַ�����
  {
    K[i]=k%10;
    k/=10;
  }
  Mul(sum,K,z);
  Output(z);
  return 0;
}

