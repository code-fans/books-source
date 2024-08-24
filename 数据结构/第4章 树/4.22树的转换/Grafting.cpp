//树的转换
#include <bits/stdc++.h>
using namespace std;
int h1,h2,num;
char s[200005];

void Dfs(int tree1,int tree2)           //tree1代表树1高度，tree2代表树2高度
{
  int son=0;
  while (s[num]=='d')
  {
    num++;
    son++;
    Dfs(tree1+1,tree2+son);
  }
  num++;
  h1=max(h1,tree1);
  h2=max(h2,tree2);
}

int main()
{
  //freopen("Grafting.in","r",stdin);
  //freopen("Grafting.out","w",stdout);
  int T=0;
  scanf("%s",s);
  while (s[0]!='#')
  {
    h1=h2=num=0;
    Dfs(0,0);
    printf("Tree %d: %d => %d\n",++T,h1,h2);
    scanf("%s",s);
  }
}

