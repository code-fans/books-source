//侦探推理
#include <bits/stdc++.h>
using namespace std;

int lie[25],whosay[200]; //lie用于标记是否说谎,whosay[]保存谁说了这句话
int ERR,guilt;
string name[105],say[205];
string week[8]= {" ","Today is Sunday.",
                 "Today is Monday.",
                 "Today is Tuesday.",
                 "Today is Wednesday.",
                 "Today is Thursday.",
                 "Today is Friday.",
                 "Today is Saturday.",
                };

void Judge(int who,int guilt)
{
  if(lie[who] && lie[who]!=guilt)     //说一个人又是罪犯又不是罪犯，错误
    ERR=1;
  else
    lie[who]=guilt;
}

int main()
{
  //freopen("LOGIC.in","r",stdin);
  //freopen("LOGIC.out","w",stdout);
  int m,n,p;
  cin>>m>>n>>p;
  for(int i=1; i<=m; i++)
    cin>>name[i];
  for(int i=1; i<=p; i++)
  {
    string man;
    cin>>man;
    man=man.substr(0,man.length()-1); //去冒号
    for(int j=1; j<=m; j++)
      if(name[j]==man)
        whosay[i]=j;                  //判断这句话是谁说的
    getline(cin,say[i]);
    say[i]=say[i].substr(1,say[i].length()-1);//某些网站上的数据还需特别处理
  }
  for(int today=1; today<=7; today++) //枚举今天是星期几
    for(int G=1; G<=m; G++)           //枚举罪犯
    {
      ERR=0;                          //清除标记
      memset(lie,0,sizeof(lie));
      for(int i=1; i<=p; i++)         //依次判断每句话
      {
        int who=whosay[i];
        if(say[i]=="I am guilty.")    //说自己是罪犯
          Judge(who,G==who?1:-1);
        if(say[i]=="I am not guilty.")//说自己不是罪犯
          Judge(who,G!=who?1:-1);
        for(int j=1; j<=m; j++)       //说对了就是真话，否则就是假话
        {
          if(say[i]==name[j]+" is guilty.")
            Judge(who,j==G?1:-1);
          if(say[i]==name[j]+" is not guilty.")
            Judge(who,j!=G?1:-1);
        }
        for(int j=1; j<=7; j++)
          if(say[i]==week[j])         //判断今天是星期几是真是假
            Judge(who,j==today?1:-1);
      }
      int liecount=0,uncertain=0;     //liecount:说假话的人数，uncertain:不确定的人数
      for(int i=1; i<=m; i++)
      {
        if(lie[i]==-1) liecount++;
        if(lie[i]==0)  uncertain++;
      }
      if(!ERR && liecount+uncertain>=n && liecount<=n)
        if(guilt && guilt!=G)         //出现了两个合理的罪犯
        {
          cout<<"Cannot Determine\n";
          return 0;
        }
        else guilt=G;
    }
  cout<<(guilt?name[guilt]:"Impossible")<<endl;
}
