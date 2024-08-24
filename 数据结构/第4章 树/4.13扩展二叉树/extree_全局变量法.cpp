//扩展二叉树
#include <bits/stdc++.h>
using namespace std;

int Left[110],Right[110];                        //保存左儿子、右儿子下标
char Node[110];
int nn=1;//设为全局变量，和引用变量效果是一样的，这样看起来就简单了 

char CreateTree()                          //建树,i为引用变量
{
  int cur=nn;                                     //当前位置cur确定为i
  if(Node[cur]!='.')
  {
    nn++;
    Left[cur]=CreateTree();
    nn++;
    Right[cur]=CreateTree();
  }
  return cur;
}

void Inorder(int i)                              //中序输出
{
  if(Node[i]=='.')
    return;
  Inorder(Left[i]);
  printf("%c",Node[i]);
  Inorder(Right[i]);
}

void Postorder(int i)                            //后序输出
{
  if(Node[i]=='.')
    return;
  Postorder(Left[i]);
  Postorder(Right[i]);
  printf("%c",Node[i]);
}

int main()
{
  //freopen("extree.in","r",stdin);
  //freopen("extree.out","w",stdout);
  gets(Node+1);
  CreateTree();
  Inorder(1);
  printf("\n");
  Postorder(1);
  printf("\n");
  return 0;
}

