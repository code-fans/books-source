//������ - ��ͨ����
#include <bits/stdc++.h>
using namespace std;
const int MAX=100001;

bool a[MAX+10];                  //ȫ�����飬��ʼֵ��Ϊfalse��0
int prime[MAX/3],Count=0;        //prime������,Countͳ����������

int main()
{
  //freopen("prime.out","w",stdout);
  for(int i=2,limit=sqrt(MAX); i<MAX; i++)
  {
    if(a[i]==0)                   //a[i]=0��ʾ������
      prime[Count++]=i;           //�������δ���prime[]
    if(limit>i)                   //���ƣ�����i*i���ܻ��������
      for(int j=i*i; j<MAX; j+=i)//��i*i��ʼ����Ϊi*(2~i-1)��ɾ��
        a[j]=1;                   //���a[j]��������
  }
  for(int i=0; i<Count-1; i++)
    cout<<prime[i]<<' ';
  cout<<prime[Count-1]<<endl;
  return 0;
}

