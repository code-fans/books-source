//�������2
//�������ص�������棬���ص�λ��һ��������β��
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int s, e, t;
} a[5001];
int used[300001];

bool Cmp(node a, node b)
{
  return a.e < b.e;
}

int main()
{
  freopen("ad2.in","r",stdin);
  freopen("ad2.out","w",stdout);
  int n, w,ans=0;
  scanf("%d%d", &n, &w);
  for(int i=1; i<=w; i++)
    scanf("%d%d%d", &a[i].s, &a[i].e, &a[i].t);
  sort(a+1, a+w+1, Cmp);             //������λ������
  for(int i=1; i<=w; i++)
  {
    int ad = 0;
    for(int j=a[i].s; j<=a[i].e; j++)//ͳ�Ƹ�����Ĺ����
      if(used[j])
        ad++;
    if(ad >= a[i].t)                 //�������ѳ���Ҫ�������������
      continue;
    for(int j=a[i].e; j>=a[i].s && ad!=a[i].t; j--)//�����ɺ���ǰɨ��
      if(!used[j])
      {
        used[j]=1;                   //���ȱ�ٵĹ��
        ad++;
        ans++;
      }
  }
  printf("%d\n", ans);
  return 0;
}
