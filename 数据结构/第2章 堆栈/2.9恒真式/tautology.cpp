//恒真式
//从右到左扫描前缀表达式，遇操作数则入栈，
//遇n元操作符则弹出n个操作数进行运算并将运算结果入栈。
//最终在栈中的唯一操作数即为值
#include <bits/stdc++.h>
using namespace std;

int p,q,r,s,t;
char inStr[101];
stack<int> sta;

bool Solve()
{
  while(!sta.empty())                      //每次清空堆栈
    sta.pop();
  int fir,sec;
  for(int i=strlen(inStr)-1; i>=0; --i)
  {
    switch(inStr[i])
    {
      case 'p':
        sta.push(p);
        break;
      case 'q':
        sta.push(q);
        break;
      case 'r':
        sta.push(r);
        break;
      case 's':
        sta.push(s);
        break;
      case 't':
        sta.push(t);
        break;
      case 'K':
        fir=sta.top();
        sta.pop();
        sec=sta.top();
        sta.pop();
        sta.push(fir && sec);
        break;
      case 'A':
        fir=sta.top();
        sta.pop();
        sec=sta.top();
        sta.pop();
        sta.push(fir || sec);
        break;
      case 'N':
        fir=sta.top();
        sta.pop();
        sta.push(!fir);
        break;
      case 'C':
        fir=sta.top();
        sta.pop();
        sec=sta.top();
        sta.pop();
        sta.push( sec<= fir);  //sec<= fir  等价于sec||!fir
        break;
      case 'E':
        fir=sta.top();
        sta.pop();
        sec=sta.top();
        sta.pop();
        sta.push( sec== fir);
        break;
    }
  }
  return sta.top();
}

int main()
{
  //freopen("tautology.in","r",stdin);
  //freopen("tautology.out","w",stdout);
  int okn;
  while(cin>>inStr,inStr[0]!='0')
  {
    okn=0;                                               //枚举32种情况
    for(p=0; p<2; ++p)
      for(q=0; q<2; ++q)
        for(r=0; r<2; ++r)
          for(s=0; s<2; ++s)
            for(t=0; t<2; ++t)
              if(Solve()==0)
                break;
              else ++okn;
    cout<<(okn==32?"tautology":"not")<<endl;
  }
  return 0;
}
