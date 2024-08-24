//统计单词数-用string处理
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stat.in","r",stdin);
  freopen("stat.out","w",stdout);
  string a,b;          //string不是基本数据类型，不能用scanf()读入
  getline(cin,a);      //读取string推荐用getline()
  getline(cin,b);
  for (int i=0; i<a.length(); ++i)
    a[i]=tolower(a[i]);//转小写字母，转大写字母为toupper
  for (int i=0; i<b.length(); ++i)
    b[i]=tolower(b[i]);
  a=' '+a+' ';         //单词前后加空格
  b=' '+b+' ';         //文章同步前后加空格
  if (b.find(a)==-1)   //先测试是否有匹配,找不到值为-1
    cout<<-1<<endl;
  else
  {
    int first=b.find(a),count=0;
    for(int P=b.find(a); P<b.length(); P=b.find(a,P+1))
      ++count;
    cout<<count<<" "<<first<<endl;
  }
  return 0;
}
