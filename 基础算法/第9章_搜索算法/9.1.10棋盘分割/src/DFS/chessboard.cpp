/*
z
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 0x3f3f3f3f
using namespace std;
int n;
int s[9][9][9][9],c[9][9];
int f[20][9][9][9][9];
int add(int x1,int y1,int x2,int y2 )
{
    int w=0;
    for(int i=x1;i<=x2;i++)
      for(int j=y1;j<=y2;j++)
          w+=c[i][j];
    return w;
}
int dfs(int k,int x1,int y1,int x2,int y2)
{
    if(f[k][x1][y1][x2][y2]!=-1)
       return f[k][x1][y1][x2][y2];
    f[k][x1][y1][x2][y2]=INF;
    if(x1<x2)//横切
    {
        for(int x=x1; x<x2; x++)
        {
            int t1=dfs(k-1,x+1,y1,x2,y2);  //取上面那么递归计算下面
            int t2=dfs(k-1,x1,y1,x,y2);    //去下面那么递归计算上面
            int t=min(t1+s[x1][y1][x][y2],t2+s[x+1][y1][x2][y2]);
            f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],t);
        }
    }
        if(y1<y2)
        {
            for(int y=y1;y<y2;y++)
            {
                int t1=dfs(k-1,x1,y+1,x2,y2) ;   //选左边那么递归计算右边
                int t2=dfs(k-1,x1,y1,x2,y);     //选右边那么递归计算左边
                int t=min(t1+s[x1][y1][x2][y],t2+s[x1][y+1][x2][y2]);
                f[k][x1][y1][x2][y2]=min(f[k][x1][y1][x2][y2],t);
            }
        }
    return f[k][x1][y1][x2][y2];
}
int main()
{
    int x1,y1,x2,y2,n;
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=8;i++)
      for(int j=1;j<=8;j++)
        scanf("%d",&c[i][j]);
    for(x1=1; x1<=8; x1++)
      for(x2=x1; x2<=8; x2++)
        for(y1=1; y1<=8; y1++)
          for(y2=y1; y2<=8; y2++)
          {
               int tmp=add(x1,y1,x2,y2);
               f[1][x1][y1][x2][y2]=s[x1][y1][x2][y2]=tmp*tmp;
          }
    dfs(n,1,1,8,8);
    double X,ans;
    X=1.*add(1,1,8,8);
    X=(X/n)*(X/n);
    //cout<<f[n][1][1][8][8]<<endl;
    ans=sqrt(1.0*f[n][1][1][8][8]/n-X);
    printf("%.3f\n",ans);
    return 0;
}