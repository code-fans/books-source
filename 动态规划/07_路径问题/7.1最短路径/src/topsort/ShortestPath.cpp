//���·��
#include <bits/stdc++.h>
using namespace std;
#define IMAX 0x7fffffff

vector <int> vec;                                //���ڴ�����������ֵ
int n,o=-1,t=-1,th=-1;
int a[101][101];

void TopSort(int a[101][101],int *indegree)      //��������
{
  queue <int> q;
  while(!q.empty() || vec.size()<n)
  {
    for(int i=1; i<=n; i++)
      if(indegree[i]==0)
      {
        q.push(i);                               //�����Ϊ0�ĵ����
        indegree[i]=-1;                          //���Ϊ�����ٷ���
      }
    int v=q.front();
    vec.push_back(v);                            //ȡ����Ԫ����������������
    q.pop();                                     //����Ԫ�س���
    for(int i=1; i<=n; i++)                      //ɾ������ָ��������ı�
      if(a[v][i]!=-1 && indegree[i]!=-1)
        indegree[i]--;
  }
}

int main()
{
  //freopen("ShortestPath.in","r",stdin);
  //freopen("ShortestPath.out","w",stdout);
  scanf("%d",&n);
  int f[n+1];
  int indegree[n+1];                              //����ÿ��������
  memset(f,127,sizeof(f));
  memset(indegree,0,sizeof(indegree));            //ÿ�������ȳ�ʼΪ0
  memset(a,-1,sizeof(a));
  while(o!=0 && t!=0 && th!=0)
  {
    cin>>o>>t>>th;
    a[o][t]=th;
    indegree[t]++;                                //����t��ȼ�1
  }
  TopSort(a,indegree);                            //��������
  f[n]=0;
  for(int i=n-2; i>=0; i--)
    for(int j=n-1; j>i; j--)
    {
      int I=vec[i],J=vec[j];
      if(a[I][J]>0 && f[J]!=0x7f7f7f7f)
        f[I]=min(f[I],f[J]+a[I][J]);
    }
  printf("%d\n",f[1]);
  return 0;
}

