//������-һά�Ż��㷨
//f[i][j]=f[i-1][j]+f[i][j-1]����д�ɹ�������f[i]=f[i]+f[i-1]
//����f[i-1]����ǰ�淽�����f[i][j-1]
//f[i]��Ϊ��û�б����¹�,��������f[i-1][j]
#include <bits/stdc++.h>
using namespace std;
const int dx[9]= {0,-2,-1,1,2,2,1,-1,-2};
const int dy[9]= {0,1,2,2,1,-1,-2,-2,-1};
long long F[21]= {1};                         //����һά����Ϳ�����
bool Map[21][21];

int main()
{
  //freopen("river.in","r",stdin);
  //freopen("river.out","w",stdout);
  int n,m,x,y;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for(int i=0; i<9; ++i)
    if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
      Map[x+dx[i]][y+dy[i]]=1;                //�������̤����λ��Ϊ1
  for(int i=0,j; i<=n; ++i)                   //������������
    for(F[0]*=!Map[i][0],j=1; j<=m; ++j)      //ÿ�д������ҵ���
      (F[j]+=F[j-1])*=!Map[i][j];
  printf("%lld\n",F[m]);
  return 0;
}
