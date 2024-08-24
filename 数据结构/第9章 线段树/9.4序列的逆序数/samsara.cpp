//���е����������߶���
#include <bits/stdc++.h>
using namespace std;

struct Seg_Tree
{
  int left,right,val;
  int calmid()
  {
    return (left+right)>>1;
  }
} t[15000];
int val[5001];                               //��������

void BuildTree(int left,int right,int pos)
{
  t[pos].left = left;
  t[pos].right = right;
  t[pos].val = 0;                            //��һ�䲻��ʡ
  if(left != right)
  {
    int mid = t[pos].calmid();
    BuildTree(left,mid,pos<<1);
    BuildTree(mid+1,right,pos<<1|1);
  }
}

int Query(int L,int R,int pos)               //ͳ��[L,R]�����L���������
{
  if(L <= t[pos].left && R >= t[pos].right)  //����ڰ��������ڣ��򷵻�ֵ
    return t[pos].val;
  int min = (t[pos].left+t[pos].right)>>1;   //ȡ���Ҷ˵���м�
  int ans = 0;
  if(L <= min)
    ans += Query(L, R, pos<<1);          //�ݹ�������
  if(R > min)
    ans += Query(L, R, pos<<1|1);        //�ݹ�������
  return ans;
}

void Update(int id,int pos)              //�������а���id������������valֵ
{
  t[pos].val ++;                         //��һ
  if(t[pos].left != t[pos].right)
  {
    int mid = t[pos].calmid();
    if(id <= mid)
      Update(id,pos<<1);
    else
      Update(id,pos<<1|1);
  }
}

int main()
{
  //freopen("samsara.in","r",stdin);
  //freopen("samsara.out","w",stdout);
  int n;
  while(scanf("%d",&n) == 1)
  {
    BuildTree(0,n-1,1);
    unsigned long long sum = 0;
    for(int i=0; i<n; i++)
    {
      scanf("%d",&val[i]);
      sum += Query(val[i],n-1,1);        //��ʱval[i]��δ��������
      Update(val[i],1);                  //��ʱ����val[i]����������
    }
    unsigned long long Ans = sum;
    for(int i=0; i<n; i++)
    {
      sum=sum-val[i]+(n-val[i]-1);
      Ans=min(Ans,sum);
    }
    cout<<Ans<<endl;
  }
  return 0;
}

