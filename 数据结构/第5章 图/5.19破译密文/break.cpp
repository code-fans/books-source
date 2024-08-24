//破译密文
//网上似乎好多代码是错的，因为不能仅比较相邻的字符串
#include <bits/stdc++.h>
using namespace std;

int n,Map[27][27],ind[27],use[27],cnt,Check[27][27];
string s[30010],str,ans;

int Out(string val)
{
  cout<<val<<endl;
  exit(0);
}

int main()
{
  //freopen("break.in","r",stdin);
  //freopen("break.out","w",stdout);
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    cin>>s[i];
  for (int i = 1; i < n; i++)
    for(int j = i+1; j <= n; j++)
      for(int k=0; k<min(s[i].size(),s[j].size()); k++)
        if (s[i][k]!=s[j][k])
        {
          if(Check[s[j][k]-'a'][s[i][k]-'a']==1) //矛盾
            Out("0");
          Map[s[i][k]-'a'][s[j][k]-'a']=1;       //建图
          if(Check[s[i][k]-'a'][s[j][k]-'a']==0) //还没有标记
          {
            Check[s[i][k]-'a'][s[j][k]-'a']=1;
            ind[s[j][k]-'a']++;
          }
          use[s[i][k]-'a']=1;
          use[s[j][k]-'a']=1;
          break;
        }
  for (int i = 0; i < 26; i++)
    if (use[i])
      cnt++;                          //统计使用的字母数量
  map<char,char> MAP;                 //字典映射
  for (int i = 0,j; i < cnt; i++)
  {
    for (j=0; ind[j] || !use[j]; j++) //寻找入度为0且标记过的字母
      if (j>=26)                      //找不到入度为0且被用过的字母
        Out("0");
    MAP[j+'a']='a'+i;                 //映射
    ind[j]=-1;
    for (int k = 0; k < 26; k++)
      if (Map[j][k])
        ind[k]--;
  }
  cin>>str;
  for (int i = 0; i < str.size(); i++)
  {
    if (!MAP[str[i]])                  //找不到对应的字母
      Out("0");
    ans+=MAP[str[i]];
  }
  Out(string(ans));
}
