/*
�������ƣ�USACO 1.3.2 Barn1
����˵������̬�滮
��d[i,j]��ʾ��i��ţ�޵���j��ţ��Ҫʹ�õ�ľ�峤��,
��f[i,j]��ʾ��ǰi��ľ���޵���jͷţ���õ���̳���.
 f[i,j]=min(f[i-1,k-1]+d[k,j])  (1<=k<=j)
��Ȼd[i,j]=cow[j]-cow[i]+1,f[1,i]=d[1,i]
*/
#include <bits/stdc++.h>
using namespace std;
const int INF= (1<<30);

int m,c,s,cow[201],d[201][201],f[51][201];

int main()
{
  freopen ("barn.in","r", stdin);
  freopen ("barn.out","w",stdout);
  cin>>m>>s>>c;
  for(int i=1; i<=c; i++)
    cin>>cow[i];
  sort(cow+1,cow+1+c);        //�������ź���
  memset(f,127,sizeof(f));    //��ʼΪ���ֵ
  for(int i=1; i<=c; i++)     //���㸲�ǵ�iͷţ����jͷţ�����ľ�峤��
    for(int j=1; j<=c; j++)
      d[i][j] = abs(cow[i]-cow[j])+1;
  for(int i=1; i<=c; i++)     //�߽�����
    f[1][i] = d[1][i];
  for(int i=1; i<=m; i++)     //û����߽������������������ȥ
    f[i][0] = 0;
  for(int i=1; i<=m; i++)     //��̬�滮,ö��ľ������
    for(int j=1; j<=c; j++)   //��ӵ���ö��ţ
      for(int k=1; k<=j; k++) //k��1~j��Χ�ڳ���
        f[i][j]=min(f[i][j],f[i-1][k-1]+d[k][j]);
  cout<<f[m][c]<<"\n";
  return 0;
}

