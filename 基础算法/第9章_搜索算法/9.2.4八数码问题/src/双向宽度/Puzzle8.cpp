//八数码问题 - 双向宽度搜索演示
#include <bits/stdc++.h>
using namespace std;

struct node
{
  string str;                                 //保存字符串形式的八数码
  int pre;                                    //保存上一步的位置
};
vector <node> c[2];
int p1,p2,t1,t2;                              //p1,p2指向队首,t1,t2指队尾
int Step;                                     //Step为交换次数

void OutC1(int v)                             //递归逆序输出队列1
{
  Step++;
  if(v==0)
    cout<<c[0][v].str<<endl;
  else
  {
    OutC1(c[0][v].pre);
    cout<<c[0][v].str<<endl;
  }
}

void OutC2(int v)                             //输出队列2
{
  while(1)
  {
    Step++;
    if(c[1][v].str=="123804765")
    {
      cout<<"123804765\n";
      break;
    }
    cout<<c[1][v].str<<endl;
    v=c[1][v].pre;
  }
}

int Check(int idx,string str,int key)         //key为0,仅查找本队列元素
{
  for(int i=0; i<c[idx].size(); i++)
    if(str==c[idx][i].str)
    {
      if(key==1)                              //key为1
        idx==0? t1=i:t2=i;                    //确定另一队列的重合位置
      return 1;
    }
  return 0;
}

void BFS(int idx,int &p,int O,int loc)
{
  string st=c[idx][p].str;
  swap(st[O],st[O+loc]);                      //交换数码
  if(Check(idx,st,0)==0)                      //查找本队列是否有相同
    c[idx].push_back(node {st,p});            //注意是C++11写法
  if(Check((idx+1)%2,st,1))                   //查找另一队列是否有重合
  {
    idx==0?t1=c[0].size()-1:t2=c[1].size()-1; //确定当前队列的队尾
    OutC1(c[0][t1].pre);
    OutC2(t2);
    printf("%d\n",Step-1);
    exit(0);                                  //直接退出程序，返回0值
  }
}

void Add(int idx,int &p)                      //添加队列2
{
  int O=c[idx][p].str.find('0',0);            //查找数码串中0的位置
  if(O >= 3)                                  //向上搜索
    BFS(idx,p,O,-3);                          //-3为要交换位置的偏移量
  if(O < 6)
    BFS(idx,p,O,3);                           //向下搜索
  if((O % 3) > 0)
    BFS(idx,p,O,-1);                          //向左搜索
  if((O % 3) < 2)
    BFS(idx,p,O,1);                           //向右搜索
  p++;                                        //队首指针后移，即出队
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  string star;
  for(int i=0,t; i<=8; i++)
  {
    scanf("%d",&t);
    star+=t+'0';
  }
  string goal="123804765";                    //目标状态
  c[0].push_back(node {star,0});              //队列1存入初始值，C++11写法
  c[1].push_back(node {goal,0});              //队列2存入目标值，C++11写法
  while(c[0].size()<5000 || c[1].size()<5000)
    c[0].size()<=c[1].size()?Add(0,p1):Add(1,p2); //优先扩展短队列
  printf("-1\n");
  return 0;
}

