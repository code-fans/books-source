//�����������
#include <bits/stdc++.h>
using namespace std;

inline int Read()                         //���ٶ�������
{
  int x=0,f=1;
  char ch=getchar();
  for(; ch<'0' || ch>'9'; ch=getchar())   //getchar��scanf��Լ��ʮ��
    if(ch=='-')
      f=-1;
  for(; ch>='0' && ch<='9'; ch=getchar())
    x=x*10+ch-'0';
  return x*f;
}

inline void Puts(int x)                   //�����������
{
  char c[16];
  int num=0,temp=x<0?-x:x;
  for(; temp; temp/=10)
    c[++num] = (temp%10)+'0';
  if(x<0)
    putchar('-');
  if(x==0)
    putchar('0');
  for(; num; putchar(c[num--]));
  putchar('\n');
}

int main()
{
  while(1)
  {
    int x=Read();
    Puts(x);
  }
  return 0;
}

