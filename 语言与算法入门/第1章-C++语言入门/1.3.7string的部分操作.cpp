//string�Ĳ��ֲ�������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s="Hi,..morn";           //��������Ϊs��string�ಢ��ʼ��
  s=s+"ing";                      //β������ַ���"ing"
  cout<<"����ַ���:"<<s<<endl;   //���"Hi,..morning"
  s.erase(3,2);                   //ɾ����3���ַ����2���ַ�
  cout<<"ɾ���ַ���:"<<s<<endl;   //���"Hi,morning"
  int f=s.find("Hi,");            //����"Hi,"��s�е�λ��,-1Ϊ�Ҳ���
  s.insert(f+3,2,'G');            //��f+3��λ�ú���뵥���ַ�'G'2��
  cout<<"�������ַ�:"<<s<<endl;   //���"Hi,GGmorning"
  s.insert(5,",MM,");             //�ڵ�5��λ�ú�����ַ���",MM,"
  cout<<"�����ַ���:"<<s<<endl;   //���"Hi,GG,MM,morning"
  string v=s.substr(4,3);         //ȡs�е�4��λ�ú��3���ַ���v
  cout<<"�ַ����Ӵ�:"<<v<<endl;   //���"G,M"
  cout<<"string����:"<<v.length();//���3,��v�ĳ���
  return 0;
}

