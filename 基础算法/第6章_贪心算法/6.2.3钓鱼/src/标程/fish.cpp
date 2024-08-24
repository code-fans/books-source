//����
#include <bits/stdc++.h>
using namespace std;

int n,h;
int fish[30],d[30],WalkTime[30];    //WalkTime[i]Ϊ�ߵ�i�������ѵ�ʱ��

struct LAKE
{
  int max;                           //������������
  int tim[30];
} lake[30];

int GetMax(int p[], int i, int j)    //��������p��������ı��
{
  int Max=p[i], loc=i;
  for(int m=i+1; m<=j; m++)
    if(Max<p[m])
    {
      Max=p[m];
      loc=m;
    }
  return loc;
}

void GetFish(int T)
{
  for(int i=1; i<=n; i++)            //�ṹ�������ʼ��
  {
    lake[i].max=0;
    memset(lake[i].tim,0,sizeof(lake[i].tim));
  }
  int f[30];                         //����fish�����ֵ,�Ա��޸�
  for(int i=1; i<=n; i++)            //ö������ߵ�i���������
  {
    int RealTime=T-WalkTime[i];      //��ȥ��·���ܵ��������ʱ��
    int FishTime=0;                  //ʵ�ʵ���ʱ���ʼΪ0
    for(int j=1; j<=i; j++)
      f[j]=fish[j];                  //��fish�����ֵ������f������
    while(FishTime<RealTime)         //��ʱ��û����ʱ
    {
      int k=GetMax(f,1,i);           //�ҵ�1~i�����е��������ı��
      lake[i].max+=f[k];             //���µ�������
      lake[i].tim[k]+=5;             //ͣ��k����ʱ������һ����λʱ��
      f[k]>=d[k]?f[k]-=d[k]:f[k]=0;  //���µ�k��������һʱ���ܵ�������
      FishTime+=5;                   //ʱ������һ����λʱ��
    }
  }
  for(int i=1; i<=n; i++)
    f[i]=lake[i].max;
  int loc=GetMax(f,1,n);             //�ҵ����Ž��±�
  for(int i=1; i<=n; i++)
    printf("%d%s",lake[loc].tim[i],i==n?"\n":", ");
  printf("Number of fish expected: %d\n\n", lake[loc].max);
}

int main()
{
  //freopen("fish.in","r",stdin);
  //freopen("fish.out","w",stdout);
  while(scanf("%d", &n) && n)
  {
    scanf("%d", &h);
    for(int i=1; i<=n; i++)
      scanf("%d", &fish[i]);
    for(int i=1; i<=n; i++)
      scanf("%d", &d[i]);
    for(int i=2,t; i<=n; i++)
    {
      scanf("%d", &t);
      WalkTime[i]=WalkTime[i-1]+5*t;  //Ԥ�����ߵ���i���������ѵ�ʱ��
    }
    GetFish(h*60);
  }
  return 0;
}

