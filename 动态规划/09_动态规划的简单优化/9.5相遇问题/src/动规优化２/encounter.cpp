//�������� - �����Ż�2
#include <bits/stdc++.h>
using namespace std;

int Dir[501][1000];            //ֻ�����һ�룬��������ֻ�ÿ���һ��
double p[2][501][1000],ans;    //��������,����ֻ�ÿ���һ��

int main()
{
  //freopen("encounter.in","r",stdin);
  //freopen("encounter.out","w",stdout);
  int n,m;
  cin>>n;
  m=n>>1;
  if(m&1)                                           //��0�±꿪ʼ
  {
    for(int i=0; i<m+1; i++)
      for(int j=0; j<n; j++)
        Dir[i][j]=2+(i>0 && i<n-1)+(j>0 && j<n-1);
    p[0][m][m]=1;
    for(int t=0,w=0; t<n; t++,w=1-w)                //w���ƹ��������±�
    {
      memset(p[1-w],0,sizeof(p[1-w]));              //��գ���ֹ�����ۼ�
      for(int i=0; i<m+1; i++)
        for(int j=t; j<n; j++)
          if((abs(j-t-1)+abs(i-m-1))&1)             //��֦
          {
            if(i-1>=0)
              p[1-w][i-1][j]+=p[w][i][j]/Dir[i][j];
            if(j-1>=0)
              p[1-w][i][j-1]+=p[w][i][j]/Dir[i][j];
            if(i+1<m)
              p[1-w][i+1][j]+=p[w][i][j]/Dir[i][j];
            if(i+1==m)                              //���㵽�м�ʱ����Ҫ��2
              p[1-w][i+1][j]+=p[w][i][j]/Dir[i][j]*2;
            if(j+1<n)
              p[1-w][i][j+1]+=p[w][i][j]/Dir[i][j];
          }
      ans+=p[1-w][m][t];
    }
  }
  cout<<setprecision(ans==0?0:4)<<fixed<<ans<<endl;
  return 0;
}

