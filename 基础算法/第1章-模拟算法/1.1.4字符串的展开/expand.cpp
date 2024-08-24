//字符串的展开
#include <bits/stdc++.h>
using namespace std;

int p1,p2,p3;
string S,Ans;

char ToChar(char ch)
{
  if(p1==3)
    return '*';
  return p1==1?tolower(ch):toupper(ch);
}

int main()
{
  //freopen("expand.in","r",stdin);
  //freopen("expand.out","w",stdout);
  cin>>p1>>p2>>p3>>S;
  S=' '+S+' ';//字符串两端各加一个空格，防止'-'出现在开头或末尾
  for(int i=1; i<S.size()-1; i++)
  {
    if(S[i]!='-')
      Ans+=S[i];
    else
    {
      char s=S[i-1],t=S[i+1];
      if(s<t && (islower(s) && islower(t) || isdigit(s) && isdigit(t)))
      {
        if(p3==1)
          for(char i=s+1; i<=t-1; i++)//正序
            for(int j=0; j<p2; j++)
              Ans+=ToChar(i);
        else
          for(char i=t-1; i>=s+1; i--)//逆序
            for(int j=0; j<p2; j++)
              Ans+=ToChar(i);
      }
      else
        Ans+='-';
    }
  }
  cout<<Ans<<endl;
  return 0;
}

