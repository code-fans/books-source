//ͳ�Ƶ�����-string����
#include <bits/stdc++.h>
using namespace std;

int main()
{

  string a,b;
  getline(cin,a);//��ȡstring�Ƽ���getline()
  getline(cin,b);
  for (int i=0; i<a.length(); ++i)
    a[i]=tolower(a[i]);//תСд��ĸ��ת��д��ĸΪtoupper
  for (int i=0; i<b.length(); ++i)
    b[i]=tolower(b[i]);
  a=' '+a+' ';//����ǰ��ӿո�
  b=' '+b+' ';//����ͬ��ǰ��ӿո�
  if (b.find(a)==string::npos)//�Ȳ����Ƿ���ƥ��
    cout<<-1<<endl;
  else
  {
    int first=b.find(a),count=0;
    for(int Pos=b.find(a); Pos!=string::npos; Pos=b.find(a,Pos+1)) //npos��ʾstring�Ľ���λ
      ++count;
    cout<<count<<" "<<first<<endl;
  }
  return 0;
}
