//组合数高精度算法1-非高精度
#include <bits/stdc++.h>
using namespace std;

const int MAX = 90000000;
long long C[MAX][2];

void Combin(int M,int N)
{
  int M1=0, M2=1;
  C[0][M1] = 1;                     //表示C(1,0)=1
  C[1][M1] = 1;                     //表示C(1,1)=1

  for(int i = 2; i <= M; ++i)       //由于M<=1000000，运算极为耗时
  {
    C[0][M2] = C[i][M2] = 1;        //表示C(i,0)=1,表示C(i,i)=1
    for(int j = 1; j < i; ++j)
    {
      C[j][M2] = C[j-1][M1] + C[j][M1];
      if (j>=N)                      //优化剪枝
        break;
    }
    swap(M1,M2);                     //滚动数组交换值
  }
  printf("%lld\n",C[N][M1]);
}

int main()
{
  //freopen("combin.in","r",stdin);
  //freopen("combin.out","w",stdout);
  int m, n;
  scanf("%d%d",&m,&n);
  m=m+n-2;
  Combin(m,--n);
  return 0;
}

