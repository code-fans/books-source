//ͳ�Ƶ�����-��string����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stat.in","r",stdin);
  freopen("stat.out","w",stdout);
  string a,b;          //string���ǻ����������ͣ�������scanf()����
  getline(cin,a);      //��ȡstring�Ƽ���getline()
  getline(cin,b);
  for (int i=0; i<a.length(); ++i)
    a[i]=tolower(a[i]);//תСд��ĸ��ת��д��ĸΪtoupper
  for (int i=0; i<b.length(); ++i)
    b[i]=tolower(b[i]);
  a=' '+a+' ';         //����ǰ��ӿո�
  b=' '+b+' ';         //����ͬ��ǰ��ӿո�
  if (b.find(a)==-1)   //�Ȳ����Ƿ���ƥ��,�Ҳ���ֵΪ-1
    cout<<-1<<endl;
  else
  {
    int first=b.find(a),count=0;
    for(int P=b.find(a); P<b.length(); P=b.find(a,P+1))
      ++count;
    cout<<count<<" "<<first<<endl;
  }
  return 0;
}
