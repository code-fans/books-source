//一个简单的二叉查找树的例子,用数组模拟二叉树的结构,使用栈优化
#include <bits/stdc++.h>
#include <windows.h>                   //正式比赛不要加入此头文件 
#define MAX 1000000                    //树中最多结点数
using namespace std;

//data为结点数据,lc,rc为结点的左右孩子
int data[MAX],p[MAX],lc[MAX],rc[MAX];
int root = -1;
int Stack[MAX];                        //用于提供数组空位的栈
int top = 0;

//搜索树上值为k的结点，并返回其在数组中的位置，如果不存在，则返回-1
int tree_search(int R,int k)
{
  while(R != -1 && data[R] != k)
    k<data[R] ? R = lc[R]:R = rc[R];
  return R;
}

void tree_insert(int z)//插入结点z，该结点在pre_insert()过程中已经赋值
{
  int x = root, y = -1;
  while(x != -1)
  {
    y = x;
    if(data[z] < data[x])
      x = lc[x];
    else
      x = rc[x];
  }
  p[z] = y;
  if(y == -1)                        //如果树是空的
    root = z;                        //z就是树根
  else if (data[z] < data[y])
    lc[y] = z;
  else
    rc[y] = z;
}

void pre_insert(int ins_data)        //将结点插入到树中
{
  int z = Stack[top++];
  data[z] = ins_data;
  tree_insert(z);
}

int tree_minimum(int x)              //找树上的最小值
{
  while(lc[x] != -1 )
    x = lc[x];
  return x;
}

int tree_successor(int x)            //求某结点的后继
{
  if(rc[x] != -1)         //若该结点存在右子树，则寻找其右子树最左结点
    return tree_minimum(rc[x]);
  //否则查找其最低祖先，查找直到遇到某个结点是其父结点的左孩子结点为止
  int y = p[x];
  while(y != -1 && x == rc[y])
  {
    x = y;
    y = p[y];
  }
  return y;
}

void tree_delete(int z)         //删除数组z位置上的结点
{
  int Son,y;
  //如果这个结点至多有一个孩子，则删除该结点
  if(lc[z] == -1 || rc[z] == -1)
    y = z;
  else                          //否则寻找其后继
    y = tree_successor(z);

  if(lc[y] != -1)               //将x指向y的左孩子或右孩子(如果有的话)
    Son = lc[y];
  else
    Son = rc[y];

  //如果y有孩子，那么则将在上面步骤中指定过的孩子的父结点指向y的父结点
  if(Son != -1)
    p[Son] = p[y];

  if(p[y] == -1)                   //删除的结点为根结点
    root = Son;
  else if(y == lc[p[y]])           //删除的结点y为y的左孩子
    lc[p[y]] = Son;
  else                             //删除的结点y为y的右孩子
    rc[p[y]] = Son;

  if(y != z)                       //将y的值赋给z
    data[z] = data[y];

  //删除结点 y
  data[y] = -1;
  lc[y] = -1;
  rc[y] = -1;
  p[y] = -1;
  Stack[--top] = y;
}

void pre_delete(int data)                      //删除操作
{
  int k = tree_search(root,data);              //二分查找到k的位置
  if(k != -1)
    tree_delete(k);
}

void init()                                    //初始化所有结点，默认空值为-1
{
  for(int i = 0 ; i < MAX; ++ i)
  {
    data[i] = rc[i] = lc[i] = p[i] = -1;
    Stack[i] = i;
  }
}

void Display(int x)                            //以中序遍历的方式显示
{
  if(x == -1) return ;
  if(lc[x] != -1)
    Display(lc[x]);
  cout<<data[x]<<" left:"<<lc[x]<<" right:"<<rc[x]<<" parent:"<<p[x]<<"\n";
  if(rc[x] != -1)
    Display(rc[x]);
}

void GraphiShow(int root,int x,int y,int k,int space)//图形化输出树
{
  if(root!=-1)
  {
    HANDLE hOutput;
    COORD location;
    location.X=x;
    location.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);        //获得屏幕句柄
    SetConsoleCursorPosition(hOutput,location);     //定位光标到坐标（x,y）处
    if(k==1)
      cout<<data[root]<<"/";                        //输出表示左子树
    else if(k==2)
      cout<<"\\"<<data[root];                       //输出表示右子树
    else
      cout<<data[root];                             //输出根结点
    GraphiShow (lc[root],x-space,y+1,1,space/2);
    GraphiShow (rc[root],x+space,y+1,2,space/2);
  }
}

int main()
{
  int ins,tmp;
  cout<<"1.插入一个值\n";
  cout<<"2.删除一个值\n";
  cout<<"3.图形化输出\n";
  init();
  while(cin>>ins)
  {
    switch(ins)
    {
      case 1:
        cin>>tmp;
        pre_insert(tmp);
        Display(root);                              //中序输出
        break;
      case 2:
        cin>>tmp;
        pre_delete(tmp);
        Display(root);
        break;
      case 3:
        system("cls");
        GraphiShow(root,40,1,0,20);
        break;
      default:
        return 0;
    }
  }
  return 0;
}

