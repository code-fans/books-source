//�ݹ�������
#include <bits/stdc++.h>
using namespace std;

int age(int n)
{
  if(n==1)  //�ݹ����������
    return 10;
  else
    return age(n-1)+2; //��������
}

int main()
{
  printf("%d\n",age(5));
  return 0;
}

