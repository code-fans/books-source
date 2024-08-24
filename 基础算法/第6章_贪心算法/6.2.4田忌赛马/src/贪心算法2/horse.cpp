//田忌赛马 - 贪心算法二
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("horse.in","r",stdin);
  //freopen("horse.out","w",stdout);
  int tian[1001], king[1001], n;
  while (scanf("%d", &n), n)
  {
    for (int i=0; i<n; i++)
      scanf("%d", &tian[i]);
    for (int j=0; j<n; j++)
      scanf("%d", &king[j]);
    sort(tian, tian+n);
    sort(king, king+n);
    bool visit1[1001]= {0};
    bool visit2[1001]= {0};
    int win=0, fail=0;                 //win:田忌赢的次数，fail：未比赛的马数
    for (int i=0; i<n; i++)
      for (int j=n-1; j>=0; j--)
        if (tian[i]>king[j] && !visit2[j])   //田忌的马找尽量快的对手并且获胜
        {
          win++;
          visit1[i]=visit2[j]=true;
          break;
        }
    for (int i=0; i<n; i++)
      if (!visit1[i])
      {
        for (int j=0; j<n; j++)
          if (!visit2[j] && tian[i]==king[j])//寻找平局的马
          {
            visit1[i]=visit2[j]=true;
            break;
          }
        if(!visit1[i])
          fail++;
      }
    cout<<(win-fail)*200<<endl;
  }
  return 0;
}

