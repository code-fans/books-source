#include<bits/stdc++.h>
using namespace std;

double d1,c,d2,oil,ans;	//oil:ʣ�µ����� ans:��С���� ����������Ϊ�������
double d[10],p[10];
int n,j;

int main()
{
  freopen("budget.in","r",stdin);
  freopen("budget.out","w",stdout);
  cin>>d1>>c>>d2>>p[0]>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>d[i]>>p[i];
    if(d[i]-d[i-1]>c*d2)
    {
      cout<<"No Solution\n";
      return 0;
    }
  }
  d[n+1]=d1;
  for(int i=0; i<=n; i=j)               //iΪ��ǰ������
  {
    for(j=i+1; d[j]-d[i]<=c*d2 && j<=n+1; j++)
      if(p[j]<p[i]) 		            //���ҵ������˵ļ���վ
      {
        ans+=((d[j]-d[i])/d2-oil)*p[i]; //�Ӹպ��㹻�����j������վ����
        oil=0;
        break;
      }
    if(d[j]-d[i]>c*d2)                  //û�ҵ������˵ļ���վ����ǰ�ͼ������
    {
      ans+=(c-oil)*p[i];			    //�������価����
      oil=c-(d[--j]-d[i])/d2;           //����j��ʣ�µ��� 
    }
  }
  printf("%.2lf\n",ans);
  return 0;
}
