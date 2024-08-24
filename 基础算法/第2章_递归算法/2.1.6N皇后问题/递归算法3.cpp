//递归算法3
#include <bits/stdc++.h>
using namespace std;

int board[20+1];
bool x1[40+1];//斜线数为2*N+1用来判断正斜线"/"的
bool x2[40+1];//反斜线"\"上有棋，则作标记
bool Y[20+1];//解决列冲突
int total,n;

void Place(int x,int y)
{
  if(x==n+1)
    total++;
  else
    for(int i=1; i<=y; i++)
      if((!Y[i])&&(!x1[x+i])&&(!(x2[x-i+n])))//如果没有冲突
      {
        board[x]=i;
        Y[i]=1;//则该列标记为1
        x1[x+i]=1;//该正斜线标记为1
        x2[x-i+n]=1;//该反斜线标记为1
        if(n%2!=0 && x==1 && board[1]==(n+1)/2)
          Place(2,(n+1)/2-1);
        else
          Place(x+1,n);
        Y[i]=0;//还原
        x1[x+i]=0;//还原
        x2[x-i+n]=0;//还原
      }
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  cin>>n;
  Place(1,(n+1)/2);
  cout<<total*2<<endl;
  return 0;
}
