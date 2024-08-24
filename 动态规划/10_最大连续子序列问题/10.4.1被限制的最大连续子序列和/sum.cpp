//�����Ƶ�������������к�
//��ͨ��dpת�Ʒ��̾��� dp[i] = sum[i] - min{sum[j]}  (i- m <= j <= i)
//���������ĸ��Ӷ����ﵽn^2�����Ե��Ż������õ��˵������С�
//�������У��������м����ֶ����е�Ԫ�ص�����������ݼ���������һ�����У�
//�õ���������������⣬һ�㶼����Ҫ�õ���ǰ��ĳ����Χ�ڵ���Сֵ�����ֵ
//������Ԫ�شӶ��ײ��룬�����Ԫ�رȶ���Ԫ��С�����Ķ���Ԫ�����ɾ�����ٲ���
//������֤���׵���β��Ԫ���ɴ�С�ݼ�����β��Ԫ����С
//������г��ȳ���m,��ɾ����β��Ԫ�أ��������ϸ���s[i]-��С����sum[j]�Ϳ�����

#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL sum[1000010];

list<int> q;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  int n,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    while(!q.empty())            //��ն���
      q.pop_back();
    sum[0] = 0;
    for(int i=1; i<=n; i++)
    {
      scanf("%lld",&sum[i]);
      sum[i] += sum[i-1];
    }
    LL maxn = 0;
    q.push_front(0);             //�����±�,�Է���������г���
    for(int i=1; i<=n; i++)
    {
      while(!q.empty() && sum[q.front()] > sum[i])//�ݼ�����,��֤��β����С
        q.pop_front();
      q.push_front(i);           //�Ӷ��ײ�����Ԫ��
      while(!q.empty() && i - q.back() > m)//��������Ѿ�����m
        q.pop_back();
      maxn = max(maxn,sum[i] - sum[q.back()]);//��ȥ��С��ֵ����β��
    }
    cout << maxn << endl<<endl;
  }
  return 0;
}

