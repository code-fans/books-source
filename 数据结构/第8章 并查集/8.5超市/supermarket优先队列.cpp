//���ȶ���
#include<bits/stdc++.h>
using namespace std;

int n, t,const int maxn = 1e4+100;

struct node
{
  int p,d;
  bool friend operator < (node a,node b) ///���ȶ�������С��ǰ�棬��Ϊ��������Ҫ�滻�ģ��滻���������
  {
    return a.p>b.p;
  }
} t[maxn];

bool cmp(node x,node y) ///�����ǵ�һ�ؼ��ʣ������ǵڶ��ؼ���
{
  return x.d<y.d||(x.d == y.d && x.p>y.p);
}
int main()
{
  int n;
  while(~scanf("%d",&n))
  {
    priority_queue<node>Q;
    for(int i = 1; i <= n; i++)
      cin>>t[i].p>>t[i].d ;
    sort(t+1,t+1+n,cmp);
    for(int i = 1; i <= n; i++)
      if(t[i].d>Q.size())///��ǰ��Ʒ��������ά���Ķ��У�ֱ����ӣ��ڵ�ǰ״̬�����϶���ѡ��
        Q.push(t[i]);
      else if(t[i].d == Q.size())///��ǰ��Ʒ����������ά���Ķ��У�����ͷ�ǲ��������С
        if(t[i].p>Q.top().p)//�滻��
          Q.pop(),Q.push(t[i]);
    int ans = 0;
    while(!Q.empty())
      ans+=Q.top().p,Q.pop();
    printf("%d\n",ans);
  }
  return 0;
}
