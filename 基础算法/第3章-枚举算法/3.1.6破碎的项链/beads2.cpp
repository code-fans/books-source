//破碎的项链
#include<bits/stdc++.h>
using namespace std;

char s[700],c;
int Left, Right, White, ans;

int main()
{
  //freopen("beads.in","r",stdin);
  //freopen("beads.out","w",stdout);
  int n;
  scanf("%d%s",&n,s);
  memcpy(s+n,s,n);          //从s+n处拷贝s，共n个 
  int N=(n<<1);             //长度为原字符串的两倍
  for(int i = 0; i <N; i++)
    if(s[i] == 'w')
    {
      Right++;
      White++;
    }
    else if(s[i] ==  c )
    {
      Right++;
      White=0;
    }
    else
    {
      c=s[i];
      ans=max(ans,Left+Right);
      Left=Right-White;
      Right=White+1;
      White=0;
    }
  printf("%d\n",min(max(ans,Left+Right),n));
  return 0;
}
