//��������1
#include<bits/stdc++.h>
using namespace std;

long long F[11][155][155];      //F[i][a][k]:��i����a״̬�·�kֻ���޵ķ�����
int num[155],s[155],N,K,states; //states��ʾһ����,���ܷ��õĺϷ�״̬��

void Init()
{
  for(int i=0; i<(1<<N); ++i)   //ö��000��000~111��111�����п���״̬
  {
    if(i&(i<<1))                //�����ڻ��๥�����״̬����
      continue;
    s[++states]=i;              //��������Ϸ���״̬
    for(int t=i; t; t>>=1)
      num[states]+=(t&1);       //ͳ�ƸúϷ�״̬�·��õ�������
  }
}

void DP()
{
  F[0][1][0]=1;                 //ע������states�±��Ǵ�1��ʼ��
  for(int i=1; i<=N; ++i)       //ö����
    for(int a=1; a<=states; ++a)//ö����һ��״̬
      for(int k=num[a]; k<=K; ++k)//ö�ٷ��õ�������
        for(int b=1; b<=states; ++b) //ö�ٸ��е�״̬
          if(!(s[a]&s[b]) && !(s[a]&(s[b]<<1))&& !(s[b]&(s[a]<<1)))
            F[i][a][k]+=F[i-1][b][k-num[a]];//�޳�ͻ���ۼӷ�����
  long long ans=0;
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
  return 0;
}

