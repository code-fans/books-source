//�����Ȼ�� - �ݹ��㷨
#include <bits/stdc++.h>
using namespace std;

int Num[100],Count;

void Print(int k)                 //��ӡk����
{
  printf("%d=%d",Num[0],Num[1]);
  for(int i=2; i<=k; i++)
    printf("+%d",Num[i]);
  printf("\n");
  ++Count;
}

void split(int k,int n)           //kΪָ���λ��,nΪ�����ֵ���
{
  if(n<=0)                        //���޷��ٲ�֣����ӡ
    Print(k);
  else
    for(int i=Num[k]; i<=n; ++i)
      if(i>=Num[k])               //�����ֵ������ڵ���ǰһ����
      {
        Num[k+1]=i;               //��ɹ����
        split(k+1,n-Num[k+1]);    //��������һ�����ĵݹ�
      }
}

int main()
{
  //freopen("Distribution.in","r",stdin);
  //freopen("Distribution.out","w",stdout);
  scanf("%d",&Num[0]);            //��������7
  for(int i=1; i<=Num[0]/2; ++i)  //�Ȳ�ֳ���λ����
  {
    Num[1]=i;                     //����Num[0]Ϊ7ʱ����һλ����Num[1]ֻ������1,2,3
    split(1,Num[0]-Num[1]);       //�ݹ�������
  }
  printf("%d\n",Count);
  return 0;
}

