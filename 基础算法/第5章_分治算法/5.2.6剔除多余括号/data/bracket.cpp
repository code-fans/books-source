//剔除多余括号-非二分法
#include <bits/stdc++.h>
using namespace std;

char s[10010];
bool vis[10010];
int len;

int FindMinOp(int Left,int Right)   //返回匹配括号中的最低级运算符
{
  for(int i=Left; i<=Right; i++)
    if(s[i] == '-' || s[i] == '+')
      return s[i];
}

int FirstLeft()                     //从右向左查找到第一个左括号
{
  for(int j=len-1; j>=0; j--)
    if(s[j] == '(')
      return s[j];
}

int FindRight(int Left)             //寻找左括号的匹配右括号
{
  for(int R=Left+1,cnt=1; R<len; ++R)
  {
    if(s[R] == '(')
      cnt++;
    if(s[R] == ')')
      cnt--;
    if(cnt==0)
      return R;
  }
}

void Work()                         //判断括号是否可删除
{
  for(int i=FirstLeft(); i>=0; i--) //从最内层括号向左扫描
    if(s[i]=='(')
    {
      int R=FindRight(i);           //找到相匹配的右括号
      char MinOp=FindMinOp(i,R);    //找到最低级的运算符
      if(s[i-1]=='/')               //若左括号前为/，则不可删除
        continue;
      else if((s[i-1]=='*' || s[i-1]=='-') && (MinOp=='+' || MinOp=='-'))
        continue;//若左括号前为*,-，且括号内最低运算符为+,-则不可删除
      else if((s[R+1]=='/' || s[R+1]=='*') && (MinOp=='+' || MinOp=='-'))
        continue;//若右括号后为/,*,且括号内最低运算符为+,- 则不可删除
      else
      {
        vis[i]=true;                //左括号可以删除
        vis[R]=true;                //右括号可以删除
      }
    }
}

int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  scanf("%s",s);
  len=strlen(s);
  Work();
  for(int i=0; i<len; i++)
    if(!vis[i])
      printf("%c",s[i]);
  puts("");
  return 0;
}
