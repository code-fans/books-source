//单词查找树
#include <bits/stdc++.h>
using namespace std;

string a[10000];

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n=0;
  while(cin>>a[++n]);
  sort(a+1,a+1+n);
  int t=a[1].length();                  //先累加第一个单词的长度
  for(int i=2; i<=n; i++)
  {
    int j=0;
    while(a[i][j]==a[i-1][j] && j<a[i-1].length())
      j++;                              //求两个单词相等部分的长度
    t+=a[i].length()-j;                 //累加
  }
  cout<<t+1<<endl;                      //注意最后要加一
  return 0;
}

