#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int i=1; i<=5; i++)   //5��������ݣ�����ѭ��5��
  {
    string F="test";
    F+=char(i+48);         //����iתΪ�ַ�i,'0'��ASCIIֵΪ48
    //�����������i=1ʱ,Ϊ"copy test1.in test.in"
    string s="copy "+ F+".in test.in";
    system(s.c_str());      //ִ�п�������
    int time1=clock();      //��ȡ��ǰ����ʱ����
    system("test.exe");     //ִ��test.exe�ļ�
    int time2=clock();      //�������н������ʱ����
    //�Ƚ��ļ�����,����i=1ʱ,Ϊ"fc test.out test1.ans";
    string Cmd="fc test.out "+F+".ans";
    if(!system(Cmd.c_str()))//ִ�бȽ��ļ�����
      cout<<" ���Ե�"<<i<<"ͨ������ʱ"<<time2-time1<<"����\n\n";
  }
  return 0;
}

