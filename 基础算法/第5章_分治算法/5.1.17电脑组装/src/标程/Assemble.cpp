//������װ
//����+���֣����벻Ҫһ���ַ�һ���ַ����������ʱ���������ַ����Ƚϣ�
//�ѡ����ࡱ���ַ���ӳ�������
//��ÿһ���������������С��������Ȼ����ִ�quality��
//ÿһ�������ѡһ��Ʒ�ʲ�����quality������˵ģ���Ԥ��Ƚϼ��ɡ�
#include <bits/stdc++.h>
using namespace std;

struct computer
{
  int type,price,quality;
} d[1005];

int have[1005],n,budget,t,Count;

int Cmp(computer a,computer b)
{
  return a.quality<b.quality;
}

int Judge(int middle)
{
  memset(have,-1,sizeof(have));
  for(int i=middle; i<n; i++)        //������middle�����Ŀ�ʼѡ
  {
    if(have[d[i].type]==-1)          //��������ͻ�û��ͳ��
      have[d[i].type]=d[i].price;    //����Ӹ����͵�һ������ļ�ֵ
    else if(have[d[i].type]>d[i].price)
      have[d[i].type]=d[i].price;    //ѡȡ����ѡ����quality������˵Ĳ���
  }
  int sum=0;
  for(int i=0; i<Count; i++)         //���Ƿ��������Ͷ�ѡ��
    if(have[i]==-1)                  //����ûѡ�ģ���ʧ��
      return 0;
    else
      sum+=have[i];                  //�����ۼ�
  return sum>budget?0:1;             //������Ԥ�㣬ʧ��
}

int Binary(int left,int right)       //����������
{
  while(left<right)
  {
    int middle=(left+right+1)>>1;    //Ҫ��1����������8,9�ͳ���ѭ��
    Judge(middle)?left=middle:right=middle-1;
  }
  return d[left].quality;
}

int main()
{
  //freopen("Assemble.in","r",stdin);
  //freopen("Assemble.out","w",stdout);
  char a[25];
  for(cin>>t; t; t--)
  {
    Count=0;
    scanf("%d%d",&n,&budget);        //�������Ԥ��
    map<string,int> MAP;             //��stringӳ��Ϊ����
    for(int i=0; i<n; i++)
    {
      string type,name;              //������û���õ�
      cin>>type>>name>>d[i].price>>d[i].quality;
      if(MAP.find(type)==MAP.end())     //��������ͻ�û��
        MAP[type]=Count++;           //�����ӳ��Ϊĳ������
      d[i].type=MAP[type];           //��ǹ���
    }
    sort(d,d+n,Cmp);                 //����������
    cout<<Binary(0,n-1)<<endl;
  }
  return 0;
}
