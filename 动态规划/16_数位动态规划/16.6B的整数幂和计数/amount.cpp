#include <bits/stdc++.h>
using namespace std;

int c[35][35];
int X,Y,k,b;

void Init()
{
  c[0][0]=1;
  for (int i=1; i<=32; i++)
  {
    c[i][0]=c[i-1][0];
    for (int j=1; j<=i; j++)
      c[i][j]=c[i-1][j]+c[i-1][j-1];
  }
}

int Cal(int n)
{
  int a[100],len=0,cnt=0,ans=0;
  for(; n; n/=b)     //���B������
    a[len++]=n%b;
  cout<<len<<endl;
  for (int i=len-1; i>=0; i--)//�Ӹ�λ����λɨ��
  {
    if (a[i]==1)     //���Ϊ1�����μ���
    {
      ans+=c[i][k-cnt];
      cout<<"=C"<<i<<","<<k-cnt<<' '<<c[i][k-cnt]<<endl;
      cnt++;
      if (cnt==k)    //�Ѿ����㹻��1��
        break;
    }
    else if (a[i]>1) //��һ����0/1����������ȫ����Ϊ1
    {
      ans+=c[i+1][k-cnt];//����ֱ���������
      break;
    }
  }
  cout<<ans<<" fir"<<endl;
  if (cnt==k)//�����Ǳ����䣬��Ҫ����ͳ��ԭ������
    ans++;
  cout<<ans<<" d"<<endl;
  return ans;
}

int main()
{
//  freopen("amount.in","r",stdin);
//  freopen("amount.out","w",stdout);
  Init();
  scanf("%d%d%d%d",&X,&Y,&k,&b);
  printf("%d\n",Cal(Y)-Cal(X-1));
  return 0;
}
