//�򵥱������� - �ݹ�ⷨ
#include <bits/stdc++.h>
using namespace std;

int W[40];               //����Ʒ����

int Bag(int s,int n)     //sΪʣ��������nΪʣ���ѡ��Ʒ��
{
  if(s==0)               // �������װ��
    return 1;
  if(s<0||(s> 0 && n<1)) //��s<0��n<1�������
    return 0;
  if(Bag(s-W[n],n-1))    //�Ӻ���ǰװ��װ��W[n]����ʣ����Ʒ���н�
  {
    cout<<W[n]<<"\n";    //��װ����n�����������
    return 1;
  }
  return Bag(s,n-1);     //��װ�˵�n�����޽���ɾ�������Ե�n��1��
}

int main()
{
  freopen("Backpack.in","r",stdin);
  freopen("Backpack.out","w",stdout);
  int S,N;
  scanf("%d%d",&S,&N);
  for(int i=1; i<=N; ++i)
    scanf("%d",&W[i]);
  if(!Bag(S,N))
    printf("Failed!\n");
  return 0;
}

