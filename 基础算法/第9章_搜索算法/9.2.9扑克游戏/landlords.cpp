//斗地主
#include <bits/stdc++.h>
using namespace std;

int Card[15];
int ans;

void DFS(int step)
{
  if(step>ans)  return;  //剪枝
  int s1=0,s2=0,s3=0,s4=0;
  for(int i=1; i<=14; i++)
  {
    if(Card[i]==1) s1++; //统计单牌个数
    if(Card[i]==2) s2++; //统计对牌个数
  }
  for(int i=1; i<=14; i++)
    if(Card[i]==4)
    {
      s4++;
      if(s1>=2) s1-=2;     //四带二张
      else if(s2>=2) s2-=2;//四带两对
      else if(s2>=1) s2--; //四带一对
    }
  for(int i=1; i<=14; i++)
    if(Card[i]==3)
    {
      s3++;
      if(s1>=1) s1--;      //三带一张
      else if(s2>=1) s2--; //三带一对
    }
  ans=min(ans,step+s1+s2+s3+s4);
  int j;
  for(int i=1; i<=8; i++)      //有单顺子的情况
  {
    for(j=i; j<=12; j++)
    {
      Card[j]--;
      if(Card[j]<0) break;
      if(j-i>=4)
        DFS(step+1);
    }
    for(int k=i; k<=j && k!=13; k++) //恢复原样
      Card[k]++;
  }
  for(int i=1; i<=10; i++)    //有双顺子的情况
  {
    for(j=i; j<=12; j++)
    {
      Card[j]-=2;
      if(Card[j]<0) break;
      if(j-i>=2)
        DFS(step+1);
    }
    for(int k=i; k<=j && k!=13; k++) //恢复原样
      Card[k]+=2;
  }
  for(int i=1; i<=11; i++)   //有三顺子的情况
  {
    for(j=i; j<=12; j++)
    {
      Card[j]-=3;
      if(Card[j]<0) break;
      if(j-i>=1)
        DFS(step+1);
    }
    for(int k=i; k<=j && k!=13; k++) //恢复原样
      Card[k]+=3;
  }
}

int main()
{
  //freopen("landlords.in","r",stdin);
  //freopen("landlords.out","w",stdout);
  int t,n;
  cin>>t>>n;
  while(t--)
  {
    memset(Card,0,sizeof(Card));
    ans=n;
    for(int i=1; i<=n; i++)
    {
      int a,b;
      cin>>a>>b;
      if(a==0)  Card[14]++;  // 王
      if(a==1 || a==2) Card[a+11]++;  // A
      if(a>=3) Card[a-2]++;
    }
    DFS(0);
    cout<<ans<<endl;
  }
  return 0;
}
