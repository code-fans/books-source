//通天塔
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int h,a,c;
} stone[405];
bool dp[40005];//dp[i]表示该高度是否达到

bool Cmp(node a,node b)
{
  return a.a<b.a;
}

int main()
{
  //freopen("Elevator.in","r",stdin);
  //freopen("Elevator.out","w",stdout);
  int k;
  cin>>k;
  for(int i=0; i<k; i++)
    scanf("%d%d%d",&stone[i].h,&stone[i].a,&stone[i].c);
  sort(stone,stone+k,Cmp);
  dp[0]=1;
  for(int i=0; i<k; i++)                       //枚举石头
    for(int j=0; j<stone[i].c; j++)            //枚举j种石头的数量
      for(int h=stone[i].a; h>=stone[i].h; h--)//枚举高度
        dp[h]|=dp[h-stone[i].h];               //dp[h]或dp[h-stone[i].h为真
  for(int i=stone[k-1].a; i>=0; i--)
    if(dp[i])
    {
      cout<<i<<endl;
      return 0;
    }
  return 0;
}

