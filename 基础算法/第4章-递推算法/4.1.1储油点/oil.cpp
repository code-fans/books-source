//���͵�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("oil.in","r",stdin);
  //freopen("oil.out","w",stdout);
  double oil[10],dis[10];
  dis[1]=500;                     //�������һ�����͵���յ�ľ���
  oil[1]=500;                     //���͵�1�财��500
  int d=500;                      //��ʼֵΪ���һ�����͵㵽�յ�ľ���
  int k=1;                        //���͵�λ�����,��������
  while (d<=1000)                 //��ʼ����
  {
    k++;
    d+=500/(2*k-1);               //ÿ�ζ�Ҫ����һ������
    dis[k]=d;                     //ȷ�����͵�λ��
    oil[k]=oil[k-1]+500;          //ÿ�ζ�Ҫ��װһ�Σ����Լ�500
  }
  dis[k]=1000;                    //������ʼ�㵽�յ�ľ���ֵ
  double d1=1000-dis[k-1];        //ʣ�µľ���
  oil[k]=d1*(2*k-1)+oil[k-1];     //��һ����������2k-1�ε��ͺļӵ���㴦
  for(int i=0; i<k; i++)          //��һ�����ǰ���͵�ľ���ʹ�����
    printf("i=%d  dis=%.2f  oil=%.2f\n",i,1000-dis[k-i],oil[k-i]);
  return 0;
}

