//����½����� - �Ƕ����㷨
#include <bits/stdc++.h>
using namespace std;

int Stack[100001]= {1e-9};              //��ֹ��һ��Ԫ��̫С

int main()
{
  //freopen("LIS.in","r",stdin);
  //freopen("LIS.out","w",stdout);
  int n,temp,longest=0;
  scanf("%d",&n);
  for (int i=0; i<n; i++)
  {
    scanf("%d",&temp);
    if (temp>=Stack[longest])           //��ջ��Ԫ�ش�������ջ
      Stack[++longest]=temp;
    else
    {
      int j=upper_bound(Stack,Stack+longest,temp)-Stack;
      Stack[j]=temp;
    }
  }
  printf("%d\n",longest);               //�����������ջ�Ĵ�С
  return 0;
}

