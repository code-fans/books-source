//��100~200֮�䲻�ܱ�3�����������
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k=0;
  for(int n=100; n<=200; n++)
  {
    if(n%3==0)
      continue; //������ǰѭ���壬ִ��ѭ������������
    if(k==0)
    {
      k++;
      cout<<n;
    }
    else
      cout<<' '<<n;
  }
  cout<<endl;
  return 0;
}

