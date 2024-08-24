//ʱ�ն�λ2
#include <bits/stdc++.h>
using namespace std;
#define N 10010

struct Node
{
  double begin,end;
} node[N];

int Cmp(const Node &a,const Node &b)
{
  if(a.begin!=b.begin)
    return a.begin<b.begin;
  else
    return a.end <b.end;
}

int main()
{
  //freopen("location2.in", "r", stdin);
  //freopen("location2.out", "w", stdout);
  int ncase;                         //����������
  scanf("%d",&ncase);
  while(ncase--)
  {
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    double R= h/(2*1.0) ;
    int k=0;
    for(int i=0; i<n; i++)           //Ԥ����������ת��Ϊ��������
    {
      int x;
      double r;
      scanf("%d%lf",&x,&r);
      if(r>R)
      {
        r=sqrt(r*r- h*h/(4*1.0));
        node[k].begin=x-r<0?0:x-r;
        node[k].end=x+r>w?w:x+r;
        k++;
      }
      else
        continue;                    //ɾȥ����������װ��
    }
    sort(node,node+k,Cmp);
    int ans=0;
    double p=0;
    int flag=1;
    while(p<w)                       //����û������
    {
      double Max=0;
      //Ѱ�ҷ����������������Ҷ˵�ֵ�����Ǹ�
      for(int i=0; node[i].begin<=p && i<k; i++)
        if(node[i].end-p>=Max)
          Max=node[i].end-p;
      if(!Max)
      {
        flag=0;
        break;
      }
      p+=Max;
      ans++;
    }
    printf("%d\n",flag?ans:0);
  }
  return 0;
}

