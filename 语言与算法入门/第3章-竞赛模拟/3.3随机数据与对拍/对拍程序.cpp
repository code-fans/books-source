//���ĳ���
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in.txt","r",stdin); //Dev-C++����ƽ̨��Ӵ����Ա����Զ�����
  do
  {
    system("CreatRand.exe");
    system("program1.exe");
    system("program2.exe");
  }
  while(system("fc out1.txt out2.txt")==0);
  return 0;
}

