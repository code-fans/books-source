//���ص�1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("light1.in","r",stdin);
  //freopen("light1.out","w",stdout);
  int f[101]; //��û����ֵ������£�����f��ĸ�Ԫ��ֵδ֪
  memset(f,0,sizeof(f));//ȫ������Ԫ�ظ�ֵΪ0
  for(int  i=1; i<=100; i++)
    if(i%2==0)
      f[i]=!f[i];
  for(int  i=1; i<=100; i++)
    if(i%3==0)
      f[i]=!f[i];
  for(int  i=1; i<=100; i++)
    printf("%d",f[i]);
  printf("\n");
  return 0;
}

