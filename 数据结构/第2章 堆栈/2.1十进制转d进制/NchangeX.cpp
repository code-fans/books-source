//ʮ����תd����
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000                   //ջ�����ɵ����Ԫ�ظ���

int Stack[MAXN];
int Top = -1;                       //��ʼ��ջ��ָ��Ϊ-1
char c[36]= {'0','1','2','3','4','5','6','7','8','9','A','B',
             'C','D','E','F','G','H','I','J','K','L','M','N',
             'O','P','Q','R','S','T','U','V','W','X','Y','Z'
            };

int StackEmpty()                    //�ж�ջ�Ƿ�Ϊ��
{
  return Top<0 ? 1:0;
}

char Pop()                          //ջ��Ԫ�س�ջ����ȡ��ջ��Ԫ��ֵ
{
  int temp=Stack[Top--];
  return c[temp];
}

void Push(int value)                //��ջ
{
  Stack[++Top]=value;
}

void Conversion(int N,int d)        //����ת��
{
  while(N)
  {
    Push(N%d);
    N/=d;
  }
  while(!StackEmpty())
    cout<<Pop();
}

int main()
{
  freopen("NchangeX.in","r",stdin);
  freopen("NchangeX.out","w",stdout);
  int number,d;
  cin>>number>>d;
  if(number==0)                     //ע������0
    cout<<0<<endl;
  else
  {
    Conversion(number,d);
    cout<<endl;
  }
  return 0;
}

