//������
#include <bits/stdc++.h>
using namespace std;

int Card[15];
int ans;
void DFS(int step);

void Straight(int step,int Max,int num)//��������Max�ŵ�˳��
{
  int j;
  for(int i=1; i<=11; i++)             //ö��
  {
    for(j=i; j<=12; j++)
    {
      Card[j]-=num;                    //������˳�ӵ�������
      if(Card[j]<0) break;             //������˳�����˳�
      if(j-i>=Max)
        DFS(step+1);
    }
    for(int k=i; k<=j && k!=13; k++)   //�ָ�ԭ��
      Card[k]+=num;
  }
}

void DFS(int step)
{
  if(step>ans)  return;                //��֦
  int s1=0,s2=0,s3=0,s4=0;             //���ţ����ӣ����ţ�����
  for(int i=1; i<=14; i++)
  {
    if(Card[i]==1) s1++;               //ͳ�Ƶ��Ƹ���
    if(Card[i]==2) s2++;               //ͳ�ƶ��Ƹ���
  }
  for(int i=1; i<=13; i++)             //�����ܴ����ȴ���
    if(Card[i]==4)
    {
      s4++;
      if(s1>=2) s1-=2;                 //�Ĵ�����
      else if(s2>=2) s2-=2;            //�Ĵ�����
      else if(s2>=1) s2--;             //�Ĵ�һ��
    }
  for(int i=1; i<=13; i++)
    if(Card[i]==3)
    {
      s3++;
      if(s1>=1) s1--;                  //����һ��
      else if(s2>=1) s2--;             //����һ��
    }
  ans=min(ans,step+s1+s2+s3+s4);       //��������ƺ�����
  Straight(step,4,1);                  //�������˳�ӵ����
  Straight(step,2,2);                  //�����˫˳�ӵ����
  Straight(step,1,3);                  //�������˳�ӵ����
}

int main()
{
  //freopen("landlords.in","r",stdin);
  //freopen("landlords.out","w",stdout);
  int T,n;
  for(cin>>T>>n; T--; cout<<ans<<endl)
  {
    ans=n;
    memset(Card,0,sizeof(Card));
    for(int i=1,a,b; i<=n; i++)
    {
      cin>>a>>b;
      if(a==0)  a+=16;
      if(a==1 || a==2) a+=13;
      Card[a-2]++;
    }
    DFS(0);
  }
  return 0;
}
