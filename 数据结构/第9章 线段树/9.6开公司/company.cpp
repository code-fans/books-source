//����˾
#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
const int DAY=5e4;
#define ls (pos<<1)
#define rs (pos<<1|1)

double B[N+10],K[N+10];                    //B����y�ύ��,K��б��
int Lazy[N*4+10];                          //������ڱ���ֱ�߱��

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

bool Check(int a,int b,int x)              //�Ƚ���ֱ���ڵ�x���yֵ
{
  return K[a]*(x-1)+B[a]>K[b]*(x-1)+B[b];
}

void Update(int pos,int l,int r,int index)
{
  if (l==r)                               //���ΪҶ�ӽ��
  {
    if (Check(index,Lazy[pos],l))         //����²����ֱ�߸���
      Lazy[pos]=index;                    //����lazyΪ��ֱ��
    return;
  }
  int mid=(l+r)>>1;
  if (K[index]>K[Lazy[pos]])              //�²���ֱ��б�ʴ���ԭ�ȱ��
    if (Check(index,Lazy[pos],mid))       //�²���ֱ����mid����
    {
      Update(ls,l,mid,Lazy[pos]);         //ԭ����lazy��������������
      Lazy[pos]=index;                    //���µ�ǰlazyΪ��ֱ��
    }
    else
      Update(rs,mid+1,r,index);           //����������ֱ�߸���
  if (K[index]<K[Lazy[pos]])              //�²���ֱ��б��С��ԭ�ȱ��
    if (Check(index,Lazy[pos],mid))       //ԭ��ͬ�ϣ���
    {
      Update(rs,mid+1,r,Lazy[pos]);
      Lazy[pos]=index;
    }
    else
      Update(ls,l,mid,index);
}

double GetY(int a,int x)                  //��ȡ��x��Ļ���ֵ
{
  return K[a]*(x-1)+B[a];
}

double Query(int pos,int l,int r,int T)
{
  if (l==r)
    return GetY(Lazy[pos],T);
  int mid=(l+r)>>1;
  double ans=GetY(Lazy[pos],T);           //һ·���´�
  if (T<=mid)
    ans=max(ans,Query(ls,l,mid,T));
  else
    ans=max(ans,Query(rs,mid+1,r,T));
  return ans;
}

int main()
{
  freopen("company.in","r",stdin);
  freopen("company.out","w",stdout);
  int n=Read(),index=1;
  char s[10];
  for (int i=1; i<=n; i++)
  {
    scanf("%s",s+1);
    if (s[1]=='P')
    {
      scanf("%lf%lf",&B[index],&K[index]);
      Update(1,1,DAY,index++);
    }
    else
      printf("%d\n",int(Query(1,1,DAY,Read()))/100);
  }
  return 0;
}
