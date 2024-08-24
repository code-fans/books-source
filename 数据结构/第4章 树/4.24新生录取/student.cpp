//����¼ȡ
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int lower[MAXN];   //lower[i]��ʾ�Ե�i��Ϊ��λ��ʱС����λ�����˵Ĳ����ܺ�
int upper[MAXN];   //upper[i]��ʾ�Ե�i��Ϊ��λ��ʱ������λ�����˵Ĳ����ܺ�
pair<int, int>people[MAXN];                   //����ÿ���˵ķ�����Ǯ��

int main()
{
  freopen("student.in","r",stdin);
  freopen("student.out","w",stdout);
  int n,c,f;
  scanf("%d%d%d",&n,&c,&f);
  for(int i = 0; i < c; i++)
    scanf("%d%d",&people[i].first, &people[i].second);
  sort(people, people+c);                      //��������С��������

  int total = 0;
  int half = n/2;
  priority_queue<int>q;
  for(int i = 0; i < c; i++)                   //����ÿ�������n/2���˵�ѧ�Ѻ�
  {
    lower[i] = (q.size() == half? total:INF);  //��������������n/2�����ֵ
    q.push(people[i].second);
    total += people[i].second;                 //ͳ����Ǯ��
    if(q.size() > half)                        //�������������n/2
    {
      total -= q.top();
      q.pop();                                 //������ҪǮ�����ĵ���
    }
  }

  total = 0;
  priority_queue<int>q1;
  for(int i = c-1; i >= 0; i--)                //����ÿ�����ұ�n/2���˵�ѧ�Ѻ�
  {
    upper[i] = (q1.size() == half? total:INF);
    q1.push(people[i].second);
    total += people[i].second;
    if(q1.size() > half)
    {
      total -= q1.top();
      q1.pop();
    }
  }
  int ans = -1;
  for(int i = c-1; i >= 0; i--)                //���ҵ��ұ������п���
    if(lower[i]+people[i].second+upper[i] <= f)//���û�г����ܷ���
    {
      ans = people[i].first;
      break;
    }
  printf("%d\n",ans);
  return 0;
}

