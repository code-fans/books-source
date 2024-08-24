#include <bits/stdc++.h>
using namespace std;

int cnt,permutation[10001],m,n,a[10001];
bool used[10001];

void Out()
{
  for(int i=1; i<=n; i++)
    cout<<permutation[i]<<(i==n?"\n":" ");
  exit (0);
}

int DFS(int pos)                 //posΪ��ǰλ��,��ǰ����ɨ��
{
  if(pos>n)
  {
    if(++cnt>m)                 //����ǵ�m�������������
      Out();
  }
  else
    for(int i=a[pos]; i<=n; i++) //�ӵ�ǰ����ʼö�ٵ�n
      if(!used[i])               //�����ǰ��û�ù�
      {
        a[pos]=1;
        permutation[pos]=i;      //���и�ֵ
        used[i]=true;            //��Ǹ�����ʹ��
        DFS(pos+1);
        used[i]=false;           //�ָ�����δʹ��
      }
}

int main()
{
  freopen("martian.in","r",stdin);
  freopen("martian.out","w",stdout);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  DFS(1);
  return 0;
}
