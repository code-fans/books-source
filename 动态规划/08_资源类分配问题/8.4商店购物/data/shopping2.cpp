//�̵깺��
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

struct Node
{
  int c,k;
} S[MAXN];
int F[MAXN][MAXN][MAXN][MAXN][MAXN],P[105][1005];


int main()
{
  //freopen("shopping2.in","r",stdin);
  //freopen("shopping2.out","w",stdout);
  int s,b,n,c;
  cin>>s;
  for(int i=1; i<=s; i++)              //����s���Ż���Ʒ��Ϣ
  {
    cin>>n;
    for(int j=1; j<=n; j++)
    {
      cin>>c;
      cin>>P[i][c];                    //P[i][j]Ϊ��i���Żݷ�����j��Ʒ������
    }
    cin>>P[i][1001];                    //P[i][1001]Ϊ��i���Żݷ������Żݼ�
  }
  cin>>b;
  for(int i=1; i<=b; i++)               //����b�ֲ�ͬ��Ʒ
  {
    s++;
    cin>>S[i].c>>S[i].k>>P[s][1001];    //����������ļ۸�Ҳ����Ϊ�Żݷ�������
    P[s][S[i].c]=1;                    //������Żݷ����и���Ϊ1��
  }
  memset(F,127/2,sizeof(F));
  F[0][0][0][0][0]=0;
  for(int i=1; i<=s; i++)//���������Żݷ���
  {
    int A=P[i][S[1].c];//���ﵥ��һ����Ʒ�ı�ţ��ڵ�i���Żݷ����еĸ���
    int B=P[i][S[2].c];//���ﵥ�ڶ�����Ʒ�ı�ţ��ڵ�i���Żݷ����еĸ���
    int C=P[i][S[3].c];//���ﵥ��������Ʒ�ı�ţ��ڵ�i���Żݷ����еĸ���
    int D=P[i][S[4].c];//���ﵥ���ĸ���Ʒ�ı�ţ��ڵ�i���Żݷ����еĸ���
    int E=P[i][S[5].c];//���ﵥ�������Ʒ�ı�ţ��ڵ�i���Żݷ����еĸ���
    for(int a=A; a<=S[1].k; a++)//��A���˿�ʵ�ʹ����һ����Ʒ���������
      for(int b=B; b<=S[2].k; b++)//��B���˿�ʵ�ʹ���ڶ�����Ʒ���������
        for(int c=C; c<=S[3].k; c++)//��C���˿�ʵ�ʹ����������Ʒ���������
          for(int d=D; d<=S[4].k; d++)//��D���˿�ʵ�ʹ�����ĸ���Ʒ���������
            for(int e=E; e<=S[5].k; e++)//��E���˿�ʵ�ʹ����һ����Ʒ���������
              F[a][b][c][d][e]=
                min(F[a][b][c][d][e],F[a-A][b-B][c-C][d-D][e-E]+P[i][1001]);
  }
  cout<<F[S[1].k][S[2].k][S[3].k][S[4].k][S[5].k]<<endl;
  return 0;
}

