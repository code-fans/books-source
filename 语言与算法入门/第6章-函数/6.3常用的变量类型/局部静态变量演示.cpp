//�ֲ���̬������ʾ
#include <bits/stdc++.h>
using namespace std;

int fun()
{
  static int n=1;
  n++;
  return n;
}

int main()
{
  int i;
  for(i=0; i<3; i++)
    printf("%d ",fun());
  return 0;
}

