//������ģ��ջ
#include<bits/stdc++.h>
#define MAXN 1000              //ջ�����ɵ����Ԫ�ظ���
using namespace std;

int Stack[MAXN];               //����д��stack���������Ƴ�ͻ
int Top = -1;                  //��ʼ��ջ��ָ��Ϊ-1

int Pop()                      //ջ��Ԫ�س�ջ����ȡ��ջ��Ԫ��ֵ
{
  if(Top<0)
  {
    cout<<"\nջΪ��!\n";
    return -1;
  }
  return Stack[Top--];
}

void Push(int value)           //��ջ
{
  if(Top>=MAXN)
    cout<<"\nջ����!\n";
  else
    Stack[++Top]=value;
}

void Display()                 //��ʾջ��Ԫ��
{
  for(int tmp = Top ; tmp >= 0 ; -- tmp)
    cout<<Stack[tmp]<<" ";
  cout<<"\n";
}

int main()
{
  int ins;
  while(1)
  {
    system("cls");              //����
    Display();
    cout<<"������Ԫ��ֵ,(0=�˳�,-1=��ջ)\n";
    cin>>ins;
    if(ins==0)
      exit(0);
    else if(ins!=-1)
      Push(ins);
    else if(ins==-1)
      Pop();
  }
  return 0;
}

