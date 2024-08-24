#include<bits/stdc++.h>
using namespace std;

int s,t,w,cnt;
int a[30];

inline void Output()
{
  for(int i=1; i<=w; i++)
    cout<<(char)('a'+a[i]-1);
  cout<<endl;
}

void Dfs(int pos)
{
  if(pos==0)
    return;
  if(a[pos]<t-(w-pos) && (a[pos]<a[pos+1]-1 || pos==w))//该位可以加
  {
    a[pos]++;
    for(int i=pos+1; i<=w; i++)
      a[i]=a[i-1]+1;
    Output();
    if(++cnt==5)                                //输出了五个退出
      exit(0);
    Dfs(w);                                     //从头再找下一个
  }
  else
    Dfs(pos-1);                                 //该位不能加1，则向前一位
}

int main()
{
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  string str;
  cin>>s>>t>>w>>str;
  for(int i=0; i<str.size(); i++)
    a[i+1]=str[i]-'a'+1;
  Dfs(w);
  return 0;
}
