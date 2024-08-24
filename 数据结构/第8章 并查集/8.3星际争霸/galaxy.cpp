//�Ǽ�����
#include<bits/stdc++.h>
using namespace std;
const int MAX=30010;
int p[MAX],sum[MAX],cnt[MAX];     //sum[i]:i�����ĳ���ǰ׺��,cnt[]:����ս����

int Father(int x)
{
  if(p[x]==x)
    return x;
  int px=Father(p[x]);            //���ҵ���(��������),���򳤶ȼ�������
  sum[x]+=sum[p[x]];              //ά��x�����ĳ���ǰ׺�ͣ�+�����ȵ������ľ���
  return p[x]=px;                 //·��ѹ�������ظ���㼴p[x]
}

void Union(int i,int j)
{
  int RootI=Father(i);
  int RootJ=Father(j);
  if(RootI==RootJ)
    return;
  p[RootI]=RootJ;                 //i����ָ��j���еĸ�(·��ѹ��)
  sum[RootI]+=cnt[RootJ];         //����i�����׵������ľ���
  cnt[RootJ]+=cnt[RootI];         //���кϲ���ս��������
}

int main()
{
  //freopen("galaxy.in","r",stdin);
  //freopen("galaxy.out","w",stdout);
  int N,x,y;
  scanf("%d\n",&N);
  for(int i=1; i<=30000; i++)
    p[i]=i,cnt[i]=1;              //ÿ�и�����ʼ�����Լ���ս����Ϊ1
  while(N--)
  {
    char s;
    scanf("%c%d %d%*c",&s,&x,&y);
    if(s=='M')
      Union(x,y);
    else
      printf("%d\n",Father(x)^Father(y)?-1:abs(sum[x]-sum[y])-1);
  }
  return 0;
}

