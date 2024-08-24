//循环队列演示程序
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5                       //队列的最多元素个数

int Queue[MAXN];
int Front=0;                         //头指针
int Rear=0;                          //尾指针

void AddQueue(int value)             //输入value值入队列
{
  if((Rear+1)%MAXN==Front)
    cout<<"队满"<<endl;
  else
  {
    Queue[Rear]=value;
    Rear=(Rear+1)%MAXN;
  }
}

int DelQueue()                       //删除队列数据
{
  if(Front==Rear)
    cout<<"队列为空"<<endl;
  else
  {
    int temp=Queue[Front];
    Queue[Front]=-1;                //取出后该位置设置为-1
    Front=(Front+1)%MAXN;           //指向下一位置
    return temp;                    //输出元素值
  }
}

void Display()                      //显示队列里所有的元素
{
  for(int i = 0 ; i < MAXN; ++ i)
    cout<<Queue[i]<<" ";
  cout<<endl;
}

void Init()                         //初始化队列，设定空值为-1
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
    cout<<"1.输入一个元素值到队列\n";
    cout<<"2.删除一个元素值从队列\n";
    cout<<"3.退出\n";
    cin>>Select;
    switch(Select)
    {
      case 1:
        cout<<"请输入一个值：";
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

