//Dijkstra���Ż�
#include <bits/stdc++.h>
using namespace std;
#define Max 0xfffffff

int n,ms;
int Map[1501][1501];                 //�洢ͼ
int visit[1501];                     //���÷��ʱ��
int heap[1501];                      //��
int pos[1501];                       //pos[i]�洢���е�i����ͼ�е�λ��
int posh[1501];                      //posh[i]�洢ͼ�еĵ�i�ڶ��е�λ��

void Minheap(int x)                    //ά����С��
{
  int t=x;
  int l=t<<1;                          //���ӽ��
  int r=(t<<1)+1;                      //���ӽ��
  if(l<=ms && heap[l]<heap[t])
    t=l;
  if(r<=ms && heap[r]<heap[t])
    t=r;
  if(t!=x)
  {
    swap(heap[x],heap[t]);
    swap(posh[pos[x]],posh[pos[t]]);
    swap(pos[x],pos[t]);
    Minheap(t);                        //�ݹ�������µ�����
  }
}

void Insert(int x)                     //�ı����ĳ��Ԫ�ص�ֵ
{
  while(x>1 && heap[x]<heap[x>>1])
  {
    swap(heap[x],heap[x>>1]);
    swap(posh[pos[x]],posh[pos[x>>1]]);
    swap(pos[x],pos[x>>1]);
    x>>=1;
  }
}

void Dijkstra(int x)                   //���x�㵽�����ĵ�Դ���·��
{
  int Min,p,q;
  for(int i=1; i<=n; i++)              //��ʼ������Ԫ��
    heap[i]=Map[1][i];
  heap[x]=0;
  for(int i=1; i<=n; i++)              //��ʼ��
    pos[i]=posh[i]=i;
  for(int i=n>>1; i>=1; i--)           //����С��
    Minheap(i);
  for(int i=1; i<n; i++)
  {
    p=pos[1];                          //����С��Ԫ�������������Ǹõ�
    q=heap[1];                         //qΪ��ǰ��̽��
    visit[p]=1;
    swap(heap[1],heap[ms]);
    swap(posh[pos[1]],posh[pos[ms]]);
    swap(pos[1],pos[ms]);        //������Ԫ�غ���С��Ԫ�ؽ�������������ά����
    ms--;                        //ÿȷ��һ���㣬�Ѷ�����С1
    Minheap(1);                  //ά����С��
    for(int j=1; j<=n; j++)      //����δ���Ҷ������С�����ܺ�
      if(!visit[j] && q+Map[p][j]<heap[posh[j]])
      {
        heap[posh[j]]=q+Map[p][j];
        Insert(posh[j]);         //�޸�j���ڶ����λ��
      }
  }
  for(int i=1; i<=n; i++)        //��ӡ���·��
    cout<<heap[posh[i]]<<'\n';
}

void Init()
{
  cin>>n;                        //n�����
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
      cin>>Map[i][j];
      if(Map[i][j]==-1)           //��������·��,��Ϊ+��
        Map[i][j]=Max;
    }
  ms=n;                          //��Ԫ��Ϊn
}

int main()
{
  //freopen("map.in","r",stdin);
  //freopen("map.out","w",stdout);
  Init();                        //����ͼ
  Dijkstra(1);
  return 0;
}

