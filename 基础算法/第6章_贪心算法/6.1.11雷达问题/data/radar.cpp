//�״�����
#include <bits/stdc++.h>
using namespace std;

struct IsLand                               //����ṹ��[a,b]
{
  double a,b;
} b[1001];

int Cmp(IsLand x,IsLand y)
{
  return x.b<y.b ;
}

int main()
{
  freopen("radar.in","r",stdin);
  freopen("radar.out","w",stdout);
  int n,d,x,y;
  for(int Case=1; cin>>n>>d,n; Case++)      //nΪ0���˳�
  {
    int Ok=1;
    for(int k=0; k<n; ++k)
    {
      cin>>x>>y;
      if(abs(y)>d)                     //���괹ֱ���볬��d,�޽�
        Ok=0;                          //����ֱ���˳����������ݻ���
      b[k].a=x-sqrt(d*d-y*y);          //�������x�����߽�
      b[k].b=x+sqrt(d*d-y*y);          //�������x����ұ߽�
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

