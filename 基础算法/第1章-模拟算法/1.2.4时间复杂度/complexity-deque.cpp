//时间复杂度
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("complexity.in","r",stdin);
  freopen("complexity.out","w",stdout);
  int t,L;
  cin>>t;
  while(t--)
  {
    scanf("%d",&L);         //获取代码行数
    string s;
    getline(cin,s);
    int Time=s[3]=='1'?0:(s.size()==7?s[5]-'0':(s[5]-'0')*10+s[6]-'0');//获取时间复杂度
    int RealTime=0,NoLoop=0,Error=0;    //RealTime表示实际的时间复杂度
    deque<int>q1,q2;        //双端队列,一个存所有的循环变量，一个存参加循环的循环变量
    int Visit[101]= {0},InLoop[101]= {0};
    while(L--)
    {
      getline(cin,s);
      if(s[0]=='F')
      {
        int loop=s[2]-'a'+1;             //取循环变量（转为整型）
        q1.push_front(loop);             //加入第一个队列
        if(!Visit[loop])                 //如果loop未被标记
        {
          Visit[loop]=1;                 //标记
          if(s[4]=='n')//如果循环从n开始，并且循环右端点不是n
          {
            if(isdigit(s[6]))
              NoLoop=1;                  //不参加循环
          }
          else
          {
            int t1=atoi(s.substr(4,s.find(' ',5)-4).c_str());//获得循环的起始值
            if(s[s.find_last_of(' ',100)+1]=='n' && NoLoop==0) //如果循环结束值是n并且当前语句参与循环
            {
              q2.push_front(loop);       //参与循环加入第二个队列中
              InLoop[loop]=1;            //标记
              RealTime=max(int(q2.size()),RealTime);//第二个队列中有几个循环变量,那么复杂度就是O(n的几次方)
            }
            if(s[s.find_last_of(' ',100)+1]!='n') //若循环结束值不为n
              if(atoi(s.substr(s.find(' ',5)+1).c_str())<t1)
                NoLoop=1;//如结束值小于起始值，不参加循环
          }
        }
        else Error=1;
      }
      else if(s[0]=='E')
      {
        if(!q1.empty())                  //当第一个队列不为空
        {
          int p=q1.front();
          q1.pop_front();                //弹出队首
          if(InLoop[p])                  //如果队首元素也在第二个队列里
          {
            q2.pop_front();
            InLoop[p]=0;
          }
          Visit[p]=0;
        }
        else Error=1;
        if(q1.empty())
          NoLoop=0;         //如果第一个队列空，该循环体就执行完了
      }
      else
        Error=1;
    }
    if(Error==1 || !q1.empty())
      cout<<"ERR"<<'\n';
    else
      RealTime!=Time?cout<<"No"<<'\n':cout<<"Yes"<<'\n';
  }
  return 0;
}
