#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("escape.in","r",stdin);
  //freopen("escape.out","w",stdout);

  int m,s,t,now=0;
  cin>>m>>s>>t;
  int s1=0,s2=0;//����ܲ����ߵľ��������˸���ߵľ���
  for(int i=1; i<=t; i++) //һ����ʱ��ȥ��
  {
    s1+=17;//���ֺ��ܲ���������
    if(m>=10)
    {
      s2+=60;  //�ܹ�������϶�Ҫ���ֵģ�
      m-=10;
    }
    else m+=4;//û����һ�غϾ���������
    if(s2>s1) s1=s2;//���ֵĿ��˾Ͱ��ܲ����滻�����ֵ�
    if(s1>s) //�ܳ�ȥ�˾������ǰʱ��
    {
      cout<<"Yes"<<endl<<i<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl<<s1<<endl;//ʱ�䶼�����˻�û�ܳ�ȥ�������No����s1��ֵ�����������ֿ��߾���һ�������ܲ����ܲ��ľ���ͻᱻ�滻����ʱ�ܵľ���Զ��һ����s1��
}
