//�۹⹫��
#include<bits/stdc++.h>
using namespace std;
#define N 30001

int n,m,k;
int Time[N],last[N],sum[N],effect[N],fast[N];
int ans;

struct node
{
  int time,sta,end;       //����ʱ�䣬��㡢�յ���
} man[N];

int Calc(int k)
{
  effect[n]=effect[n-1]=n;//effect[i]Ϊiվ������Ӱ�쵽����Զվ��
  while(k--)              //ֱ������������
  {
    for(int i=n-2; i>=1; --i)//����
      fast[i+1]<=last[i+1]?effect[i]=i+1:effect[i]=effect[i+1];//����һվ�Ȼ򲻵�
    int obj,MAX=-1;
    for(int i=1; i<n; ++i)
    {
      int total=sum[effect[i]]-sum[i];//�ҵ����Ӱ�������
      if(total>MAX && Time[i]>0)//ʱ�䲻�ܼ�Ϊ0
      {
        MAX=total;
        obj=i;//�������������ĵ�
      }
    }
    ans-=MAX;//����ans
    Time[obj]--;//ʹ�ü�����������ʱ���һ
    for(int i=2; i<=n; ++i)//����fast[]
      fast[i]=max(fast[i-1],last[i-1])+Time[i-1];
  }
  return ans;
}

int main()
{
//  //freopen("bus.in","r",stdin);
//  //freopen("bus.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k); //���������˿����͵�������������
  for(int i=1; i<n; ++i)
    scanf("%d",&Time[i]);   //�ӵ�i�����㿪����i��1����������Ҫ��ʱ��
  for(int i=1; i<=m; ++i)
  {
    scanf("%d%d%d",&man[i].time,&man[i].sta,&man[i].end);//��iλ�˿��������������ʱ�̣������ľ����ź͵���ľ�����
    last[man[i].sta]=max(last[man[i].sta],man[i].time);//�������a[i].start��ʱ��
    sum[man[i].end]++;//ͳ�Ƶ�man[i].endվ��������
  }
  fast[1]=last[1];
  for(int i=2; i<=n; ++i)
  {
    sum[i]+=sum[i-1];//��iվ�����������ǰ׺�ʹ���
    fast[i]=max(fast[i-1],last[i-1])+Time[i-1];//ͳ��i��վ��췢��ʱ��
  }
  for(int i=1; i<=m; ++i)//������޼������Ľ�
    ans+=fast[man[i].end]-man[i].time;
  printf("%d\n",Calc(k));
  return 0;
}

