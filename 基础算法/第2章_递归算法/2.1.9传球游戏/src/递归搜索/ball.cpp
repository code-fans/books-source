//������Ϸ - �ݹ�����
#include <bits/stdc++.h>
using namespace std;

int n,m,Sum;

void Pass(int man,int step)
{
  if(step==m)                             //�������m��
  {
    if(man==1)                            //ǡ�ô����������������1
      ++Sum;
    return;
  }
  if(man==n)                              //������ڵ�n��������
  {
    Pass(1,step+1);                       //���ߴ�����һ����
    Pass(man-1,step+1);                   //���ߴ���n��1��
  }
  else if(man==1)                         //������ڵ�һ������
  {
    Pass(n,step+1);                       //���ߴ�����n��
    Pass(man+1,step+1);                   //���ߴ�����2��
  }
  else                                    //�����1��n֮����κ�һ��
  {
    Pass(man+1,step+1);                   //���ߴ����ұ�
    Pass(man-1,step+1);                   //���ߴ������
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  Pass(1,0);                              //��1�ſ�ʼ���򣬵�ǰ����Ϊ0
  printf("%d\n",Sum);
  return 0;
}

