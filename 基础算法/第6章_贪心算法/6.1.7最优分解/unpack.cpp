/*���ŷֽ�
̰���㷨�����a+b=n����|a-b|ԽС����ôa*bԽ�󣬿��Խ�n�ֽ�ɴ�2��ʼ��������Ȼ���ĺ͡�
���磺����n=10������Էֽ�Ϊ2��3��4����ʣ��1����5�������1���żӣ�4 -> 5��
���ԣ����շֽ�Ϊ2,3,5�����Ϊ2*3*5=30��
���ʣ�µ����ֺ�ǰ���������ȣ��������ټ�1
*/
#include <bits/stdc++.h>
using namespace std;

int a[100];               //����ֽ�����

long long Fun(int n)
{
  int k=0;                //kΪ�����±�ָ��
  for(int i=2; n>a[k]; i++)
  {
    a[++k]=i;
    n-=i;
  }
  if(n==a[k])             //���ʣ��ֵ�����һ������Ԫ��ֵ���
    a[k]++;               //��������Ԫ��ֵ�ټ�1
  for(int i=0; i<n; i++)  //�ٰ�ʣ�µ�ֵ����ÿ����1������Ԫ����
    a[k-i]++;
  long long sum=1;
  for(int i=1; i<=k; i++) //���±�1��ʼ��
    sum*=a[i];
  return sum;
}

int main()
{
  freopen("unpack.in","r",stdin);
  freopen("unpack.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%lld\n",Fun(n));
  return 0;
}

