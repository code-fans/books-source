//rand.cpp
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
  freopen("24.in","r",stdin);                   //Dev-C++���ܿ���ƽ̨��Ӵ˾�
  freopen("24.in","w",stdout);
  SYSTEMTIME sys;                               //����sysΪSYSTEMTIME����
  GetLocalTime( &sys );
  srand(sys.wSecond*1000+sys.wMilliseconds);    //�Ժ��뼶����Ϊ���������
  for(int i=0; i<=3; i++)
    cout<<rand()%9+1<<' ';
  return 0;
}
