//������
//ע���һ�㲻���ù�ʽ����Ϊ��Ŀ����һ�仰��"���������Ԫ������֮��"
//���⣬��͹�ʽ�����������ķ�ֵ,BFSҲ����
#include <bits/stdc++.h>
using namespace std;

int w[110][110],c[110],rd[110],cd[110];

int main()
{
  //freopen("NETWORK.in","r",stdin);
  //freopen("NETWORK.out","w",stdout);
  int n,p,outs=0;
  cin>>n>>p;
  for(int i=1,u; i<=n; i++)
  {
    cin>>c[i]>>u;
    if(c[i]==0)                        //�������
      c[i]-=u;                      //����ʽҪ���Ȱ�ÿһ��״̬������ֵ
  }
  for(int i=1,s,t; i<=p; i++)
  {
    cin>>s>>t;
    cin>>w[s][t];
    rd[t]++;                           //���++
    cd[s]++;                           //����++
  }
  queue <int> q;                       //�����Ƚ��ȳ�,�ȷ���Ľڵ����һ��>=�����Ľڵ����
  for(int i=1; i<=n; i++)
    if(rd[i]==0)                       //�����Ϊ0�ĵ�һ��������,׼����������
      q.push(i);
  while(!q.empty())
  {
    int head=q.front();
    q.pop();
    for(int i=1; i<=n; i++)
      if(c[head]>0 && w[head][i]!=0)   //�˷��򴫵�
      {
        c[i]+=w[head][i]*c[head];      //����ʽ����
        q.push(i);                     //���������
      }
    if(cd[head]!=0)                    //�������һ�㣬����֮��Ҫ״̬���
      c[head]=0;
  }
  for(int i=1; i<=n; i++)
    if(c[i]>0)
    {
      outs=1;
      cout<<i<<" "<<c[i]<<endl;
    }
  if(outs==0)
    cout<<"NULL"<<endl;
  return 0;
}
