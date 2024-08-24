//神族文字－ＳＴＬ版
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("dictionary.in","r",stdin);
  freopen("dictionary.out","w",stdout);
  string english,foreign,s;
  map<string,string>translate;//记录Foreign到English的映射
  while(getline(cin,s))//输入字典
  {
    if(s.size()==0)
      break;
    english=s.substr(0,s.find(" "));
    foreign=s.erase(0,s.find(" ")+1);
    translate[foreign]=english;
  }
  while(cin>>s)//开始翻译
  {
    if(translate[s]!="")
      cout<<translate[s]<<endl;
    else
      cout<<"eh"<<endl;
  }
  return 0;
}
