//�����
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  char s[30000];
  int i=0,j,Long=0,m=0;
  cin.getline(s,30000-1);
  while(s[i]!='\0')//�����ַ���
  {
    j=0;
    while(s[i]!=' ' && s[i]!='\0')//ͳ��ÿ�����ʵĳ���
    {
      j++;//j����ͳ�Ƶ��ʳ���
      i++;//i����ͳ��ɨ������ַ��������Ƕ���
    }
    if(j>Long)//ɸѡ��ĵ���
    {
      m=i-j;//��Ǹõ���λ��
      Long=j;
    }
    while(s[i]==' ')//�ո�ҲҪͳ�Ƶ��ַ���������
      i++;
  }
  while(s[m]!=' ' &&s[m]!='\0')//�ӱ��λ��������,ֱ���ո�����
  {
    printf("%c",s[m]);
    m++;
  }
  printf("\n");
  return 0;
}

