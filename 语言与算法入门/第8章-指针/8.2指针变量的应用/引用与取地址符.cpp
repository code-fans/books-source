//������ȡ��ַ����
#include <bits/stdc++.h>
using namespace std;

void swap1(int *x,int *y)//ȡ��ַ
{
  int z=*x;
  *x=*y;
  *y=z;
}

void swap2(int &x,int &y)//����
{
  int z=x;
  x=y;
  y=z;
}

int main()
{
  int a=1,b=-1;
  swap1(&a,&b);//����Ҫ������Ϊָ�룬��Ҫȡ��ַ��
  printf("   a=%d,b=%d\n",a,b);
  swap2(a,b);//���ò���Ҫȡ��ַ��
  printf("   a=%d,b=%d\n",a,b);
  return 0;
}
