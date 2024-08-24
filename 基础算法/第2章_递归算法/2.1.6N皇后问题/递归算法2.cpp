#include <bits/stdc++.h>
using namespace std;

int n,num;
int board[20];
bool Y[31],x1[31],x2[31];

void Place(int x)//递归函数
{
  if(x>n)
    num++;
  else
    for(int y=1; y<=n; y++)
      if(Y[y]==0 && x1[x+y]==0 && x2[x-y+n]==0)//如果可以摆放
      {
        board[x]=y;
        Y[y]=1;
        x1[x+y]=1;
        x2[x-y+n]=1;
        Place(x+1);
        Y[y]=0;
        x1[x+y]=0;
        x2[x-y+n]=0;
      }
}

int main()
{
  //freopen("queen.in","r",stdin);
  //freopen("queen.out","w",stdout);
  cin>>n;
  Place(1);
  cout<<num<<endl;
  return 0;
}

