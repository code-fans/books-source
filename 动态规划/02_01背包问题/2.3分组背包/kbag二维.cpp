//���鱳���������㷨1
#include<bits/stdc++.h>
using namespace std;

int V,N,w[101][1001],f[101][1001],stone[111][1001],K=0;

int main()
{
  //freopen("kbag.in","r",stdin);
  //freopen("kbag.out","w",stdout);
  cin>>V>>N;
  for(int i=1,a,b,c; i<=N; i++)
  {
    cin>>a>>b>>c;
    stone[c][++stone[c][0]]=a;            //stone[i][0]���c����Ʒ����
    w[c][stone[c][0]]=b;                  //w[i][j]���i���j����Ʒ�ļ�ֵ
    K=max(K,c);                           //ͳ������ж�����
  }
  for(int k=1; k<=K; k++)                 //ö�ٷ���
    for(int i=0; i<=stone[k][0]; i++)     //ö�ٸ÷��������Ʒ
      for(int j=V; j>=stone[k][i]; j--)   //ö�ٱ�������
        f[k][j]=max(f[k-1][j],max(f[k-1][j-stone[k][i]]+w[k][i],f[k][j]));
  printf("%d\n",f[K][V]);
  return 0;
}
