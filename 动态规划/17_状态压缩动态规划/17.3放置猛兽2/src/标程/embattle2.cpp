//��������2
#include <bits/stdc++.h>
using namespace std;
#define MOD 100000000

int M,N,row[13];
int put[13][1000];
int F[13][1000],Ans=0;

void Init()
{
  cin>>M>>N;
  for(int x,i=1; i<=M; i++)
    for(int j=1; j<=N; j++)                   //ѹ��ÿ���ܷ���õ�״̬
    {
      cin>>x;
      row[i]=(row[i]<<1)+1-x;
    }
  for(int i=1; i<=M; i++)                     //���ÿһ�����п���״̬
    for(int j=0; j<(1<<N); j++)
    {
      if((j<<1)&j || (j>>1)&j || j&row[i])   //��ͻ�����
        continue;
      put[i][0]++;                            //����i���ܷ��õ�״̬��
      put[i][put[i][0]]=j;                    //�����״̬
    }
}

void Dp()
{
  F[0][1]=1;
  put[0][0]=1;                                //��ʼֵ,�����ж�������
  for(int i=1; i<=M; i++)                     //ö����
    for(int b=1; b<=put[i-1][0]; b++)         //ö����һ�е�״̬
      for(int a=1; a<=put[i][0]; a++)         //ö�ٴ���״̬
      {
        if(put[i-1][b] & put[i][a])
          continue;                           //������ͻ
        F[i][a]+=F[i-1][b];
        F[i][a]%=MOD;                         //��ֹ���
      }
  for(int i=1; i<=put[M][0]; i++)             //ͳ�����һ��
    Ans+=F[M][i],Ans%=MOD;
  cout<<Ans<<endl;
}

int main()
{
  freopen("embattle2.in","r",stdin);
  freopen("embattle2.out","w",stdout);
  Init();
  Dp();
  return 0;
}

