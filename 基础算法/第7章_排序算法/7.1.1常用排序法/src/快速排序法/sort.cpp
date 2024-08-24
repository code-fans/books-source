//���ؿ�������
#include <bits/stdc++.h>
using namespace std;
#define N 100010

int a[N];

void QuickSort(int i,int j)               //���ź���
{
  int m=i,n=j;
  int k=a[(i+j)>>1];                      //ѡȡ�м�Ԫ��
  while(m<=n)
  {
    while(a[m]<k)  m++;                   //�������ұ�k���Ԫ��
    while(a[n]>k)  n--;                   //���ҵ����ұ�kС��Ԫ��
    if(m<=n)
      swap(a[m++],a[n--]);                //����,��ָ��ָ����һԪ��
  }
  if(m<j)  QuickSort(m,j);                //�ݹ�
  if(n>i)  QuickSort(i,n);
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  QuickSort(1,n);
  for(int i=1; i<=n; i++)
    printf("%d ",a[i]);
  return 0;
}

