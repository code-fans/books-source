//ѭ��������ʾ����
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5                       //���е����Ԫ�ظ���

int Queue[MAXN];
int Front=0;                         //ͷָ��
int Rear=0;                          //βָ��

void AddQueue(int value)             //����valueֵ�����
{
  if((Rear+1)%MAXN==Front)
    cout<<"����"<<endl;
  else
  {
    Queue[Rear]=value;
    Rear=(Rear+1)%MAXN;
  }
}

int DelQueue()                       //ɾ����������
{
  if(Front==Rear)
    cout<<"����Ϊ��"<<endl;
  else
  {
    int temp=Queue[Front];
    Queue[Front]=-1;                //ȡ�����λ������Ϊ-1
    Front=(Front+1)%MAXN;           //ָ����һλ��
    return temp;                    //���Ԫ��ֵ
  }
}

void Display()                      //��ʾ���������е�Ԫ��
{
  for(int i = 0 ; i < MAXN; ++ i)
    cout<<Queue[i]<<" ";
  cout<<endl;
}

void Init()                         //��ʼ�����У��趨��ֵΪ-1
{
  for(int i = 0 ; i < MAXN; ++ i)
    Queue[i] = -1;
}

int main()
{
  int Select,temp;
  Init();
  while(1)
  {
    cout<<"1.����һ��Ԫ��ֵ������\n";
    cout<<"2.ɾ��һ��Ԫ��ֵ�Ӷ���\n";
    cout<<"3.�˳�\n";
    cin>>Select;
    switch(Select)
    {
      case 1:
        cout<<"������һ��ֵ��";
        cin>>temp;
        AddQueue(temp);
        break;
      case 2:
        DelQueue();
        break;
      case 3:
        return 0;
    }
    system("pause");
    system("cls");
    Display();
  }
  return 0;
}

