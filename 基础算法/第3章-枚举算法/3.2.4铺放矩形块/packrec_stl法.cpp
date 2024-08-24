//铺放矩形块-STL法
#include<bits/stdc++.h>
using namespace std;

int xx[5],yy[5],ans=1000000,x[5],y[5];
bool Used[1005];

void UpdateAns(int x,int y)//更新和保存答案
{
  if(x*y<ans)
  {
    ans=x*y;
    memset(Used,0,sizeof(Used));
  }
  if(x*y==ans)
    Used[x]=Used[y]=1;
}

void Enum(int x[],int y[])//枚举所有状态
{
  int X,Y;
  X=x[1]+x[2]+x[3]+x[4];               //第一种排列方式
  Y=max(max(y[1],y[2]),max(y[3],y[4]));
  UpdateAns(X,Y);

  X=max(x[1]+x[2]+x[3],x[4]);          //第二种排列方式
  Y=max(y[1],max(y[2],y[3]))+y[4];
  UpdateAns(X,Y);

  X=max(x[1]+x[2],x[3])+x[4];          //第三种排列方式
  Y=max(max(y[1],y[2])+y[3],y[4]);
  UpdateAns(X,Y);

  X=x[1]+max(x[2],x[3])+x[4];          //第四、五种排列方式
  Y=max(y[1],max(y[2]+y[3],y[4]));
  UpdateAns(X,Y);

  Y=max(y[1]+y[3],y[2]+y[4]);          //第六种排列方式
  if(y[1]+y[3]<=y[4])
    X=max(x[2],max(x[1],x[3])+x[4]);
  else if(y[3]<=y[4] && y[1]+y[3]>=y[4])
    X=max(x[1]+x[2],max(x[1],x[3])+x[4]);
  else if(y[3]>=y[4] && y[3]<=y[2]+y[4])
    X=max(x[1]+x[2],max(x[2],x[4])+x[3]);
  else if(y[3]>=y[2]+y[4])
    X=max(x[1],max(x[2],x[4])+x[3]);
  else if(y[3]==y[4])
    X=max(x[1]+x[2],x[3]+x[4]);
  UpdateAns(X,Y);
}

void SwapXY(int x[],int y[],int step)//矩形块的长宽也可以互换
{
  if(step>4)                         //获得一种状态
    Enum(x,y);                       //枚举该状态的所有可能情况
  else
  {
    SwapXY(x,y,step+1);
    swap(x[step],y[step]);
    SwapXY(x,y,step+1);
  }
}

void GetState()
{
  int a[]= {0,1,2,3,4};
  do
  {
    for(int i=1; i<=4; i++)
      x[i]=xx[a[i]],y[i]=yy[a[i]];
    SwapXY(x,y,1);
  }
  while(next_permutation(a+1,a+5));
}

int main()
{
  //freopen("packrec.in","r",stdin);
  //freopen("packrec.out","w",stdout);
  for(int i=1; i<=4; i++)
    scanf("%d%d",&xx[i],&yy[i]);
  GetState();
  printf("%d\n",ans);
  for(int i=1; i<=sqrt(ans); i++)
    if(Used[i])
      printf("%d %d\n",i,ans/i);
  return 0;
}
