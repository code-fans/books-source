//树的图形化显示
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int MAXN=32768;                  //2^15

int n;
struct tree
{
  int Left,Data,Right;
} tree[MAXN];

void Create(int *node,int len)
{
  for(int i=1; i<=len; i++)            //遍历各结点
  {
    tree[i].Data=node[i];              //元素值存入结点
    int pos=0,dir=0;
    while(dir==0)
    {
      if(node[i]<tree[pos].Data)       //判断是否为左子树
        if(tree[pos].Left!=-1)         //如果该位置已被占用,继续往下找
          pos=tree[pos].Left;
        else
          dir=1;                       //设为左树
      else                             //判断是否为右子树
        if(tree[pos].Right!=-1)
          pos=tree[pos].Right;
        else
          dir=-1;                      //设为右树
    }
    dir==1? tree[pos].Left=i:tree[pos].Right=i;
  }
}
//需在程序起始位置加入#include <windows.h>
//形参中x,y为输出结点坐标，k＝0，1，2代表结点为根、左子、右子，space控制输出树宽
void GraphiShow(int root,int x,int y,int k,int space)//图形化
{
  if(root!=-1)
  {
    //此段代码用于定位光标，无需记忆，照抄直接拿来即可
    HANDLE hOutput;
    COORD location;
    location.X=x;
    location.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);       //获得屏幕句柄
    SetConsoleCursorPosition(hOutput,location);    //定位光标到坐标（x,y）处
    if(k==1)
      cout<<tree[root].Data<<"/";                       //输出表示左子树
    else if(k==2)
      cout<<"\\"<<tree[root].Data;                      //输出表示右子树
    else
      cout<<tree[root].Data;                            //输出根结点
    GraphiShow (tree[root].Left,x-space,y+1,1,space/2);
    GraphiShow (tree[root].Right,x+space,y+1,2,space/2);
  }
}


int main()
{
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)
  {
    tree[i].Left=-1;
    tree[i].Data=0;
    tree[i].Right=-1;
  }
  Create(node,n);
  GraphiShow (1,20,3,0,20);
  return 0;
}

