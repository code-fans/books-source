//�ݹ��㷨3
#include <bits/stdc++.h>
using namespace std;

int board[20+1];
bool x1[40+1];//б����Ϊ2*N+1�����ж���б��"/"��
bool x2[40+1];//��б��"\"�����壬�������
bool Y[20+1];//����г�ͻ
int total,n;

void Place(int x,int y)
{
  if(x==n+1)
    total++;
  else
    for(int i=1; i<=y; i++)
      if((!Y[i])&&(!x1[x+i])&&(!(x2[x-i+n])))//���û�г�ͻ
      {
        board[x]=i;
        Y[i]=1;//����б��Ϊ1
        x1[x+i]=1;//����б�߱��Ϊ1
        x2[x-i+n]=1;//�÷�б�߱��Ϊ1
        if(n%2!=0 && x==1 && board[1]==(n+1)/2)
          Place(2,(n+1)/2-1);
        else
          Place(x+1,n);
        Y[i]=0;//��ԭ
        x1[x+i]=0;//��ԭ
        x2[x-i+n]=0;//��ԭ
      }
}

int main()
{
  freopen("queen.in","r",stdin);
  freopen("queen.out","w",stdout);
  cin>>n;
  Place(1,(n+1)/2);
  cout<<total*2<<endl;
  return 0;
}
