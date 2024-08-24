//��ת����2
#include<bits/stdc++.h>
using namespace std;

int Map[20][20];
int n,ans =(1<<31)-1;

void Flip(int x,int y)
{
  Map[x-1][y] ^= 1;
  Map[x][y-1] ^= 1;
  Map[x][y] ^= 1;
  Map[x][y+1] ^= 1;
  Map[x+1][y] ^= 1;
}

void Dfs(int row,int step,int value)
{
  if(row == n+1)
  {
    for(int i = 1; i <= n; i++)
      if(Map[n][i]==value)          //�������ϣ��˳�
        return;
    ans=min(step,ans);          //��������´�
    return;
  }
  int v = 0;
  for(int i = 1; i <= n; i++)
    if(Map[row-1][i]==value)        //��һ���ĳ���Ӳ���Ŀ��״̬����ת
    {
      step++;
      Flip(row,i);                  //��ת��ǰ���Ըı���һ�������
      v |= 1<<(i-1);                //��¼��ת��λ��
    }
  Dfs(row+1,step,value);
  for(int i = 1; i <= n; i++)       //��ԭ
    if((v>>(i-1))&1)
      Flip(row,i);
}

int main()
{
  freopen("flip.in","r",stdin);
  freopen("flip.out","w",stdout);
  cin >> n;
  char ch;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
      cin >> ch;
      Map[i][j] =(ch=='b');
    }
  for(int k = 0; k <(1<<n); k++)
  {
    for(int i = 1; i <= n; i++)     //ö�ٳ���0��(�����ڵ���)������״̬
      Map[0][i]=(k>>(i-1))&1;
    Dfs(1,0,0);                     //�ӵ�1�п�ʼ�������ܲ����ҵ�ȫΪ1��״̬
    Dfs(1,0,1);                     //�ӵ�1�п�ʼ�������ܲ����ҵ�ȫΪ0��״̬
  }
  if(ans!=(1<<31)-1)
    cout<<ans<<endl;
  else
    cout<<"Impossible"<<endl;
  return 0;
}
