//���ų˳�
//�����У�1->3 ���� 3->6 ���� 6->7
#include<bits/stdc++.h>
using namespace std;
int m,n,D[510][510],f[510][510];

void Init()
{
  cin>>m>>n;
  for(int i=1; i<=m; i++)                        //ɨ��m����·
    for(int stand,num=0; cin>>stand;)
    {
      f[i][++num]=stand;
      for(int j=1; j<num; j++)                   //֮ǰ�����վ����һվ����ȨֵΪ1�ı�
        D[f[i][j]][stand]=1;
      char t=getchar();
      if(t=='\r' || t=='\n')                     //�س�����windows����"\r",linux����"\n" 
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
  D[1][n]>1e9?cout<<"NO\n":cout<<D[1][n]-1<<endl;//���ٻ��˴���=���ٳ˳�����-1
  return 0;
}
