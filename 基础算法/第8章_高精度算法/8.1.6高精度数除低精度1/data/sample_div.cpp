//�߾��������Ե;�����1
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

void Output(int c[],int len,int j=0)
{
  for(; c[j]==0 && j<len; j++); //��ȥǰ����Ч��0
  for(int i=j; i<=len; ++i)
    cout<<c[i];
  cout<<'\n';
}

int main()
{
  freopen("sample_div.in","r",stdin);
  freopen("sample_div.out","w",stdout);
  int a[MAXN],c[MAXN];
  int x=0,b;             //x��ʾ���� 
  string str;
  cin>>str>>b;
  for(int i=0; i<str.size(); ++i)
  {
    a[i]=str[i]-'0';     //�Ƚ��ַ�ת��Ϊ����
    c[i]=(x*10+a[i])/b;  //ģ����������̴���c[i]
    x=(x*10+a[i])%b;     //��������10���ۼƵ�x
  }
  Output(c,str.size()-1);
  return 0;
}
