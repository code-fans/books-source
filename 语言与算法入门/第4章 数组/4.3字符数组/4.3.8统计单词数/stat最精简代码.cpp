//统计单词数-最精简代码
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("stat.in","r",stdin);
  //freopen("stat.out","w",stdout);
  string a,b;
  getline(cin,a);//读取string推荐用getline()
  getline(cin,b);
  transform(a.begin(),a.end(),a.begin(),::tolower);//全部转小写
  transform(b.begin(),b.end(),b.begin(),::tolower);
  a=' '+a+' ';//单词前后加空格
  b=' '+b+' ';//文章同步前后加空格
  int first=b.find(a),count=0;//计数器初始化为0
  for(int P=b.find(a); P!=string::npos; P=b.find(a,P+1))
    ++count;
  first==string::npos?cout<<"-1\n":cout<<count<<" "<<first<<endl;
  return 0;
}

