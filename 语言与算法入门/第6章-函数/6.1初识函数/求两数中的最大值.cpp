//�������е������
#include <bits/stdc++.h>
using namespace std;

int Max(int a,int b)      //MaxΪһ���Ӻ���
{
  return (a>b?a:b);       //����ֵΪa,b�е����ֵ
}

int main()
{
  int x,y;
  scanf("%d %d",&x,&y);
  printf("%d\n",Max(x,y));//����Max����������x,yֵ���ݸ�Max����
  return 0;
}

