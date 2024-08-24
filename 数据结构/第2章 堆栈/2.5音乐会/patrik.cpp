//���ֻ�
#include <bits/stdc++.h>
using namespace std;
const int N=500050;

int H[N],Stack[N];                   //H[]�������,Stack[]Ϊ����ջ
long long Ans;                       //����ȡint
int top;                             //topָ�򵥵�ջ��

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

void Calc(int x)                     //����������վ�������������Ż�
{
  int L=0,R=top,pos=0;
  while(L<=R)                        //�򵥵�ջ�ǵݼ��ģ����Կ��Զ��ֲ���
  {
    int mid=(L+R)>>1;
    if(H[Stack[mid]]>x)
      pos=mid,L=mid+1;                //����pos����x��ߵ�һ����x�ߵ���
    else R=mid-1;
  }
  !pos? Ans+=top:Ans+=top-pos+1;     //!pos��ʾû�ҵ���x�ߵ���
}

int main()
{
  //freopen("patrik.in","r",stdin);
  //freopen("patrik.out","w",stdout);
  int n=Read();
  for(int i=1; i<=n; ++i)
    H[i]=Read();
  for(int i=1; i<=n; ++i)
  {
    Calc(H[i]);
    while(top>0 && H[i]>H[Stack[top]])//ά�������ݼ�ջ
      --top;
    Stack[++top]=i;                   //��ǰԪ����ջ,����������,�������
  }
  printf("%lld\n",Ans);
  return 0;
}

