//����ָ����Χ�ڵ������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int low,hight;
  srand(time(0));
  cin>>low>>hight;//����low,hightֵ����С���õߵ�
  for(int i=1; i<=5000; i++)
    cout<<rand() %(hight-low+1)+low<<"  ";
  return 0;
}

