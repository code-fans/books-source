//��ð�ݷ���n����������С����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int a[10005],n;//��û����ֵ������£�����a��ĸ�Ԫ��ֵδ֪
  scanf("%d",&n);
  for(int i=1; i<=n; i++)//���±�1��a[1]��ʼ��a[0]����������
    scanf("%d",&a[i]);
  for(int j=1; j<=n-1; j++) //��ѭ����n-1��
    for(int i=1; i<=n-j; i++) //ÿ��Сѭ���Ĳ�����εݼ�
      if(a[i]>a[i+1])//�Ƚ���������ǰ�������ں�����,��С���ϸ�,�����³�
        swap(a[i],a[i+1]);
  for(int i=1; i<n; i++)
    printf("%d ",a[i]);//����ӡ���ź��������
  printf("%d\n",a[n]);
  return 0;
}

