//��ŵ��
#include <bits/stdc++.h>
using namespace std;

void Move(int n,char A,char B,char C)//��n����Ƭ��A�����B���Ƶ�C��
{
  if(n==1)                        //����Ƭֻʣ1��ʱ
    printf("%c->%c ",A,C);        //�ƶ���Ƭ��A��C
  else
  {
    Move(n-1,A,C,B);                 //�ݹ����,��Ƭ��-1,�����뻻λ��
    printf("%c->%c ",A,C);        //�ƶ���Ƭ��A��C
    Move(n-1,B,A,C);                 //�ݹ����,��Ƭ��-1,�����뻻λ��
  }
}

int main()
{
  int m;                          //��Ƭ��
  scanf("%d",&m);                 //�����Ƭ��
  Move(m,'A','B','C');
  return 0;
}

