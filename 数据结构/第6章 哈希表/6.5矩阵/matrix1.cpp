#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned int ull;
ull val[1000010],p1[1003],p2[1003],hash_[1001][1001],hash_2[101][101];
ull has,H;
int p=0;
int n,m,a,b;
const ull Pi=131,Pj=233;
inline void reset_p()
{
  p1[0]=1;
  p2[0]=1;
  for(int i=1; i<=1000; i++)
  {
    p1[i]=p1[i-1]*233;
    p2[i]=p2[i-1]*131;
  }
}
inline void _hash()
{
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      hash_[i][j]=hash_[i-1][j]*Pi+hash_[i][j];
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      hash_[i][j]=hash_[i][j-1]*Pj+hash_[i][j];
}
inline ull _hash2()
{
  for (int i=1; i<=a; i++)
    for (int j=1; j<=b; j++)
      hash_2[i][j]=hash_2[i-1][j]*Pi+hash_2[i][j];
  for (int i=1; i<=a; i++)
    for (int j=1; j<=b; j++)
      hash_2[i][j]=hash_2[i][j-1]*Pj+hash_2[i][j];
  return hash_2[a][b];
}
int main()
{
  //freopen("matrix.in","r",stdin);
  //freopen("matrix.out","w",stdout);
  reset_p();

  scanf("%d%d%d%d",&n,&m,&a,&b);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      scanf("%1u",&hash_[i][j]);
  _hash();
  for(int i=a; i<=n; i++)
    for(int j=b; j<=m; j++)
    {
      has=hash_[i][j];
      has-=hash_[i-a][j]*p2[a];
      has-=hash_[i][j-b]*p1[b];
      has+=hash_[i-a][j-b]*p2[a]*p1[b];
      val[++p]=has;
    }
  int q,flag=0;
  char useless;
  scanf("%d",&q);
  for(int v=1; v<=q; v++)
  {
    for(int i=1; i<=a; i++)
      for(int j=1; j<=b; j++)
        scanf("%1u",&hash_2[i][j]);
    H=_hash2();

    for(int j=1; j<=p-1; j++)
    {
      if(val[j]==H)
      {
        if(v!=q)printf("1\n");
        else printf("1");
        flag=1;
        break;
      }
    }
    if(!flag)
      if(v!=q)printf("0\n");
      else printf("0");
    flag=0;
  }
  return 0;
}
