//�������� - ����ʵ�֣�Ҳ��������ģ���ջʵ�֣�
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001;

bool w[MAXN][MAXN];        //w[]������Ƿ����
int ind[MAXN],n,m,a,b;     //ind[]���������
queue<int>q;               //���б������������·��

void TopoSort()
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)//�ҵ������С�ġ����Ϊ0�Ľ��
      if(ind[j]==0)
      {
        q.push(j);         //�ý�����
        ind[j]=-1;
        for(int k=1; k<=n; ++k)
          if(w[j][k])      //����͸ý����صĽ��
          {
            ind[k]--;      //��ؽ�����ȼ� 1
            w[j][k]=0;     //ɾ��
          }
        break;
      }
}

int main()
{
  freopen("ranking.in","r",stdin);
  freopen("ranking.out","w",stdout);
  cin>>n>>m;             //���������ͱ���
  for(int i=0; i<m; i++)
  {
    cin>>a>>b;
    if(w[a][b]==0)       //�����ظ�����������
    {
      w[a][b]=true;      //�������
      ind[b]++;          //��ȼ�һ
    }
  }
  TopoSort();            //��������
  while(!q.empty())      //���������
  {
    printf("%d%c",q.front(),q.size()==1?'\n':' ');
    q.pop();
  }
  return 0;
}

