//ϣ������
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int Data[MAXN],n;

void ShellSort(int *a, int n)//ϣ������
{
  int t,i,j;
  for(int d=n/2; d>=1; d>>=1) //����Ϊd��ÿ�μ�һ��
    for(i=d; i<n; i++) //��ÿ�����������ֱ�Ӳ�������
    {
      t=a[i];//ע�⣺�˲��������֮ǰ�Ĳ�������ʵ�ַ�����������
      for(j=i-d; (j>=0) && (a[j]>t); j-=d) //�������С���������������λ����
        a[j+d]=a[j];
      a[j+d]=t;
    }
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%d",&Data[i]);
  ShellSort(Data,n);//����ϣ������
  for (int i=0; i<n; ++i)//���
    printf("%d ",Data[i]);
  printf("\n");
  return 0;
}

