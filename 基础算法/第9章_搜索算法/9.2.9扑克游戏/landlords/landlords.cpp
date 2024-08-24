//斗地主
#include <bits/stdc++.h>
using namespace std;

int Card[15];
int ans;
void DFS(int step);

void Straight(int step,int Max,int num)//连成最少Max张的顺子
{
  int j;
  for(int i=1; i<=11; i++)             //枚举
  {
    for(j=i; j<=12; j++)
    {
      Card[j]-=num;                    //把连成顺子的牌拿走
      if(Card[j]<0) break;             //连不成顺子则退出
      if(j-i>=Max)
        DFS(step+1);
    }
    for(int k=i; k<=j && k!=13; k++)   //恢复原样
      Card[k]+=num;
  }
}

void DFS(int step)
{
  if(step>ans)  return;                //剪枝
  int s1=0,s2=0,s3=0,s4=0;             //单张，对子，三张，四张
  for(int i=1; i<=14; i++)
  {
    if(Card[i]==1) s1++;               //统计单牌个数
    if(Card[i]==2) s2++;               //统计对牌个数
  }
  for(int i=1; i<=13; i++)             //杂牌能带的先带走
    if(Card[i]==4)
    {
      s4++;
      if(s1>=2) s1-=2;                 //四带二张
      else if(s2>=2) s2-=2;            //四带两对
      else if(s2>=1) s2--;             //四带一对
    }
  for(int i=1; i<=13; i++)
    if(Card[i]==3)
    {
      s3++;
      if(s1>=1) s1--;                  //三带一张
      else if(s2>=1) s2--;             //三带一对
    }
  ans=min(ans,step+s1+s2+s3+s4);       //先求出带牌后的情况
  Straight(step,4,1);                  //再求出单顺子的情况
  Straight(step,2,2);                  //再求出双顺子的情况
  Straight(step,1,3);                  //再求出三顺子的情况
}

int main()
{
  //freopen("landlords.in","r",stdin);
  //freopen("landlords.out","w",stdout);
  int T,n;
  for(cin>>T>>n; T--; cout<<ans<<endl)
  {
    ans=n;
    memset(Card,0,sizeof(Card));
    for(int i=1,a,b; i<=n; i++)
    {
      cin>>a>>b;
      if(a==0)  a+=16;
      if(a==1 || a==2) a+=13;
      Card[a-2]++;
    }
    DFS(0);
  }
  return 0;
}
