//�������������
#include <bits/stdc++.h>
using namespace std;

int a[100001];

void QuickSort(int L,int R)
{
  int m=L,n=R;
  for(int k=a[rand()%(R-L+1)+L]; m<=n;)  //kΪ���ȷ����Ԫ��
  {
    while(a[m]<k)  m++;                  //�������ұ�k���Ԫ��
    while(a[n]>k)  n--;                  //���ҵ����ұ�kС��Ԫ��
    if(m<=n)                             //���ҵ��������������򽻻�
      swap(a[m++],a[n--]);
  }
  if(m<R)  QuickSort(m,R);               //�ݹ�
  if(n>L)  QuickSort(L,n);
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  srand(time(0));                        //���������
  QuickSort(1,n);
  for(int i=1; i<=n; i++)
    printf("%d ",a[i]);
  return 0;
}

