//数组仿真队列
#include <bits/stdc++.h>
using namespace std;

int Queue[5];
int front =-1;                             //头指针
int rear =-1;                              //尾指针

void AddQueue(int value)
{
  if(rear>=4)
    cout<<"错误，队列已满!\n";
  else
    Queue[++rear]=value;
}

int DelQueue()
{
  if(front==rear)
    return -1;
  else
  {
    int v=Queue[++front];                  //队首元素暂存temp
    Queue[front]=0;                        //清空队首元素
    return v;
  }
}

void Display()
{
  for(int i=0; i<5; i++)
    if(Queue[i]!=0)
      cout<<Queue[i]<<' ';
  cout<<"\n队首front="<<front<<" 队尾rear="<<rear<<"\n\n";
}

int main()
{
  int Select,temp;
  while(1)
  {
    Display();
    cout<<"1.输入一个元素到队列\n";
    cout<<"2.删除一个元素从队列\n";
    cout<<"3.退出\n";
    cin>>Select;
    switch(Select)
    {
      case 1:
        cout<<"请输入一个元素值：";
        cin>>temp;
        AddQueue(temp);
        break;
      case 2:
        temp=DelQueue();
        if(temp==-1)                        //如果队列是空
          cout<<"错误：队列为空!\n";
        else
          cout<<"出列元素为： "<<temp<<endl;
        break;
      case 3:
        return 0;
    }
    system("pause");                        //DOS下的暂停
    system("cls");                          //DOS下的清屏
  }
  return 0;
}

