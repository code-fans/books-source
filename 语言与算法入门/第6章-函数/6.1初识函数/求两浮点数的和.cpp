//�����������ĺ�
#include <bits/stdc++.h>
using namespace std;

float add(float x,float y) //��������Ϊfloat,�������β�float x,float y
{
  float z; //ע�⣬������z
  z=x+y;
  return z; //����ֵz Ϊfloat�ͣ��뷵��ֵ����ƥ��
}

int main()
{
  float x,y,z;  //ע�⣺������x,y,z
  scanf("%f %f",&x,&y);
  z=add(x,y);//����add�����󷵻�һ��float���͵�ֵ,������ֵ����z
  printf("%0.2f\n",z);
  return 0;
}

