//��ˮ��ҵ��������
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

struct node
{
  int x,y;
} a[MAXN],b[MAXN],c[MAXN];

bool cmp1(const node &p, const node &q)
{
  return p.x < q.x;
}

bool cmp2(const node &p, const node &q)
{
  return p.y > q.y;
}

int main()
{
  freopen("flowshop.in","r",stdin);
  freopen("flowshop.out","w",stdout);
  int n;
  while(scanf("%d",&n) && n)
  {
    for(int i=0; i<n; ++i)
      scanf("%d%d",&a[i].x,&a[i].y);
    int len1 = 0, len2 = 0;
    for(int i=0; i<n; ++i)
      if(a[i].x < a[i].y)
      {
        b[len1].x = a[i].x;               //�Ӽ�1 x<y
        b[len1++].y = a[i].y;
      }
      else
      {
        c[len2].x = a[i].x;               //�Ӽ�2
        c[len2++].y = a[i].y;
      }
    sort(b,b+len1,cmp1);                  //�Ӽ�1��ҵ˳��x����
    sort(c,c+len2,cmp2);                  //�Ӽ�2��ҵ˳��y����
    for(int i = len1; i<len1+len2; ++i)   //�ϲ����Ӽ�
      b[i] = c[i-len1];
    int s1sum[MAXN] = {0};
    for(int i=0; i<n; ++i)                //����M1���ѵ�ʱ��
      s1sum[i+1] = s1sum[i]+b[i].x;
    int sum = 0;
    for(int i=0; i<n; ++i)                //����M2���ѵ�ʱ��
      if(sum<s1sum[i+1])                  //Ҫ�ȵ�M1��ɲ��ܿ�ʼM2
        sum = s1sum[i+1]+b[i].y;
      else
        sum+=b[i].y;
    printf("%d\n",sum);
  }
  return 0;
}

