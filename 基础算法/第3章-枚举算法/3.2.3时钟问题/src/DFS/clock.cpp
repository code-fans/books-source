//ʱ������ �� DFS
#include <bits/stdc++.h>
using namespace std;

int Clock[9],P[9];                      //P[i]=j��ʾ��i�ַ�������j��
int M[9][9]=                            //��ʾÿ�ַ����������ļ�����
{
  {1,1,0,1,1,0,0,0,0},
  {1,1,1,0,0,0,0,0,0},
  {0,1,1,0,1,1,0,0,0},
  {1,0,0,1,0,0,1,0,0},
  {0,1,0,1,1,1,0,1,0},
  {0,0,1,0,0,1,0,0,1},
  {0,0,0,1,1,0,1,1,0},
  {0,0,0,0,0,0,1,1,1},
  {0,0,0,0,1,1,0,1,1}
};

bool OK(int P[])                        //����Ҫ����ǰP�����ֵ������
{
  int test[9];
  for(int i=0; i<9; i++)
    test[i]=Clock[i];                   //����
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      test[i]=(test[i]+M[j][i]*P[j])%4; //�����ǰ������ӵ�״̬
  for(int i=0; i<9; i++)
    if(test[i])
      return false;                     //ֻ��ȫΪ0����ȫ��12��ſ���
  return true;
}

void DFS(int dep)                         //DFS�������з��������
{
  if(dep>9)
    return;                             //�߽�����
  if(OK(P))                             //�������
  {
    for(int i=0; i<9; i++)              //���
      for(int j=0; j<P[i]; j++)
        cout<<i+1;
    cout<<endl;
    exit(0);
  }
  for(int i=0; i<4; i++)                //��ǰ����ת������0-3��֮��
  {
    P[dep]=i;
    DFS(dep+1);
  }
}

int main()
{
  //freopen("clock.in","r",stdin);
  //freopen("clock.out","w",stdout);
  for(int i=0; i<9; i++)
    cin>>Clock[i];
  DFS(0);
  return 0;
}
