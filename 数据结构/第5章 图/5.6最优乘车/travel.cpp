//最优乘车
//样例中：1->3 换乘 3->6 换乘 6->7
#include<bits/stdc++.h>
using namespace std;
int m,n,D[510][510],f[510][510];

void Init()
{
  cin>>m>>n;
  for(int i=1; i<=m; i++)                        //扫描m条线路
    for(int stand,num=0; cin>>stand;)
    {
      f[i][++num]=stand;
      for(int j=1; j<num; j++)                   //之前加入的站和这一站连成权值为1的边
        D[f[i][j]][stand]=1;
      char t=getchar();
      if(t=='\r' || t=='\n')                     //回车符在windows下是"\r",linux下是"\n" 
        break;
    }
}

int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  memset(D,127/2,sizeof(D));
  Init();
  for(int i=1; i<=n; i++)
    D[i][i]=0;
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
  D[1][n]>1e9?cout<<"NO\n":cout<<D[1][n]-1<<endl;//最少换乘次数=最少乘车次数-1
  return 0;
}
