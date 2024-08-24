//�򵥸߾��ȳ˷�
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

char str1[MAXN],str2[MAXN];
int a[MAXN],b[MAXN],c[MAXN];

void Multiply(int a[],int b[],int la,int lb)
{
  for(int i=0; i<lb; ++i)                       //��һ���ˡ�
  {
    for(int j=la-1; j>=0; --j)                  //�ڶ�������
      c[j+i]+=b[i]*a[j];                    //ע��˻������λ��
    for(int k=0; c[k]>=0; ++k)                 //��ĳλ��>=10������������������Ż�
    {
      c[k+1]+=c[k]/10;
      c[k]%=10;
    }
  }
}

void Init(int x[],char str[],int len)       //�ַ���תΪ��������
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';
}

void Output(int ans[])
{
  int i=MAXN-1;
  for(; ans[i]==0 && i>0; --i);       //�������λ����ע���ĩ�и��ֺ�
  for(; i>=0; --i)                   //������
    cout<<ans[i];
  cout<<'\n';
}

int main()
{
  freopen("mul.in","r",stdin);
  freopen("mul.out","w",stdout);
  cin>>str1>>str2;
  int la=strlen(str1);
  int lb=strlen(str2);
  Init(a,str1,la);                        //��ʼ��Ϊ��������
  Init(b,str2,lb);
  Multiply(a,b,la,lb);
  Output(c);
  return 0;
}

