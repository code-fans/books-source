//Ԥ��
#include<bits/stdc++.h>
using namespace std;

double d[10],p[10];
double d1,c,d2,oil,go,ans;   //oil:�����е�������go:�������
int n,now;                   //now:��ǰλ��

int main()
{
//  //freopen("budget.in","r",stdin);
//  //freopen("budget.out","w",stdout);
  cin>>d1>>c>>d2>>p[0]>>n;        //����,��������,ÿ������ʻ����,����ͼ�,��վ��
  double Power=c*d2;              //Powerָ���Ǽ�����������ߵ����
  for(int i=1; i<=n; i++)
  {
    cin>>d[i]>>p[i];
    if(d[i]-d[i-1]>Power)
    {
      cout<<"No Solution\n";      //�ܲ�������վ���޽�
      return 0;
    }
  }
  for(double cheap=1e9; go!=d1; cheap=1e9)//cheapΪ���ҵ�������˵���
  {
    for(int i=now+1; d[i]-go<=Power && i<=n; i++)//�ҵ��ܵ��������˵���վ
      if(p[i]<cheap)
      {
        cheap=p[i];
        now=i;
      }
    if(cheap<=p[0])               //��Χ�ڵļ���վ�����ڵ��ͼۻ�����
    {
      ans+=((d[now]-go)/d2-oil)*p[0];//�ӵ��͸պ��ܵ����������վ
      oil=(d[now]-go)/d2;
    }
    else if(d1-go>Power)          //��Χ�ڵļ���վ�������ڵ��ͼ۹����޷�һ�ε����յ�
    {
      ans+=(c-oil)*p[0];          //�������������˵ļ���վ����
      oil=c;
    }
    else                          //��Χ�ڵļ���վ�����ڵ��ͼ۹󣬵���һ�ε����յ�
    {
      ans+=((d1-go)/d2-oil)*p[0]; //�����յ�
      break;
    }
    oil-=(d[now]-go)/d2;          //��������
    go=d[now];                    //�ߵ�d[now]
    p[0]=cheap;
  }
  printf("%.2lf\n",ans);
  return 0;
}
