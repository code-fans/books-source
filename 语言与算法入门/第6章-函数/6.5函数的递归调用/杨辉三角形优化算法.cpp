//����������Ż��㷨
#include <bits/stdc++.h>
using namespace std;
int a[14][14];//�������ڴ洢��������θ�Ԫ�ص�ֵ

int c(int x,int y)/*������������е�x�е�y�е�ֵ*/
{
  if((y==1)||(y==x+1))
    a[x][y]=1; //��Ϊ��б�ߣ���ֵΪ1
  if(a[x][y]!=0)//�����λ�õ�ֵ�Ѿ������
    return a[x][y];//������ݹ���㣬ֱ�ӷ��ظ�ֵ����
//����ǰһ���е�y-1�����y��ֵ֮�Ͳ�����a[x][y]
  a[x][y]=c(x-1,y-1)+c(x-1,y);
  return a[x][y];
}

int main()
{
  int i,j,n;
  do
  {
    printf("������n��ֵ:");
    scanf("%d",&n);
  }
  while(n>12); //��֤�����ֵ������12�Ա�����ĻЧ��
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

