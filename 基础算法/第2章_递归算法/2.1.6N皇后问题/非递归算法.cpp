//N�ʺ�����ķǵݹ��㷨
#include <bits/stdc++.h>
using namespace std;

int board[21];                       //��Żʺ�λ��,�����1��ʼ

int Try(int k)                       //�жϸ�λ���Ƿ�ɰ��ûʺ�
{
  for(int i=1; i<=k-1; i++)
    if((board[i]==board[k])||(abs(board[i]-board[k])==abs(i-k)))
      return 0;
  return 1;
}

int main()
{
  //freopen("queen.in","r",stdin);
  //freopen("queen.out","w",stdout);
  int n,Count=0;
  cin>>n;
  for(int k=1; k>0;)
  {
    board[k]++;                      //���ӷŵ�λ��������һλ
    while((board[k]<=n) && (!Try(k)))//ֱ���Ե�һ�����ʵ�λ��
      board[k]++;
    if(board[k]>n)                   //���Խ��
      k--;                           //���ݵ���һ��
    else if(k==n)                    //������ú����һ�лʺ�
      Count++;
    else
      board[++k]=0;                  //����������һ�лʺ�(��ʼΪ0��
  }
  cout<<Count<<endl;
  return 0;
}

