//统计单词数-string处理
#include <bits/stdc++.h>
using namespace std;

int main()
{

  string a,b;
  getline(cin,a);//读取string推荐用getline()
  getline(cin,b);
  for (int i=0; i<a.length(); ++i)
    a[i]=tolower(a[i]);//转小写字母，转大写字母为toupper
  for (int i=0; i<b.length(); ++i)
    b[i]=tolower(b[i]);
  a=' '+a+' ';//单词前后加空格
  b=' '+b+' ';//文章同步前后加空格
  if (b.find(a)==string::npos)//先测试是否有匹配
    cout<<-1<<endl;
  else
  {
    int first=b.find(a),count=0;
    for(int Pos=b.find(a); Pos!=string::npos; Pos=b.find(a,Pos+1)) //npos表示string的结束位
      ++count;
    cout<<count<<" "<<first<<endl;
  }
  return 0;
}
