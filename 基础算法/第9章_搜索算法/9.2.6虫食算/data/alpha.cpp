//��ʳ��
#include <bits/stdc++.h>
using namespace std;
const int N=30;

int n,cnt;
int a[N],b[N],c[N],num[N],Next[N];
bool used[N];

bool Judge()                //����Ƿ���ȷ
{
  for(int i=n-1,x=0; i>=0; i--)
  {
    if((num[a[i]]+num[b[i]]+x)%n!=num[c[i]])
      return false;
    x=(num[a[i]]+num[b[i]]+x)/n;
  }
  return true;
}

bool CanPrune()  //��֦
{
  if(num[a[0]]+num[b[0]]>=n)     //��λ���ܽ�λ
    return true;
  for(int i=n-1; i>=0; i--)
  {
    int A=num[a[i]],B=num[b[i]],C=num[c[i]];
    if(A==-1||B==-1||C==-1)      //���û����ֵ,����
      continue;
    if((A+B)%n!=C &&(A+B+1)%n!=C)//��λֻ��1���ֿ���
      return true;
  }
  return false;
}

void DFS(int x)
{
  if(CanPrune()) return;
  if(x==n && Judge())
  {
    for(int i=0; i<n; i++)
      printf("%d%c",num[i],i==n-1?'\n':' ');
    exit(0);
  }
  for(int i=n-1; i>=0; i--)
    if(!used[i])
    {
      num[Next[x]]=i;
      used[i]=true;
      DFS(x+1);
      num[Next[x]]=-1;
      used[i]=false;
    }
}

void GetNext(int x)
{
  if(used[x]==false)
  {
    used[x]=true;
    Next[cnt++]=x;
  }
}

int main()
{
  //freopen("alpha.in","r",stdin);
  //freopen("alpha.out","w",stdout);
  char s1[N],s2[N],s3[N];
  scanf("%d %s %s %s",&n,s1,s2,s3);
  for(int i=0; i<n; i++)
  {
    a[i]=s1[i]-'A';
    b[i]=s2[i]-'A';
    c[i]=s3[i]-'A';
  }
  for(int i=n-1; i>=0; i--)     //�Ӵ�С��ֵ������ٶ�
  {
    GetNext(a[i]);              //����ʼֵ
    GetNext(b[i]);
    GetNext(c[i]);
  }
  memset(used,0,sizeof(used));  //��ǰ�ַ���δʹ��
  memset(num,-1,sizeof(num));   //��ʾ��ǰ����δȷ��
  DFS(0);
  return 0;
}

