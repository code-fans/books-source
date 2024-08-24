#include<bits/stdc++.h>
using namespace std;

int s[30];
int l,r,n,sum;

void DFS(int dep)
{
  if(dep>n) //位数达到要求
  {
    if(sum>0) //sum==0时搜索结果是输入的那个数，舍去
    {
      for(int i=1; i<=n; i++)
        printf("%c",char(s[i]+'a'-1));
      printf("\n");
    }
    sum++;
    if(sum==6) exit(0);//输出5个数后结束程序
    return;
  }
  if(sum>0)
    s[dep]=s[dep-1];//强制保证下一位大于该位（原数除外）
  for(int i=s[dep]+1; i<=r; i++)
  {
    s[dep]=i;
    DFS(dep+1);
  }
}

int main()
{
  //freopen("count.in","r",stdin);
  //freopen("count.out","w",stdout);
  char c;
  scanf("%d%d%d",&l,&r,&n);
  for(int i=1; i<=n; i++)
  {
    cin>>c;
    s[i]=c-'a';
  }
  DFS(1);//从低位开始搜索
  return 0;
}
