//�޲�դ��
//Ҫʹ�ܷ�����С����ôÿ��ֻѡȡ��С���ȵ�����ľ����ӣ��ٰ���Щ���͡��ۼӵ��ܷ����м���
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >wood;

int main()
{
  //freopen("repair.in","r",stdin);
  //freopen("repair.out","w",stdout);
  int n,l;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>l;
    wood.push(l);
  }
  long long ans=0;
  while(wood.size()>1)           //����Ԫ�ش���1��
  {
    int l1=wood.top();           //ȡ���Ѷ�Ԫ����Ϊ�����
    wood.pop();
    int l2=wood.top();           //ȡ����һ���Ѷ�Ԫ����Ϊ�Ҷ���
    wood.pop();
    ans+=l1+l2;                  //���ڵ���Ϊ��Ҷ�ӽڵ�,ȨֵΪa+b
    wood.push(l1+l2);            //���ڵ�Ȩֵ�Żض���
  }
  printf("%lld\n",ans);
  return 0;
}
