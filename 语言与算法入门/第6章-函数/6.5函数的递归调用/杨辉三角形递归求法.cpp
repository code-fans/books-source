//��������εݹ���
#include <bits/stdc++.h>
using namespace std;/*�ӵ�0�п�ʼ*/

int c(int x,int y)/*������������е�x�е�y�е�ֵ*/
{
  int z;
  if((y==1)||(y==x+1))
    return 1; /*��Ϊ��б�ߣ������1*/
  z=c(x-1,y-1)+c(x-1,y);/*������ֵΪǰһ���е�y-1�����y��ֵ֮��*/
  return z;
}

int main()
{
  int i,j,n;
  do
  {
    printf("������n��ֵ:");
    scanf("%d",&n);
  }
  while(n>12);   /*��֤�����ֵ������12�Ա�����ĻЧ��*/
  for(i=0; i<=n; i++) /*�������n��*/
  {
    for(j=0; j<24-2*i; j++)
      printf(" ");/*���������i��ǰ��Ŀո�*/
    for(j=1; j<i+2; j++)
      printf("%5d",c(i,j));/*�����i�еĵ�j��ֵ*/
    printf("\n");
  }
  return 0;
}

