//�������֣��ӣԣ̰�
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("dictionary.in","r",stdin);
  freopen("dictionary.out","w",stdout);
  string english,foreign,s;
  map<string,string>translate;//��¼Foreign��English��ӳ��
  while(getline(cin,s))//�����ֵ�
  {
    if(s.size()==0)
      break;
    english=s.substr(0,s.find(" "));
    foreign=s.erase(0,s.find(" ")+1);
    translate[foreign]=english;
  }
  while(cin>>s)//��ʼ����
  {
    if(translate[s]!="")
      cout<<translate[s]<<endl;
    else
      cout<<"eh"<<endl;
  }
  return 0;
}
