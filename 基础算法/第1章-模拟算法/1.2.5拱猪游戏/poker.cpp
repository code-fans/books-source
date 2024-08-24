//拱猪游戏
#include <bits/stdc++.h>
using namespace std;

int s[17]= {0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40,-100,100};//分值

void Out(int t)
{
  if(t>0)
    cout<<'+';
  cout<<t<<' ';
}

int main()
{
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  while(1)
  {
    int MAP[5][17]= {0};                   //设置牌的状态均为0
    int Num[5]= {0};                       //保存每人拿的牌的张数
    for(int i=1; i<=4; i++)
    {
      cin>>Num[i];
      for(int j=1,p; j<=Num[i]; j++)
      {
        char k;
        cin>>k>>p;                         //读入牌的种类和序号
        if(k=='H') MAP[i][p] =1;           //如果是红心牌，标记
        if(k=='S') MAP[i][14]=1;           //如果是黑桃，肯定是猪牌，标记
        if(k=='D') MAP[i][15]=1;           //如果是方块，肯定是羊牌，标记
        if(k=='C') MAP[i][16]=1;           //如果是梅花，肯定是加倍牌，标记
      }
    }
    if(Num[1]+Num[2]+Num[3]+Num[4]==0)     //退出的判断
      break;
    for(int i=1; i<=4; i++)                //开始计分
    {
      int Score=0,AllH=1;                  //AllH判断是否全是红心
      for(int j=1; j<=13 && AllH; j++)
        AllH=MAP[i][j];
      if(AllH)                             //如果全是红心
      {
        Score=200;
        if(MAP[i][14] && MAP[i][15])       //如果同时拿黑桃Q和方块J
          Score=500;                       //加500
        else
          Score+=MAP[i][14]*s[14]+MAP[i][15]*s[15];//否则单独算分
        Out(MAP[i][16]?(Score<<1):Score);  //可能翻倍
      }
      else
      {
        bool OnlyC10=true;
        for(int j=1; j<=15 && OnlyC10; j++)//判断是不是除了C10,其它牌都没有
          OnlyC10=!MAP[i][j];
        if(OnlyC10)
          Out(MAP[i][16]?50:0);            //只有C10，则加50
        else
        {
          for(int j=1; j<=15; j++)
            Score+=MAP[i][j]*s[j];
          Out(MAP[i][16]?(Score<<1):Score);//可能翻倍
        }
      }
    }
    cout<<endl;
  }
  return 0;
}

