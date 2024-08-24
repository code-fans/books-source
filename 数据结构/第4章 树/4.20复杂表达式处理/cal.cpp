//复杂表达式处理
#include <bits/stdc++.h>
using namespace std;

char str[1000];
char op[1000];                          //保存操作符
int Num[1000],lch[1000], rch[1000];
int Index=0;                            //如写成index在Linux下无法通过

int BuildTree(char *st, int L, int R)   //建二叉树
{
  int flag=1;
  for(int i=L; i<R; i++)
  {
    if(!(st[i]>='0' && st[i]<='9'))     //判断是否有操作符
    {
      flag=0;
      break;
    }
  }
  if(flag)                              //如果全是数字,处理后返回
  {
    int sum=0;
    int j=1;
    for(int i=R-1; i>=L; i--)
    {
      sum+=(st[i]-'0')*j;
      j*=10;
    }
    int u=++Index;                      //下标从1开始
    lch[u]=0;
    rch[u]=0;
    Num[u]=sum;
    return u;
  }
  int c1=-1;                            //标记加减的操作符
  int c2=-1;                            //标记乘除的操作符
  int p=0;                              //标记括号的匹配数
  for(int i=L; i<R; i++)
  {
    if(st[i]=='(')
      p++;
    if(st[i]==')')
      p--;
    if(st[i]=='+' || st[i]=='-')
      if(p==0)                          //不在括号内
        c1=i;
    if(st[i]=='*' || st[i]=='/')
      if(p==0)
        c2=i;
  }
  if(c1<0)                              //如果没有加减
    c1=c2;                              //那么就乘除
  if(c1<0)                              //如果仍然没有运算符
    return BuildTree(str,L+1, R-1);     //去两端的括号后递归
  int u=++Index;
  lch[u]=BuildTree(st, L, c1);          //考虑为什么不是c1-1而是c1
  rch[u]=BuildTree(st, c1+1, R);
  op[u]=st[c1];
  return u;                             //递归不能返回Index,否则值会乱
}

double Cal(int i)                       //计算二叉树形式的表达式值
{
  if(lch[i]==0 && rch[i]== 0)
    return Num[i];
  else  if(op[i]=='+')
    return Cal(lch[i]) + Cal(rch[i]);
  else if(op[i]=='-')
    return Cal(lch[i]) - Cal(rch[i]);
  else if(op[i]=='*')
    return Cal(lch[i]) * Cal(rch[i]);
  else if(op[i]=='/')
    return Cal(lch[i]) / Cal(rch[i]);
  return 0;
}

int main()
{
  freopen("cal.in","r",stdin);
  freopen("cal.out","w",stdout);
  while(cin>>str)
  {
    Index=0;                            //结点下标数初始为0
    BuildTree(str, 0, strlen(str));
    printf("%.2f\n", Cal(1));
  }
  return 0;
}

