//�ݹ��㷨
#include <bits/stdc++.h>
using namespace std;
int m,k;

int Josephus(int m)//kΪ��ʼ����λ��
{
  int ans;
  if(m==1)
    return 1;
  else
    ans=(Josephus(m-1)+k-1)%m+1;
  //printf("%d ",ans);
  return ans; //������һ�ֺ���λ��
}

int main()
{
  scanf("%d%d",&m,&k);
  printf("%d\n",Josephus(m));
  return 0;
}

