//���Գ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int i=1; i<=7; i++)
  {
    string F="sum";
    F+=char(i+48);             //����iתΪ�ַ�i,'0'��ASCIIֵΪ48
    string s="copy "+ F+".in sum.in";
    system(s.c_str());
    int time1=clock();
    system("sum.exe");
    int time2=clock();
    string Cmd="fc sum.out "+F+".ans";
    if(!system(Cmd.c_str()))
      cout<<"                   ���Ե�"<<i<<"ͨ������ʱ"<<time2-time1<<"����\n\n";
  }
  return 0;
}

