//��������ţ ��DFS
#include <bits/stdc++.h>
using namespace std;

int V,G,need[30],feed[20][30],ansN=1e9,tmp[20],sum[30],ans[30];

bool OK()                           //�ж��Ƿ�����
{
  for(int i=1; i<=V; i++)
    if(sum[i]<need[i])
      return false;
  return true;
}

void DFS(int cur)                   //ѡ����cur������
{
  for(int i=tmp[cur-1]+1; i<=G; i++)//ö�����б�ű�ǰһ�ִ������
  {
    tmp[cur]=i;                     //ȡ������
    for(int j=1; j<=V; j++)         //����ͳ���ۼ�ά����
      sum[j]+=feed[i][j];
    if(OK() && cur<ansN)            //������������Ž�
    {
      ansN=cur;
      for(int j=1; j<=ansN; j++)
        ans[j]=tmp[j];
    }
    else if(cur+1<ansN)             //��֦
      DFS(cur+1);                   //�ݹ���һ��
    for(int j=1; j<=V; j++)         //��Ҫ������
      sum[j]-=feed[i][j];
  }
}

int main()
{
  freopen("holstein.in","r",stdin);
  freopen("holstein.out","w",stdout);
  cin>>V;
  for(int i=1; i<=V; i++)
    cin>>need[i];
  cin>>G;
  for(int i=1; i<=G; i++)
    for(int j=1; j<=V; j++)
      cin>>feed[i][j];
  DFS(1);
  cout<<ansN<<' ';
  for(int i=1; i<=ansN; i++)
    cout<<ans[i]<<(i==ansN?'\n':' ');
  return 0;
}
