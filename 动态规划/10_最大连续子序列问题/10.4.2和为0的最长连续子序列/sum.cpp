//��Ϊ0�������������
//����ǰ��͵�dp[]
//����������a[]:  7 -7 8 6   5 -5 -5 0 -6 11
//��ǰ׺����dp[]: 7  0 8 14 19 14  9 9  3 14
//dp[]�У���0��,��ͬdpֵ��14��14,9��9���⼸������ĺ;�Ϊ��
//��14��3��ֵ����Ȼѡ����ߵ�14�����ұߵ�14������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  int n,Max=0;
  cin>>n;
  vector<int> dp(n+1);           //�ඨ��һ��0
  for (int i=1,v; i<=n; i++)
  {
    cin>>v;
    dp[i]=dp[i-1]+v;
  }
  map<int, int> m;               //dp[i]ֵΪkey,valueΪ�±�i
  for (int i=1; i<=n; i++)
    if (m[dp[i]]==0 && dp[i]!=0) //��һ�γ������ֵ
      m[dp[i]]=i;                //����ֵ���±����map
    else                         //�ڶ��γ��ֻ����ǣ�
      Max=max(Max,i-m[dp[i]]);   //���������ͬ��ֵ�ˣ����
  cout<<Max<<endl;
  return 0;
}
