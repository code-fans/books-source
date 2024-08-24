//������
#include<bits/stdc++.h>
using namespace std;

int n,Ans=0x3f3f3f3f;
bool flag;
int a[110],Group[110];         //a[]������,Group[i]����a[i]�ֵ���һ��

int GCD(int a,int b)
{
  return a%b==0?b:GCD(b,a%b);
}

void DFS(int now,int group)    //�ѵ��˵�now������������group������
{
  if(now>n)                    //������ɣ�ȡ��Сֵ���˳�
  {
    Ans=min(Ans,group);
    return;
  }
  for(int g=1; g<=group; g++)  //���Լӵ�ĳһ����
  {
    flag=true;
    for(int j=1; j<now; j++)   //��ǰ���now��֮ǰ�ļ���һ�������г���
    {
      if(Group[j]==g)          //�����j��������g��
        if(GCD(a[now],a[j])!=1)//��ô�ͱȽ�now�Ƿ�͸��������Ϊ������
        {
          flag=false;          //�����ʾ�û��Ҫ��������ȥ��
          break;               //����
        }
    }
    if(flag)                   //������Լӵ�g��
    {
      Group[now]=g;            //�ѵ�now�������浽��g��
      DFS(now+1,group);        //������һ��������������
      Group[now]=0;            //����
    }
  }
  Group[now]=group+1;          //now���ӵ��κμ��ϣ���һ������
  DFS(now+1,group+1);          //������һ�β���
  Group[now]=0;                //����
}

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  DFS(1,1);                     //�ӵ�һ������ֻ��һ�鿪ʼ
  cout<<Ans<<endl;
  return 0;
}

