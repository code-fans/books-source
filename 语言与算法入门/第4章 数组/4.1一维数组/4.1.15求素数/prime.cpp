//������ - ��ͨ����
#include <bits/stdc++.h>
using namespace std;
const int MAX=100000;

bool a[MAX+10];                    //ȫ�����飬��ʼֵ��Ϊfalse��0
int prime[MAX],Count=0;            //prime������,Countͳ����������

int main()
{
  for (int i=2; i<=MAX; i++)
  {
    if (a[i]==0)                   //a[i]=0��ʾ������
      prime[Count++]=i;            //�������δ���prime[]
    if(i<=sqrt(MAX))               //��Ҫд��i*i<=MAX,��ֹi*i�������
      for (int j=i*i; j<=MAX; j+=i)//��i*i��ʼ����Ϊi*(2~i-1)��ɾ��
        a[j]=1;                    //���a[j]��������
  }
  for (int i=0; i<Count; i++)
    cout<<prime[i]<<' ';
  return 0;
}

