//���������c(m,n)�ĵݹ���
#include <bits/stdc++.h>
using namespace std;

int combin(int m,int n)
{
  int com;
  if (n<2*m)//�Ż�
    m=n-m;
  if (m==0) /*��ֹ�ݹ���õ�����*/
    com=1;
  else if (m==1)
    com=n;
  else
    com=combin(m,n-1)+combin(m-1,n-1);
  return com;
}

int main()
{
  int m,n;
  scanf("%d %d",&m,&n);//����4 7 ���Ϊ35
  printf("%d\n",combin(m,n));
  return 0;
}

