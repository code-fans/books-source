//�������
#include<bits/stdc++.h>
using namespace std;

struct Region
{
  int a,b;
} p[1010];

bool Cmp(const Region &p1,const Region &p2) //���Ҷ�����
{
  return (p1.b < p2.b);
}

void Calc(int k,int n)
{
  set <int> s;
  sort(p,p+n,Cmp);                          //�������Ҷ˿���
  for(int i=0; i<n; i++)                    //ö��n������
  {
    int ad=0;                               //adΪ�������ѳ��ֵĹ�����
    for(int j=p[i].b; j>=p[i].a; j--)       //ͳ�ƹ����
      if(s.find(j) != s.end())              //�����λ���й��
        ad++;
    int len=min(p[i].b-p[i].a+1,k);         //lenΪ����ĳ���,���Ϊk
    if(ad>=len)                             //�������㹻��������
      continue;
    for(int j=p[i].b,cnt=0; cnt<len-ad; j--)//�Ӻ���ǰ��,����ʣ��Ĺ��
      if(s.find(j)==s.end())                //�����λ��û�й��
      {
        s.insert(j);                        //�����¹��
        cnt++;                              //�����++
      }
  }
  printf("%d\n",s.size());                  //������
  for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
    printf("%d\n",*it);
}

int main()
{
  //freopen("ad.in","r",stdin);
  //freopen("ad.out","w",stdout);
  int t,k,n;
  for(scanf("%d",&t); t; t--)
  {
    scanf("%d %d",&k,&n);
    for(int i=0; i<n; i++)
    {
      scanf("%d %d",&p[i].a,&p[i].b);
      if(p[i].a>p[i].b)
        swap(p[i].a,p[i].b);
    }
    Calc(k,n);                              //ִ�к��Ĵ���
  }
  return 0;
}
