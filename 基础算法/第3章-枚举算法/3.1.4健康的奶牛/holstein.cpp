//��������ţ
#include <bits/stdc++.h>
using namespace std;

int need[505],feed[505][505],save[50005][505];

int main()
{
  //freopen("holstein.in","r",stdin);
  //freopen("holstein.out","w",stdout);
  int V,G,ansN=0x7f7f7f7f,pos;    //ansNΪ�𰸣�������������
  cin>>V;
  for(int i=1; i<=V; i++)
    cin>>need[i];
  cin>>G;
  for(int i=1; i<=G; i++)
    for(int j=1; j<=V; j++)
      cin>>feed[i][j];
  for(int i=0; i<(1<<G); i++)         //������ö���Ӽ�
  {
    int Nfeed=0,temp[505]= {0},ok=1;  //Nfeedͳ�Ƶ�ǰ�õ���������
    for(int j=0; j<G; j++)            //ö�ٵ�j+1λ
      if(i&(1<<j))                    //�����λΪ1
      {
        save[i][++Nfeed]=j;           //˳���¼�õ�������
        for(int k=1; k<=V; k++)
          temp[k]+=feed[j+1][k];      //������ά������
      }
    if(ansN>Nfeed)                    //��¼��С��
    {
      for(int j=1; j<=V; j++)         //�ж�ά����������
        if(temp[j]<need[j])
        {
          ok=0;
          break;
        }
      if(ok)
      {
        ansN=Nfeed;                   //��¼��С�����ϸ���
        pos=i;                        //��¼��С�𰸵Ķ������Ӽ���λ��
      }
    }
  }
  cout<<ansN<<' ';
  for(int i=1; i<=ansN; i++)
    cout<<save[pos][i]+1<<(i==ansN?'\n':' ');
  return 0;
}
