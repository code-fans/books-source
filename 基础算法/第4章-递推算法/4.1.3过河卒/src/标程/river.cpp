//������
#include <bits/stdc++.h>
using namespace std;

long long F[100][100];
bool Map[100][100];
int dx[9]= {0,1,2,2,1,-1,-2,-2,-1};
int dy[9]= {0,2,1,-1,-2,-2,-1,1,2};

int main()
{
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  for(int i=0; i<9; i++)               //�����Ŀ��Ƶ�
    if(x+dx[i]>=0 && x+dx[i]<=n && y+dy[i]>=0 && y+dy[i]<=m)
      Map[x+dx[i]][y+dy[i]]=true;
  for(int k=0; !Map[k][0] && k<=n; k++)//��ʼ����һ��Ϊ1
    F[k][0]=1;
  for(int k=0; !Map[0][k] && k<=m; k++)//��ʼ����һ��Ϊ1 
    F[0][k]=1;
  for(int i=1; i<=n; i++)              //���ϵ��� 
    for(int j=1; j<=m; j++)            //������ 
      if(!Map[i][j])
        F[i][j]=F[i][j-1]+F[i-1][j];
  cout<<F[n][m]<<endl;
  return 0;
}
