//����
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int x, y;
} s[100005];

int Cmp(node a, node b)              //��xֵ��С������,�����y��С������
{
  return (a.x==b.x ? a.y<b.y : a.x<b.x);
}

int main()
{
  freopen("Treasure_map.in","r",stdin);
  freopen("Treasure_map.out","w",stdout);
  int n,m,p;
  scanf("%d%d%d", &n, &m, &p);
  vector <int> v;                    //�˴�vector����ջʹ��
  for(int i = 0; i < p; i++)
    scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s+p, Cmp);
  for(int i = 0; i < p; i++)
  {
    vector<int>::iterator it=upper_bound(v.begin(),v.end(),s[i].y);
    if(it != v.begin())              //�������ͷԪ��
      *--it=s[i].y;                  //�Ѹ�λ�õ�ֵ�滻Ϊs[i].y
    else                             //���s[i].y>ͷԪ��,��ֱ�Ӳ���
      v.insert(v.begin(), s[i].y);
  }
  printf("%d\n", v.size());
  return 0;
}

