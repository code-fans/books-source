//��ά���������������ά��������Ԫ��ֵ
# include <bits/stdc++.h>
using namespace std;

int Max(int a[][4]) //�β��������������Ϊ��
{
  int Max=a[0][0];
  for(int i=0; i<3; i++)
    for(int j=0; j<4; j++)
      if(a[i][j]>Max)
        Max=a[i][j];
  return Max;
}

int main()
{
  int a[][4]= {1,2,3,4,5,6,7,8,9,-1,-2,-3}; //�˴���ʡ�Ե�һά��ֵ��С
  printf("���ֵΪ %d\n",Max(a)); //������������
  return 0;
}

