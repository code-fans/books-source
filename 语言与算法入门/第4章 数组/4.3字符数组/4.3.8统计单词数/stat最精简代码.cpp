//ͳ�Ƶ�����-������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("stat.in","r",stdin);
  //freopen("stat.out","w",stdout);
  string a,b;
  getline(cin,a);//��ȡstring�Ƽ���getline()
  getline(cin,b);
  transform(a.begin(),a.end(),a.begin(),::tolower);//ȫ��תСд
  transform(b.begin(),b.end(),b.begin(),::tolower);
  a=' '+a+' ';//����ǰ��ӿո�
  b=' '+b+' ';//����ͬ��ǰ��ӿո�
  int first=b.find(a),count=0;//��������ʼ��Ϊ0
  for(int P=b.find(a); P!=string::npos; P=b.find(a,P+1))
    ++count;
  first==string::npos?cout<<"-1\n":cout<<count<<" "<<first<<endl;
  return 0;
}

