//�޳���������-���ַ�
#include <bits/stdc++.h>
using namespace std;

int a[1024];
char s[1024];

int Cal(int L, int R, int prev_min)
{
  int min=4, min_pos;          //min_posΪ����������λ��
  for (int i=L; i<=R; i++)     //ɨ���ҳ���������,�����λ��
  {
    if(s[i]=='^')
    {
      if (min>3)
        min=3, min_pos=i;      //���"^"��������ȼ�Ϊ3
    }
    else if(s[i]=='*' || s[i]=='/')
    {
      if (min>2)
        min=2, min_pos=i;      //���"*"��"/"��������ȼ�Ϊ2
    }
    else if(s[i]=='+' || s[i]=='-')
    {
      if (min>1)
        min=1, min_pos=i;      //���"+"��"-"��������ȼ�Ϊ1
    }
    else if(s[i]=='(')         //���������ţ����������ڵ��ַ����ҵ�ƥ���������
    {
      i++;
      for (int t=1; t!=0; i++)
      {
        if (s[i]=='(')         //�������ڶ��������ź������ŵĴ���
          t++;
        if (s[i]==')')
          t--;
      }
      i--;
    }
  }
  if (min==4)                  //ȥ���Ų���
  {
    if (s[L]=='(' && s[R]==')')//�����β��Ϊ����
    {
      int t=Cal(L+1,R-1,0);    //�����ȥ��β���ż����ݹ�ķ���ֵmin
      if (t>=prev_min)
      {
        a[L]=a[R]=1;           //����β�����ű��Ϊ����
        return t;
      }
    }
  }
  else
  {
    Cal(L,min_pos-1,min);        //�ݹ���������ǰ�˵�ʽ��
    if (s[min_pos]=='+' || s[min_pos]=='*')
      Cal(min_pos+1,R,min);      //�ݹ�����������˵�ʽ��
    else                         //����������"-"��"/"
      Cal(min_pos+1,R,min+1);    //�ݹ�����������˵�ʽ�ӣ����������ȼ�+1
  }
  return min;
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  cin>>s;
  int len=strlen(s);
  Cal(0,len-1,0);
  for (int i=0; i<len; i++)
    if (!a[i])                 //��ǰλ���Ϊ0�������
      cout<<s[i];
  cout<<'\n';
  return 0;
}
