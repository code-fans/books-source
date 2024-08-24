//�������� - ���鷨
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N[10],n;
int Array[MAXN];                                //�������
int bucket[10][MAXN];                           //Ͱ

int maxbit(int IntMax)                          //�����λ��
{
  int digit=1;
  while(IntMax>0)
  {
    digit++;
    IntMax/=10;
  }
  return digit-1;
}

void RadixSort(int *array,int Exp)              //��������
{
  int Where,m=0;
  memset(N,0,sizeof(int)*10);                   //��Ͱ���������
  for(int i=0; i<n; i++)                        //���������Ͱ
  {
    Where=array[i]/(int(pow(10,Exp)+0.001))%10; //ȡ�ø�λ��ֵ��ȷ�������ĸ�Ͱ
    bucket[Where][N[Where]++]=array[i];         //����������
  }
  for(int i=0; i<10; i++)                       //˳���ռ�Ͱ�е�����array[]
    for(int j=0; j<N[i]; j++)
      array[m++]=bucket[i][j];
}

int main()
{
  int IntMax=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d",&Array[i]);
    if(Array[i]>IntMax)                         //�ҳ������
      IntMax=Array[i];
  }
  int len=maxbit(IntMax);                       //����������λ��
  for(int i=0; i<len; ++i)                      //���ζ�ÿһλ���л�������
    RadixSort(Array,i);
  for(int i=0; i<n; i++)
    printf("%d ",Array[i]);
  return 0;
}

