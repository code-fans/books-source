//�߾�����
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;

int a[MAXN+1],N,key,ans[MAXN+1];
string s;

void Out(int *ans,int i=1)
{
  for(; key!=1 && i<MAXN && ans[i]==0; i++);//key=0,δ����1000λ,ʡ��ǰ��0
  for(; i<=MAXN; ++i)
    printf("%d",ans[i]);
  puts("");
}

int Mul(int u[],int v[],int ansn[])        //u*v=ansn
{
  int x[MAXN+1],y[MAXN+1];                 //���ڸ���a[]��b[],����a[],b[]ֱ���޸�
  memcpy(x,u,sizeof(int)*(MAXN+1));        //u���鸴�Ƶ�x����,��Ϊ��Mul(a,a,a)
  memcpy(y,v,sizeof(int)*(MAXN+1));        //v���鸴�Ƶ�y����
  memset(ansn,0,sizeof(int)*(MAXN+1));
  for(int i=MAXN; i>=1; --i)               //u
    for(int j=MAXN; j>=1; --j)             //v
      if(i+j<=MAXN && x[i]!=0 && y[j]!=0 ) //����1000λ���򲻼���
        key=1;                             //�����
      else if(i+j>MAXN)                    //δ����1000λ
        ansn[i+j-MAXN]+=x[i]*y[j];         //�˷�����
  for(int k=MAXN; k>=1; k--)               //����
    if(ansn[k]>=10)
    {
      ansn[k-1]+=ansn[k]/10;
      ansn[k]%=10;
    }
  if(ansn[0])                                    //��ʾ����1000λ
    key=1;
}

int main()
{
  //freopen("evolution.in","r",stdin);
  //freopen("evolution.out","w",stdout);
  ans[MAXN]=1;                                   //ans��Ϊ���յĽ��,��ʼΪ1
  cin>>s>>N;
  for(int i=0,len=s.size(); i<len; i++)
    a[MAXN-len+i+1]=s[i]-'0';                    //����12345�洢Ϊ000...00012345
  for(; N>1; N>>=1)                              //�����㷨
  {
    if(N&1)                                      //���Ϊ����
      Mul(ans,a,ans);                            //���������һ��a�˵�ans
    Mul(a,a,a);                                  //���a^2��ֵ��a
  }
  Mul(ans,a,ans);
  Out(ans);
  return 0;
}

