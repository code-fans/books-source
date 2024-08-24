//时间复杂度
#include <bits/stdc++.h>
using namespace std;

int t,L,ans;
struct Code
{
  char F,i;
  int x,y;
} code[200];

int Judge()
{
  stack <int> st;
  int used[256]= {0};
  int time=0,Maxtime=0,stop=0;   //stop是无法进入循环的标志
  for(int i=0; i<L; i++)
    if(code[i].F=='F')
    {
      if(used[code[i].i])        //如果重复定义变量，返回-1
        return -1;
      used[code[i].i]=1;         //变量被使用，标记
      st.push(i);                //代码行数编号入栈
      if(code[i].y-code[i].x<0)  //如不能循环，那么下面嵌套的循环都无效
        stop++;
      if(code[i].y-code[i].x>1e6 && !stop)
        time++;                  //进入n的循环，贡献时间复杂度
      Maxtime=max(Maxtime,time); //更新最大时间复杂度
    }
    else
    {
      if(st.empty())
        return -1;
      used[code[st.top()].i]=0;  //变量被销毁，取消标记
      if(code[st.top()].y-code[st.top()].x>1e6 && !stop)
        time--;
      if(code[st.top()].y-code[st.top()].x<0)
        stop--;
      st.pop();
    }
  return st.size()==0?Maxtime:-1;
}

int main()
{
  freopen("complexity.in","r",stdin);
  freopen("complexity.out","w",stdout);
  cin>>t;
  while(t--)
  {
    scanf("%d",&L);             //获取代码行数
    string S,X,Y;
    getline(cin,S);             //获取时间复杂度，注意S开头有一个空格
    int Time=S[3]=='1'?0:(S.size()==7  ? S[5]-'0' : (S[5]-'0')*10+S[6]-'0');

    for(int i=0; i<L; i++)
    {
      cin>>code[i].F;
      if(code[i].F=='F')
      {
        cin>>code[i].i>>X>>Y;
        code[i].x=(X=="n"?1e8:atoi(X.c_str()));//string转char用c_str()
        code[i].y=(Y=="n"?1e8:atoi(Y.c_str()));//atoi将*char转为整数
      }
    }
    int ans=Judge();
    ans==-1?printf("ERR\n"):printf("%s\n",ans==Time?"Yes":"No");
  }
  return 0;
}
