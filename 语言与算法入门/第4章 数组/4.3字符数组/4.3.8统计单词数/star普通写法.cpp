#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str1,str2;
  getline(cin,str2);
  getline(cin,str1);
  int len2=str2.size();
  int len1=str1.size();
  for(int i=0; i<len2; i++)
    str2[i]=toupper(str2[i]);  //ת�ɴ�д
  for(int i=0; i<len1; i++)
    str1[i]=toupper(str1[i]);
  int count=0,First;
  for(int i=0,j; i<=len1-len2; i++)//ɨ���ַ���
  {
    for(j=0; j<len2; ++j)
    {
      if(str1[j+i]!=str2[j] ||(i>0 && str1[i-1]!=' ')) break;
      //���ǵ��ʿ�ͷ�ͽ���
    }
    if(j==len2 && (str1[j+i]==' '||j+i==len1)) //���ʳ���ƥ�䣬�����ǿո���߾�ĩ
    {
      count++;
      if(count==1) First=i;
    }
  }
  if(count==0)cout<<-1;
  else cout<<count<<" "<<First;
  return 0;
}
