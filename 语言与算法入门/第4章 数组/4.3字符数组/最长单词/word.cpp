//最长单词
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  char s[30000];
  int i=0,j,Long=0,m=0;
  cin.getline(s,30000-1);
  while(s[i]!='\0')//遍历字符串
  {
    j=0;
    while(s[i]!=' ' && s[i]!='\0')//统计每个单词的长度
    {
      j++;//j用来统计单词长度
      i++;//i用来统计扫描过的字符串长度是多少
    }
    if(j>Long)//筛选最长的单词
    {
      m=i-j;//标记该单词位置
      Long=j;
    }
    while(s[i]==' ')//空格也要统计到字符串长度内
      i++;
  }
  while(s[m]!=' ' &&s[m]!='\0')//从标记位输出最长单词,直到空格或结束
  {
    printf("%c",s[m]);
    m++;
  }
  printf("\n");
  return 0;
}

