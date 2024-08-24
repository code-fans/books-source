//食物链
#include <bits/stdc++.h>
using namespace std;

int father[50005],Rank[50005];

int FindFather(int x)
{
  if(x!=father[x])
  {
    int t = father[x];
    father[x]= FindFather(father[x]);   //压缩路径
    Rank[x] = (Rank[x]+Rank[t])%3;      //更新x与father[X]的关系
  }
  return father[x];
}

void Union(int x,int y,int d)           //合并x,y所在的集合
{
  int xf = FindFather(x);
  int yf = FindFather(y);
  father[xf] = yf;                      //将集合xf合并到yf集合上
  Rank[xf]=(Rank[y]-Rank[x]+3+d)%3;     //更新 xf 与father[xf]的关系
}

int main()
{
  freopen("food12.in","r",stdin);
  freopen("food12.ans","w",stdout);
  int total=0,n,k;
  cin>>n>>k;
  for(int i=1; i<=n; ++i)
    father[i]=i;
  while(k--)
  {
    int d,x,y;
    cin>>d>>x>>y;
    if(x>n||y>n||(d==2 && x == y))      //如果x或y比n大，或x吃x，是假话
      total++;                          //假话数加一
    else if(FindFather(x)== FindFather(y)) //如果x，y的父结点相同
    {
      if((Rank[x]-Rank[y]+3)%3 != d-1)//则可判断给的关系是否正确的
        total++;
    }
    else
      Union(x,y,d-1);                 //否则合并x，y
  }
  cout<<total<<endl;
  return 0;
}

