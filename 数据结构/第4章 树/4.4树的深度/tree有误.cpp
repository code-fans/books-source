#include <bits/stdc++.h>
using namespace std;

int cnt,a[1000001]= {0,1};//�洢ÿһ���ڵ����ȣ�����1�Ǹ��ڵ㣬�������Ϊ1
pair<int,int>p[1000001];//pair�����洢ÿһ�ֵ���Ϣ

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n,ans=1;
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>p[i].first>>p[i].second;//����
  while(cnt<n-1)//n-1(�˴����������ڵ�)���ڵ㶼�������
  {
    for(int i=1; i<=n; i++)
      if(a[i])//�����i���ڵ��Ѿ��������
      {
        a[p[i].first]=a[i]+1;
        a[p[i].second]=a[i]+1;//���Ҷ�����ȣ��������+1
        if(p[i].first>0)//����������(���Ҷ���),��cnt++(�ָ�һ���ڵ㸳�����)
          cnt++;
        if(p[i].second>0)
          cnt++;
        if(p[i].first!=0||p[i].second!=0)
          ans=max(a[p[i].first],ans);//����������Ľڵ��������������ȣ�����ˢ�����ֵ
        a[i]=0;//Ϊ�˷�ֹ��ȶ�θ�ֵ���ѵ�ǰ�ڵ㸳Ϊ0
      }
    cout<<ans<<endl;//���
  }
  return 0;
}
