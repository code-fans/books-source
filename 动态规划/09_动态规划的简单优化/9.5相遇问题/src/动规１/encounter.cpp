//�������� - ����1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int Dir[301][301];                          //�洢�õ��м�����չ����
  float p[301][301]= {0},q[301][301]= {0};    //��Ϊ��������.�洢����
  int n;
  scanf("%d",&n);
  int k=(n+1)>>1;                      //�����������ʼλ��
  q[k][k]=1;                           //������ʼλ�ø���Ϊ1,ʱ��Ϊ0
  for(int i=0; i<=n+1; i++)            //����Dir[x,y] �˴�������һȦ�Է�Խ��
    for(int j=0; j<=n+1; j++)
      if((i==1 && j==1)||(i==1 && j==n)||(i==n && j==1)||(i==n && j==n))
        Dir[i][j]=2;                   //���ó���λ���ĸ���ʱ,�����Ϊ1/2
      else if(i==1||j==1||i==n||j==n)
        Dir[i][j]=3;                   //���ó���λ��������ʱ,�����Ϊ1/3
      else Dir[i][j]=4;                //���������Ϊ1/4
  float ans=0;
  for(int t=1; t<=n; t++)              //����ʱ��t,���Կɱ���ά����Ϊ��ά����
  {
    memset(p,0,sizeof(p));             //ˢ������p
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
      {
        p[i][j]+=q[i][j-1]/Dir[i][j-1];//qΪ��һʱ��ĸ���
        p[i][j]+=q[i][j+1]/Dir[i][j+1];
        p[i][j]+=q[i+1][j]/Dir[i+1][j];
        p[i][j]+=q[i-1][j]/Dir[i-1][j];
      }
    ans+=p[k][t];
    p[k][t]=0;                          //���������Ա����ظ�
    memcpy(q, p, sizeof(p));            //��������ĸ���
  }
  ans<=0.00001 ? printf("0\n") : printf("%.4f\n",ans);
  return 0;
}

