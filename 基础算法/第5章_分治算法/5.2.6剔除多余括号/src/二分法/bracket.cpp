//剔除多余括号-二分法
#include <bits/stdc++.h>
using namespace std;

int a[1024];
char s[1024];

int Cal(int L, int R, int prev_min)
{
  int min=4, min_pos;          //min_pos为最低运算符的位置
  for (int i=L; i<=R; i++)     //扫描找出最低运算符,并标记位置
  {
    if(s[i]=='^')
    {
      if (min>3)
        min=3, min_pos=i;      //标记"^"运算符优先级为3
    }
    else if(s[i]=='*' || s[i]=='/')
    {
      if (min>2)
        min=2, min_pos=i;      //标记"*"和"/"运算符优先级为2
    }
    else if(s[i]=='+' || s[i]=='-')
    {
      if (min>1)
        min=1, min_pos=i;      //标记"+"和"-"运算符优先级为1
    }
    else if(s[i]=='(')         //遇到左括号，跳过括号内的字符，找到匹配的右括号
    {
      i++;
      for (int t=1; t!=0; i++)
      {
        if (s[i]=='(')         //对括号内多重左括号和右括号的处理
          t++;
        if (s[i]==')')
          t--;
      }
      i--;
    }
  }
  if (min==4)                  //去括号操作
  {
    if (s[L]=='(' && s[R]==')')//如果首尾即为括号
    {
      int t=Cal(L+1,R-1,0);    //求出除去首尾括号继续递归的返回值min
      if (t>=prev_min)
      {
        a[L]=a[R]=1;           //将首尾的括号标记为多余
        return t;
      }
    }
  }
  else
  {
    Cal(L,min_pos-1,min);        //递归最低运算符前端的式子
    if (s[min_pos]=='+' || s[min_pos]=='*')
      Cal(min_pos+1,R,min);      //递归最低运算符后端的式子
    else                         //最低运算符是"-"或"/"
      Cal(min_pos+1,R,min+1);    //递归最低运算符后端的式子，但运算优先级+1
  }
  return min;
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  cin>>s;
  int len=strlen(s);
  Cal(0,len-1,0);
  for (int i=0; i<len; i++)
    if (!a[i])                 //当前位标记为0，则输出
      cout<<s[i];
  cout<<'\n';
  return 0;
}
