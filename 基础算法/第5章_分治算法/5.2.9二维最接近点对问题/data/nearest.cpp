//��ӽ��������
#include <bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
int n,temp[1000001];

struct Point
{
  double x,y;
} S[1000001];

bool Cmp(const Point &a,const Point &b) //��x��������ȣ���y����
{
  return (a.x==b.x? a.y<b.y : a.x<b.x);
}

bool CmpY(const int &a,const int &b)    //��y��С��������
{
  return S[a].y<S[b].y;
}

double Dist(int i, int j)
{
  double x=(S[i].x-S[j].x)*(S[i].x-S[j].x);
  double y=(S[i].y-S[j].y)*(S[i].y-S[j].y);
  return sqrt(x+y);
}

double Find(int L,int R)                  //�ҵ�L��R֮����С����
{
  if(L==R)                                //�����ұ߽��غ�
    return INF;
  if(L+1==R)                              //�����ұ߽��ֵΪ����ֻ��������
    return Dist(L,R);
  int mid=(L+R)>>1;                       //���м仮��
  double d=min(Find(L,mid),Find(mid+1,R));//�ݹ������Сֵd
  int  k=0;
  for(int i=L; i<=R; ++i)                 //�ҳ�d��Χ�ڵĵ����temp[]
    if(fabs(S[mid].x-S[i].x)<=d)
      temp[k++]=i;
  sort(temp,temp+k,CmpY);                 //��y��������
  for(int i=0; i<k; ++i)                  //��ٴ���temp[]�ڵ���Щ��
    for(int j=i+1; j<k && S[temp[j]].y-S[temp[i]].y<d; ++j) //�ҳ����(p,q)
      d=min(d,Dist(temp[i],temp[j]));
  return d;
}

int main()
{
  //freopen("nearest.in","r",stdin);
  //freopen("nearest.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%lf%lf",&S[i].x,&S[i].y) ;
  sort(S,S+n,Cmp);                        //�㰴x������С��������
  printf("%.2lf\n",Find(0,n-1)/2);        //ע�����������
  return 0 ;
}

