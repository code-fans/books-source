//简单表达式处理
#include<bits/stdc++.h>
using namespace std;

char str[200];
int l[200],r[200];

int BuildTree(int i,int j)
{
  int k,posi;
  if(i==j)                              //当只有一个字符时
  {
    l[i]=-1;                            //没有左儿子
    r[i]=-1;                            //没有右儿子
    return i;
  }
  for(k=i; k<=j; k++)
    if(str[k]=='+' || str[k]=='-')      //查找"+"和"-"
    {
      posi=k;                           //确定运算符位置
      break;
    }
  if(k>j)                               //如没有"+"和"-",就查找"*"和"/"
    for(int p=i; p<=j; p++)
      if(str[p]=='*' || str[p]=='/')    //查找
      {
        posi=p;                         //确定运算符位置
        break;
      }
  l[posi]=BuildTree(i,posi-1);          //运算符前一半递归
  r[posi]=BuildTree(posi+1,j);          //运算符后一半递归
  return posi;
}

void DispPre(int T)                     //打印前序表达式
{
  if(T!=-1)
  {
    printf("%c",str[T]);
    DispPre(l[T]);
    DispPre(r[T]);
  }
}

void DispIn(int T)                      //打印中序表达式
{
  if(T!=-1)
  {
    DispIn(l[T]);
    printf("%c",str[T]);
    DispIn(r[T]);
  }
}

void DispPost(int T)                    //打印后序表达式
{
  if(T!=-1)
  {
    DispPost(l[T]);
    DispPost(r[T]);
    printf("%c",str[T]);
  }
}

int main()
{
  //freopen("calc.in","r",stdin);
  //freopen("calc.out","w",stdout);
  cin.getline(str,200);
  int root=BuildTree(0,strlen(str)-1);
  DispPre(root);
  cout<<endl;
  DispIn(root);
  cout<<endl;
  DispPost(root);
  cout<<endl;
  return 0;
}

