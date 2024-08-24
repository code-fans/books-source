//�޳���������-�Ƕ��ַ�
#include <bits/stdc++.h>
using namespace std;

char s[10010];
bool vis[10010];
int len;

int FindMinOp(int Left,int Right)   //����ƥ�������е���ͼ������
{
  for(int i=Left; i<=Right; i++)
    if(s[i] == '-' || s[i] == '+')
      return s[i];
}

int FirstLeft()                     //����������ҵ���һ��������
{
  for(int j=len-1; j>=0; j--)
    if(s[j] == '(')
      return s[j];
}

int FindRight(int Left)             //Ѱ�������ŵ�ƥ��������
{
  for(int R=Left+1,cnt=1; R<len; ++R)
  {
    if(s[R] == '(')
      cnt++;
    if(s[R] == ')')
      cnt--;
    if(cnt==0)
      return R;
  }
}

void Work()                         //�ж������Ƿ��ɾ��
{
  for(int i=FirstLeft(); i>=0; i--) //�����ڲ���������ɨ��
    if(s[i]=='(')
    {
      int R=FindRight(i);           //�ҵ���ƥ���������
      char MinOp=FindMinOp(i,R);    //�ҵ���ͼ��������
      if(s[i-1]=='/')               //��������ǰΪ/���򲻿�ɾ��
        continue;
      else if((s[i-1]=='*' || s[i-1]=='-') && (MinOp=='+' || MinOp=='-'))
        continue;//��������ǰΪ*,-������������������Ϊ+,-�򲻿�ɾ��
      else if((s[R+1]=='/' || s[R+1]=='*') && (MinOp=='+' || MinOp=='-'))
        continue;//�������ź�Ϊ/,*,����������������Ϊ+,- �򲻿�ɾ��
      else
      {
        vis[i]=true;                //�����ſ���ɾ��
        vis[R]=true;                //�����ſ���ɾ��
      }
    }
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  scanf("%s",s);
  len=strlen(s);
  Work();
  for(int i=0; i<len; i++)
    if(!vis[i])
      printf("%c",s[i]);
  puts("");
  return 0;
}
