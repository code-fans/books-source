//单词接龙
#include <bits/stdc++.h>
using namespace std;

int n,Len,Max;
int used[100001],l[100001];
string s[10001];

int Find(int a, int b)        //是否能合并
{
  for(int i=l[a]-1; i>=1; i--)
    if(s[a][i] == s[b][0])
    {
      for(int j=i+1,k=1; j<=l[a]-1; j++,k++)
        if(s[a][j] != s[b][k])//有一个字母不相等就返回0
          return 0;
      return l[b]- (l[a]-i);      //全相等返回长度
    }
  return 0;
}

void Dfs(int x)//搜索单词
{
  for(int i = 1; i <= n; i++)
    if(used[i] < 2 && Find(x, i))//不能用两次且可以接龙
    {
      used[i]++;//用的次数++
      Len += Find(x, i);//加上新单词的长度
      Dfs(i);//接着这个单词继续搜
      used[i]--;//回溯
      Len -= Find(x, i);//回溯
    }
  Max=max(Max,Len);
}

int main()
{
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    cin>>s[i];
    l[i] = s[i].length();//存下所有单词的长度
  }
  char ch;
  cin>>ch;
  for(int i = 1; i <= n; i++)
    if(s[i][0] == ch)    //首字母相同才能接
    {
      Len = l[i];        //初始长度
      used[i]++;
      Dfs(i);
      used[i]--;         //回溯
    }
  printf("%d\n", Max);
  return 0;
}
