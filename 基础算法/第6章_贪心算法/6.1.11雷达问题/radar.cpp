//�״�����
#include <bits/stdc++.h>
using namespace std;

struct coordinate                           //����ṹ��(x,y)
{
  int x,y;
} p[1001];

struct island                               //����ṹ��[a,b]
{
  double a,b;
} b[1001];

int Cmp(island x,island y)
{
  return x.b<y.b ;
}

double Limit(coordinate a,int d)            //�ҳ����������Ӧ��Բ������Χ
{
  return sqrt(d*d-a.y*a.y);                 //�õ����ɶ���
}

int main()
{
  //freopen("radar.in","r",stdin);
  //freopen("radar.out","w",stdout);
  int n,d,k;
  for(int Case=1; cin>>n>>d,n; Case++)      //nΪ0���˳�
  {
    int Ok=1;
    for(k=0; k<n; ++k)
    {
      cin>>p[k].x>>p[k].y;
      if(abs(p[k].y)>d)                     //���괹ֱ���볬��d,�޽�
        Ok=0;                               //����ֱ���˳����������ݻ���
      b[k].a=p[k].x-Limit(p[k],d);          //�������x�����߽�
      b[k].b=p[k].x+Limit(p[k],d);          //�������x����ұ߽�
    }
    if(Ok==0)
      cout<<"Case "<< Case<<": "<<-1<<endl;
    else
    {
      int last=0;
      int radar=1;
      sort(b,b+n,Cmp);                      //�����䰴�ұ߽��С��������
      for(int i=0; i<n; ++i)
        if(b[i].a>b[last].b)                //�԰�������ȡ���Ҷ˵ĵ�
        {
          ++radar;                          //��������ǰ������ҽ磬����״�
          last=i;
        }
      cout<<"Case "<<Case<<": "<<radar<<endl;
    }
  }
  return 0;
}

