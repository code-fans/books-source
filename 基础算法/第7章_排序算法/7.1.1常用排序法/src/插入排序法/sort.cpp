//ֱ�Ӳ�������
#include <bits/stdc++.h>
#define N 100000
int a[N+1];

void InsertSort(int n,int a[])
{
  for(int i=2; i<=n; i++)               //����Ԫ�شӵ�2��λ�ÿ�ʼ
  {
    int j,insert=a[i];                  //a[i]ΪҪ�������,��ֵ��insert�Է���ʧ
    for(j=i-1; j>=1 && insert<a[j]; --j)//��a[i-1]��ʼ��ǰ�ұ�a[i]С����
      a[j+1]=a[j];                      //ǰ���a[i]������������Ųһ��λ�ñ���
    a[j+1]=insert;                      //a[i]��ֵ���뵽��ȷλ��
  }
}
int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);
  InsertSort(n,a);                        //��������
  for(int i=1; i<=n; ++i)
    printf("%d ",a[i]);
  return 0;
}
