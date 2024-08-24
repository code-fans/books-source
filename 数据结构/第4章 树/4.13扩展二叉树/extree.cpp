//扩展二叉树
#include <bits/stdc++.h>
using namespace std;

int Left[110],Right[110];                        //保存左儿子、右儿子下标
char Node[110];

char CreateTree(int& i)                          //建树,i为引用变量
{
  int cur=i;                                     //当前位置cur确定为i
  if(Node[cur]!='.')
  {
    i++;
    Left[cur]=CreateTree(i);
    i++;
    Right[cur]=CreateTree(i);
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
  freopen("extree.in","r",stdin);
  freopen("extree.out","w",stdout);
  cin.getline(Node+1,110);
  int n=1;
  CreateTree(n);                                 //将变量n作为参数传递
  Inorder(1);
  printf("\n");
  Postorder(1);
  printf("\n");
  return 0;
}

