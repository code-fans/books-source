//�Ӵ���������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("substr.in","r",stdin);
  //freopen("substr.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  if(s1.size()<s2.size())     //�Ƚ����ַ������ȣ������ַ�������ǰ��
    swap(s1,s2);
  s1+=s1;                     //����s1
  cout<<(s1.find(s2)==-1?"No":"Yes")<<'\n';
  return 0;
}

