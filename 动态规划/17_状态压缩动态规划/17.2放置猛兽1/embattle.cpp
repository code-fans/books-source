//���޾���1
#include<bits/stdc++.h>
using namespace std;

long long F[11][155][155];      //f[i][a][k]:��i����a״̬�·�kֻ���޵ķ�����
int num[155],s[155],N,K,states; //states��ʾһ����,���ܷ��õĺϷ�״̬��

void Init()
{
  for(int i=0; i<(1<<N); ++i)   //ö��000��000~111��111�����п���״̬
  {
    if(i&(i<<1))                //�����ڻ��๥�����״̬����
      continue;
    int k=0;
    for(int j=0; j<N; ++j)      //ͳ�ƸúϷ�״̬�·��õ�������
      if(i&(1<<j))
        ++k;
    s[++states]=i;              //����úϷ�״̬,�������㷨������ͬ,�±��1��ʼ
    num[states]=k;              //����úϷ�״̬�·��õ�������
  }
}

void DP()
{
  F[0][1][0]=1;                 //ע������states�±��Ǵ�1��ʼ��
  for(int i=1; i<=N; ++i)       //ö����
    for(int j=1; j<=states; ++j)//ö��״̬
      for(int kk=0; kk<=K; ++kk)//ö�ٷ��õ�������
        if(kk>=num[j])          //������������Ƶ�������
          for(int t=1; t<=states; ++t) //ö����һ�е�״̬
            if(!(s[t]&s[j]) && !(s[t]&(s[j]<<1))&& !(s[t]&(s[j]>>1)))//�޳�ͻ
              F[i][j][kk]+=F[i-1][t][kk-num[j]];
}

void Out(long long ans=0)
{
  for(int i=1; i<=states; ++i)
    ans+=F[N][i][K];
  cout<<ans<<endl;
}

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  cin>>N>>K;
  Init();
  DP();
  Out();
  return 0;
}

