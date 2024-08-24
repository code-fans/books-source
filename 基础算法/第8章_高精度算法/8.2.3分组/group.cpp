//����
//�����Ƴ���Ϊ2^(n-1)
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

int a[MAXN+1],N,ans[MAXN+1];

void Output(int *ans,int i=1)
{
  for(; ans[i]==0; i++);                     //ʡ��ǰ�����е�0
  for(int j=i; j<=MAXN; ++j)
    printf("%d",ans[j]);
  printf("\n");
}

int Mul(int u[],int v[],int ansn[])        //u*v=ansn
{
  int x[MAXN+1],y[MAXN+1];                 //���ڸ���x[]��y[],����x[],y[]ֱ���޸�
  memcpy(x,u,sizeof(int)*(MAXN+1));        //u���鸴�Ƶ�x����
  memcpy(y,v,sizeof(int)*(MAXN+1));        //v���鸴�Ƶ�y����
  memset(ansn,0,sizeof(int)*(MAXN+1));
  for(int i=MAXN; i>=1; --i)               //u
    for(int j=MAXN; j>=1; --j)             //v
      if(i+j-MAXN>0 && x[j]!=0 && y[i]!=0 )
        ansn[i+j-MAXN]+=y[i]*x[j];         //�˷�����
  for(int k=MAXN; k>=1; k--)               //����
    if(ansn[k]>=10)
    {
      ansn[k-1]+=ansn[k]/10;
      ansn[k]%=10;
    }
}

int main()
{
  //freopen("group.in","r",stdin);
  //freopen("group.out","w",stdout);
  ans[MAXN]=1;
  a[MAXN]=2;
  cin>>N;
  for(N--; N>1; N>>=1)
  {
    if(N&1)
      Mul(ans,a,ans);
    Mul(a,a,a);
  }
  Mul(ans,a,ans);
  Output(ans);
  return 0;
}

