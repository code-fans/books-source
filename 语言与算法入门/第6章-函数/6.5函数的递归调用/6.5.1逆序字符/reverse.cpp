//�����ַ�
#include <bits/stdc++.h>
using namespace std;

void reverse(int n)
{
  char next;
  if(n<=1)     //�ݹ�Ľ�������
  {
    next=getchar();//�Ӽ��̻��һ���ַ�
    putchar(next);//��Ϊֻʣ���һ���ַ��ˣ���������ֱ�Ӵ�ӡ����
  }
  else
  {
    next=getchar();//�Ӽ��̻��һ���ַ�
    reverse(n-1);  //�ݹ�����������һ���ַ�
    putchar(next);//ֻ�еȵ�n-1���ַ�������ӡ�󣬸��ַ��ű���ӡ
  }
}

int main()
{
  //freopen("reverse.in","r",stdin);
  //freopen("reverse.out","w",stdout);
  reverse(5);
  printf("\n");
  return 0;
}

