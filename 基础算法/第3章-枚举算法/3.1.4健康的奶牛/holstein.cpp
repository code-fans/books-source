//健康的奶牛
#include <bits/stdc++.h>
using namespace std;

int need[505],feed[505][505],save[50005][505];

int main()
{
  //freopen("holstein.in","r",stdin);
  //freopen("holstein.out","w",stdout);
  int V,G,ansN=0x7f7f7f7f,pos;    //ansN为答案，即最少饲料数
  cin>>V;
  for(int i=1; i<=V; i++)
    cin>>need[i];
  cin>>G;
  for(int i=1; i<=G; i++)
    for(int j=1; j<=V; j++)
      cin>>feed[i][j];
  for(int i=0; i<(1<<G); i++)         //二进制枚举子集
  {
    int Nfeed=0,temp[505]= {0},ok=1;  //Nfeed统计当前用到的饲料数
    for(int j=0; j<G; j++)            //枚举第j+1位
      if(i&(1<<j))                    //如果该位为1
      {
        save[i][++Nfeed]=j;           //顺序记录用到的饲料
        for(int k=1; k<=V; k++)
          temp[k]+=feed[j+1][k];      //增加总维他命量
      }
    if(ansN>Nfeed)                    //记录最小答案
    {
      for(int j=1; j<=V; j++)         //判断维他命够不够
        if(temp[j]<need[j])
        {
          ok=0;
          break;
        }
      if(ok)
      {
        ansN=Nfeed;                   //记录最小答案饲料个数
        pos=i;                        //记录最小答案的二进制子集的位置
      }
    }
  }
  cout<<ansN<<' ';
  for(int i=1; i<=ansN; i++)
    cout<<save[pos][i]+1<<(i==ansN?'\n':' ');
  return 0;
}
