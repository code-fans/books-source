//ͨ��ָ������������Ԫ�أ�����һ������ĳ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int *p,i,a[10];
  p=a;
  for(i=0; i<10; i++)
  {
    scanf("%d",p);//ע��˴�д��
    p++;
  }
  printf("\n");
  for(i=0; i<10; i++,p++)
    printf("%d ",*p);
  return 0;
}

