//����������
#include <bits/stdc++.h>
using namespace std;

int Queue[5];
int front =-1;                             //ͷָ��
int rear =-1;                              //βָ��

void AddQueue(int value)
{
  if(rear>=4)
    cout<<"���󣬶�������!\n";
  else
    Queue[++rear]=value;
}

int DelQueue()
{
  if(front==rear)
    return -1;
  else
  {
    int v=Queue[++front];                  //����Ԫ���ݴ�temp
    Queue[front]=0;                        //��ն���Ԫ��
    return v;
  }
}

void Display()
{
  for(int i=0; i<5; i++)
    if(Queue[i]!=0)
      cout<<Queue[i]<<' ';
  cout<<"\n����front="<<front<<" ��βrear="<<rear<<"\n\n";
}

int main()
{
  int Select,temp;
  while(1)
  {
    Display();
    cout<<"1.����һ��Ԫ�ص�����\n";
    cout<<"2.ɾ��һ��Ԫ�شӶ���\n";
    cout<<"3.�˳�\n";
    cin>>Select;
    switch(Select)
    {
      case 1:
        cout<<"������һ��Ԫ��ֵ��";
        cin>>temp;
        AddQueue(temp);
        break;
      case 2:
        temp=DelQueue();
        if(temp==-1)                        //��������ǿ�
          cout<<"���󣺶���Ϊ��!\n";
        else
          cout<<"����Ԫ��Ϊ�� "<<temp<<endl;
        break;
      case 3:
        return 0;
    }
    system("pause");                        //DOS�µ���ͣ
    system("cls");                          //DOS�µ�����
  }
  return 0;
}

