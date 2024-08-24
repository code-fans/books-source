//����ƴд���
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1123357;             //�˴����������󣬿�ѡ�����������
string h[MAXN+1];
int Total;

int Hash(string x)
{
  int L=x.length();
  return ((x[0]-65)*10000+(x[L/2]-65)*100+(x[L-1]-65))%MAXN;//ȡͷ���С�β
}

void Insert(string x)
{
  int t=Hash(x);
  while(h[t]!="" && h[t]!=x)
  {
    t++;
    if(t==MAXN)
      t=0;
  }
  h[t]=x;
}

void Find(string x)
{
  int t=Hash(x);
  while(h[t]!="" && h[t]!=x)
  {
    t++;
    if(t==MAXN)
      t=0;
  }
  if(h[t]=="")                         //û�ҵ�
    Total++;
}

int main()
{
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  int n,m;
  string wrd;
  cin>>n;                              //���ʿ�ĵ��ʸ���
  for(int i=1; i<=n; i++)
  {
    cin>>wrd;
    Insert(wrd);
  }
  cin>>m;                              //���鵥����
  for(int i=1; i<=m; i++)
  {
    cin>>wrd;
    Find(wrd);
  }
  cout<<Total<<endl;
  return 0;
}

