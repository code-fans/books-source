//���
#include <bits/stdc++.h>
using namespace std;

int n,m,q,u,v,t,sum;
int a[100010];

struct queue  //��д����
{
  int l,r,v[8000010];
  void push(int x)
  {
    v[++r]=x;
  }
  int front()
  {
    return v[l];
  }
  void pop()
  {
    l++;
  }
  bool empty()
  {
    return l>r?1:0;
  }
} p[3];

int Read(int Num=0)
{
  char C;
  for(; C<'0' || C>'9'; C=getchar());
  for(; C>='0' && C<='9'; C=getchar())
    Num=Num*10+C-'0';
  return Num;
}

int GetBig()//ÿ��ȡ3�������ж�������Ԫ�ؽ����и�
{
  for(int i=0; i<=2; i++)
  {
    if(p[i].empty())//�����ǰ���п�
      continue;
    if(i!=0 && !p[0].empty() && p[0].front()>p[i].front())
      continue;
    if(i!=1 && !p[1].empty() && p[1].front()>p[i].front())
      continue;
    if(i!=2 && !p[2].empty() && p[2].front()>p[i].front())
      continue;
    int x=p[i].front();
    p[i].pop();
    return x;
  }
}

int main()
{
  freopen("earthworm.in","r",stdin);
  freopen("earthworm.out","w",stdout);
  n=Read();
  m=Read();
  q=Read();
  u=Read();
  v=Read();
  t=Read();
  for(int i=1; i<=n; i++)
    a[i]=Read();
  sort(a+1,a+n+1);
  for(int i=n; i>=1; i--)
    p[0].push(a[i]);//��ʼ����p[0]�ɴ�С����
  p[0].l=p[1].l=p[2].l=1;//��߽�Ϊ1
  for(int i=1; i<=m; i++) //m��Ĳ���
  {
    int x=GetBig();
    if(i%t==0)//���1t,2t,3tʱ���жϵ����ĳ���
    {
      if(i!=t)
        printf(" ");
      printf("%d",x+sum);
    }
    p[1].push((long long)(x+sum)*u/v-sum-q);//�������ε�ǰ���
    p[2].push((x+sum)-(long long)(x+sum)*u/v-sum-q);//�������εĺ���
    sum+=q;//�ۼ�������q,ע��ǰ�濳�ϵ������Ѿ�����һ��q
  }
  printf("\n");
  for(int i=1; !p[0].empty()||!p[1].empty()||!p[2].empty(); i++)
  {
    int x=GetBig();
    if(i%t==0)
    {
      if(i!=t)
        printf(" ");
      printf("%d",x+sum);
    }
  }
  printf("\n");
  return 0;
}

