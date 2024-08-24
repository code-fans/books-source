//商店购物
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

struct Node
{
  int c,k;
} S[MAXN];
int F[MAXN][MAXN][MAXN][MAXN][MAXN],P[105][1005];


int main()
{
  //freopen("shopping2.in","r",stdin);
  //freopen("shopping2.out","w",stdout);
  int s,b,n,c;
  cin>>s;
  for(int i=1; i<=s; i++)              //读入s种优惠商品信息
  {
    cin>>n;
    for(int j=1; j<=n; j++)
    {
      cin>>c;
      cin>>P[i][c];                    //P[i][j]为第i种优惠方案中j商品的数量
    }
    cin>>P[i][1001];                    //P[i][1001]为第i种优惠方案的优惠价
  }
  cin>>b;
  for(int i=1; i<=b; i++)               //购买b种不同商品
  {
    s++;
    cin>>S[i].c>>S[i].k>>P[s][1001];    //将正常购物的价格也假设为优惠方案存入
    P[s][S[i].c]=1;                    //假设的优惠方案中该物为1个
  }
  memset(F,127/2,sizeof(F));
  F[0][0][0][0][0]=0;
  for(int i=1; i<=s; i++)//遍历所有优惠方案
  {
    int A=P[i][S[1].c];//购物单第一个物品的编号，在第i种优惠方案中的个数
    int B=P[i][S[2].c];//购物单第二个物品的编号，在第i种优惠方案中的个数
    int C=P[i][S[3].c];//购物单第三个物品的编号，在第i种优惠方案中的个数
    int D=P[i][S[4].c];//购物单第四个物品的编号，在第i种优惠方案中的个数
    int E=P[i][S[5].c];//购物单第五个物品的编号，在第i种优惠方案中的个数
    for(int a=A; a<=S[1].k; a++)//从A至顾客实际购买第一个物品的最多数量
      for(int b=B; b<=S[2].k; b++)//从B至顾客实际购买第二个物品的最多数量
        for(int c=C; c<=S[3].k; c++)//从C至顾客实际购买第三个物品的最多数量
          for(int d=D; d<=S[4].k; d++)//从D至顾客实际购买第四个物品的最多数量
            for(int e=E; e<=S[5].k; e++)//从E至顾客实际购买第一个物品的最多数量
              F[a][b][c][d][e]=
                min(F[a][b][c][d][e],F[a-A][b-B][c-C][d-D][e-E]+P[i][1001]);
  }
  cout<<F[S[1].k][S[2].k][S[3].k][S[4].k][S[5].k]<<endl;
  return 0;
}

