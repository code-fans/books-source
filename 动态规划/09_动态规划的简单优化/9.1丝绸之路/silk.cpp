//˿��֮· �� DP3
#include<bits/stdc++.h>
using namespace std;

int f[1002],d[1002];

int main()
{
  //freopen("silk.in","r",stdin);
  //freopen("silk.out","w",stdout);
  memset(f,127/2,sizeof(f));
  f[0]=0;					       //�����0�����е���С����Ϊ0
  int N,M;
  cin>>N>>M;
  for(int i=1; i<=N; i++)
    cin>>d[i];
  for(int i=1,c; i<=M; i++)        //��ö����������Ϊ��i������ж������ѡ��
  {
    cin>>c;
    for(int j=min(i,N); j>=1; j--) //�ڵ�i��������ߵ��ĳ���Ϊmin(i,N)
      f[j]=min(f[j],f[j-1]+d[j]*c);
  }
  cout<<f[N]<<endl;
  return 0;
}
