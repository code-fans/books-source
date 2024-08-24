//������Ϸ
#include <bits/stdc++.h>
using namespace std;

inline int Read()
{
  int x=0,f=1;
  char c=getchar();
  for(; c<'0' || c>'9'; c=getchar())
    if(c=='-')
      f=-1;
  for(; c>='0'&&c<='9'; c=getchar())
    x=x*10+c-'0';
  return x*f;
}

struct st
{
  int t,v;
} mouse[1000005];

bool Cmp(st a,st b)
{
  return a.t>b.t;
}

int main()
{
  freopen("mouse.in","r",stdin);
  freopen("mouse.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  priority_queue<int> q;               //���ȶ���Ĭ�ϴӴ�С��������
  long long ans=0,n,now=0;
  n=Read();
  for(int i=0; i<n; i++)
    mouse[i].t=Read();
  for(int i=0; i<n; i++)
    mouse[i].v=Read();
  sort(mouse,mouse+n,Cmp);             //��ʱ��Ӵ�С��
  for(int tim=mouse[0].t; tim>0; tim--)//������ͣ��ʱ��ĵ���ʼ
  {
    for(; mouse[now].t==tim; now++)    //�ѵ��ڵ�ǰʱ��ļ���
      q.push(mouse[now].v);
    if(!q.empty())
      ans+=q.top(),q.pop();            //ÿ��ȡ��ֵ���ģ������ڵĿ϶�������ʱ��Ҫ��
  }
  cout<<ans<<endl;
  return 0;
}

