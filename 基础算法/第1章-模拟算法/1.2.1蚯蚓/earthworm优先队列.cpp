//���-���ȶ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("earthworm.in","r",stdin);
  freopen("earthworm.out","w",stdout);
  priority_queue<int> earthworm;  //���ȶ���Ĭ���ɴ�С����
  int n,m,t,q,u,v,sum=0;          //sum���ڱ����ۼ����ӵ�qֵ
  cin>>n>>m>>q>>u>>v>>t;
  double p=double(u)/v;
  for(int i=0,temp; i<n; ++i)
  {
    cin>>temp;
    earthworm.push(temp);         //�����
  }
  for(int i=1; i<=m; i++)
  {
    int Big=earthworm.top()+sum;  //����Ϊ���ֵ������ʱ��ԭ����ʵֵ
    earthworm.pop();              //ɾ�����׵����
    if(!(i%t))                    //�����i*t���е����
      cout<<Big<<" ";
    int cut=floor(p*double(Big)); //��floor�Է����������ͬ���������
    earthworm.push(cut-sum-q);    //�и����������q,�����ȼ�ȥ
    earthworm.push(Big-cut-sum-q);
    sum+=q;                       //�ۼ��ܵ�������
  }
  cout<<'\n';
  for(int i=1; i<=n+m; ++i)
  {
    if(!(i%t))
      cout<<earthworm.top()+sum<<' ';
    earthworm.pop();
  }
  cout<<'\n';
  return 0;
}

