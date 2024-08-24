//��ͨƽ�������ǵݹ�д��
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;
const int MAXN=180005;

int val[MAXN],son[MAXN][2],siz[MAXN];
int tot,root,n;

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

int New(int num)                             //�����½��
{
  val[++tot]=num;
  siz[tot]=1;
  return tot;
}

void Insert(int num)                          //������
{
  int *p=&root;
  while(*p)
    ++siz[*p],p=&son[*p][num>val[*p]];
  *p=New(num);
}

void Erase(int num)                               //ɾ���ڵ�
{
  int *p=&root;
  while(val[*p]!=num)                              //����Ŀ��
    --siz[*p],p=&son[*p][num>val[*p]];
  --siz[*p];
  if(!son[*p][0]||!son[*p][1])                   //Ҷ�ӽ���ֻ��һ������
  {
    *p=son[*p][0]+son[*p][1];
    return;
  }
  int *q=&son[*p][1];
  while (son[*q][0])
    --siz[*q],q=&son[*q][0];
  val[*p]=val[*q];
  *q=son[*q][1];
}

int GetRnk(int num)                                 //��������
{
  int sum=1;
  int p=root;
  while(p)
  {
    if(num>val[p])
    {
      sum+=siz[son[p][0]]+1;
      p=son[p][1];
    }
    else
      p=son[p][0];
  }
  return sum;
}

int GetVal(int id)                                    //���Ҷ�Ӧ������ֵ
{
  int p=root;
  while (p)
  {
    if(id<=siz[son[p][0]])
      p=son[p][0];
    else if(id>siz[son[p][0]]+1)
      id-=siz[son[p][0]]+1,p=son[p][1];
    else
      break;
  }
  return val[p];
}

int GetPre(int num)                                  //����ǰ��
{
  int ans=-INF;
  int p=root;
  while(p)
  {
    if(val[p]<num)
      ans=val[p];
    p=son[p][num>val[p]];                           //����������
  }
  return ans;
}

int GetNxt(int num)                                //���Һ��
{
  int ans=INF;
  int p=root;
  while(p)
  {
    if(val[p]>num)
      ans=val[p];
    p=son[p][num>=val[p]];                           //��������
  }
  return ans;
}

int main()
{
  freopen("BalanceTree.in","r",stdin);
  freopen("BalanceTree.out","w",stdout);
  n=Read();
  for(int i=0,opt,x; i<n; ++i)
  {
    opt=Read(),x=Read();
    if(opt==1)
      Insert(x);
    else if(opt==2)
      Erase(x);
    else if(opt==3)
      printf("%d\n", GetRnk(x));
    else if(opt==4)
      printf("%d\n", GetVal(x));
    else if(opt==5)
      printf("%d\n", GetPre(x));
    else
      printf("%d\n", GetNxt(x));
  }
  return 0;
}
