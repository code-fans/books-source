#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<11)+10;
int n,m;
LL temp[MAX],dp[MAX],bin[15];
bool mark[MAX];

bool Check(int i)
{
  while(i)
    if(i&1)
    {
      i>>=1;
      if(!(i&1))
        return false;//��j����1���j+1�б�����1
      i>>=1;//�����ж���һ��
    }
    else i>>=1; //�����ж���һ��
  return true;
}

void Init()
{
  memset(mark,false,sizeof mark);
  memset(temp,0,sizeof temp);
  for(int i=0; i<bin[m]; ++i) //��ʼ����һ�кͿ��Ե���ʲô״̬
    if(Check(i))
      temp[i]=1,mark[i]=true;
}

void DP()
{
  for(int k=2; k<=n; ++k)
  {
    for(int i=0; i<bin[m]; ++i)
      dp[i]=0;
    for(int i=0; i<bin[m]; ++i)
      for(int j=0; j<bin[m]; ++j)
      {
        if((i|j) != bin[m]-1)continue;//ÿһλ��֮�����ÿһλ��1(�ۺ�ǰ��3������ͷ�����֪)
        if(!mark[i&j])continue;//�ɳ�ʼ����ǰ������������������֪i&j����õ��ͳ�ʼ�����Ե����״̬һ������
        dp[i]+=temp[j];//i���Դ�j����,������j�ķ�����
      }
    for(int i=0; i<bin[m]; ++i)
      temp[i]=dp[i];
  }
}

int main()
{
  freopen("Imprisonment.in","r",stdin);
  freopen("Imprisonment.out","w",stdout);
  for(int i=0; i<12; ++i)
    bin[i]=int(pow(2,i));//1,2,4,8...
  while(~scanf("%d%d",&n,&m),n+m)
  {
    if(n<m)
      swap(n,m);//ʼ�ձ���m<n,���Ч��
    Init();
    DP();
    printf("%lld\n",temp[bin[m]-1]);//������һ�е���ʱ��״̬����ȫ����1
  }
  return 0;
}
