//�ݹ�����ת��Ϊ�ַ�
#include <bits/stdc++.h>
using namespace std;

void convert(int n)
{
  int i;
  if((i=n/10)!=0) /*��������*/
    convert(i); /*483��һ�ηֽ�Ϊ48,�ڶ���Ϊ4*/
  putchar(n%10+'0'); /*'0'Ϊ48,48+n��ֵ,����n��ASCII��ֵ*/
}

int main()
{
  int number;  /*��������ֶ���,��483*/
  scanf("%d",&number);
  if(number<0)
  {
    putchar('-');  /*��Ϊ����ʱ�Ĵ���*/
    number=-number;
  }
  convert(number);
  return 0;
}

