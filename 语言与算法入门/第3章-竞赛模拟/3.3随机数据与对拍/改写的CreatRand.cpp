//��д��CreatRand.cpp
#include <bits/stdc++.h>
#include <windows.h>  //���windows.hͷ�ļ�,ע����ʽ���������и�ͷ�ļ� 
using namespace std;

int main()
{
  SYSTEMTIME sys;//����sysΪSYSTEMTIME����
//��õ�ǰϵͳʱ��,���ԱwSecondΪ��,wMillisecondsΪ����
  GetLocalTime( &sys );
  srand(sys.wSecond*1000+sys.wMilliseconds);//�Ժ��뼶����Ϊ���������
  //freopen("in.txt","w",stdout);//�������������д��in.txt
  cout<<rand()%1000<<" "<<rand()%1000<<" "<<rand()%1000<<endl;
  return 0;
}

