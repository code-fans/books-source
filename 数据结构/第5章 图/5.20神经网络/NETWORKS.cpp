//������
//ע���һ�㲻���ù�ʽ����Ϊ��Ŀ����һ�仰��"���������Ԫ������֮��"�����⣬��͹�ʽ�����������ķ�ֵ
#include <bits/stdc++.h>
using namespace std;

int n,p,c[110],u[110],rd[110],cd[110];
int g[110][110];//100�����ݿ����ڽӾ���
int q[2000010];
int main()
{
  freopen("NETWORKS.in","r",stdin);
  freopen("NETWORKS.out","w",stdout);
  cin>>n>>p;
  for(int i=1,u; i<=n; i++)
  {
    cin>>c[i]>>u;
    c[i]-=u;        //����ʽҪ���ÿһ��״̬������ֵ
  }
  for(int i=1,s,t; i<=p; i++)
  {
    cin>>s>>t;
    cin>>g[s][t];
    rd[t]++;         //��¼���
    cd[s]++;         //��¼����
  }
  int head=0,tail=1;
  for(int i=1; i<=n; i++)
    if(rd[i]==0)   //����������Ϊ0�Ľ��
      q[++tail]=i;//�����Ϊ0�ĵ�һ��������,׼����������
  while(head<tail)
  {
    head++;
    if(c[q[head]]>0)                        //�˷��򴫵�
    {
      for(int i=1; i<=n; i++)
        if(g[q[head]][i]!=0)
        {
          c[i]+=g[q[head]][i]*c[q[head]];   //����ʽ����
          q[++tail]=i;                      //���������
        }
      if(cd[q[head]]!=0)//�������һ��ĵ㣬����֮��Ҫ��״̬���
        c[q[head]]=0;
    }
  }
  int flag=0; //��¼��û��c>0�����
  for(int i=1; i<=n; i++)
    if(c[i]>0)
      flag=1,cout<<i<<" "<<c[i]<<endl;
  if(flag==0)
    cout<<"NULL"<<endl;
  return 0;
}

