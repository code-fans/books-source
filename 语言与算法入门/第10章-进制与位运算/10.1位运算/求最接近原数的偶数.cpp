//����ӽ�ԭ����ż��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin>>x;
  if(x&1==1)
    x=(x|1)-1;//ע��λ��������ȼ��ܵͣ����Ա��������
  cout<<x<<"����ӽ�ԭ����ż��"<<endl;
  return 0;
}

