//����½������� - ̰�ģ������Ż�
#include<bits/stdc++.h>
using namespace std;

int a[100005],f[100005];

int main()
{
  freopen("LIS.in","r",stdin);
  freopen("LIS.out","w",stdout);
  int n,longest=0;
  memset(f,-1,sizeof(f));              //Ҫ��ʼ��Ϊ-1
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    if(f[longest]<=a[i])               //�����������f[longest]
      f[++longest]=a[i];               //��a[i]���ӵ����
    else
    {
      int L=0,R=longest;
      while(L<=R)                      //���ֲ��Һ��ʵ�λ��
      {
        int mid=(L+R)>>1;
        if(f[mid]<=a[i])
        {
          L=mid+1;
          if(f[L]>a[i])
            break;
        }
        else
          R=mid-1;
      }
      f[L]=a[i];                       //����f[L]ֵ
    }
  }
  cout<<longest<<endl;
  return 0;
}

