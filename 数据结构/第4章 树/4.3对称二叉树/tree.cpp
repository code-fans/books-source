//�Գƶ�����
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;

int lson[MAXN],rson[MAXN],m,node[MAXN],ans=1;
bool OK=1;//��ǽṹ�Ƿ�Գ�

inline int Read()                         //���ٶ�������
{
  int x=0,f=1;
  char ch=getchar();
  for(; ch<'0' || ch>'9'; ch=getchar())   //getchar��scanf��Լ��ʮ��
    if(ch=='-')
      f=-1;
  for(; ch>='0' && ch<='9'; ch=getchar())
    x=(x<<3)+(x<<1)+ch-'0';               //λ�����Ż���x*8+x*2=x*10
  return x*f;
}

int Dfs(int x,int y,int s)//�ҶԳƶ����� s����ڵ��� x,yΪ���ڷ��ʵĽڵ���
{
  if((x==-1 && y==-1)) //�ж��Ƿ��нڵ�
    return 0;
  if((x==-1||y==-1)  || node[x]!=node[y])//�ж��Ƿ�Գ�
  {
    OK=0;
    return 0;
  }
  return Dfs(lson[x],rson[y],2)+Dfs(rson[x],lson[y],2)+s; //�ݹ飺����ֵΪ�ڵ���
}

int main()
{
  //freopen("tree.in","r",stdin);
  //freopen("tree.out","w",stdout);
  m=Read();
  for(int i=1; i<=m; i++)
    node[i]=Read();
  for(int i=1; i<=m; i++)
    lson[i]=Read(),rson[i]=Read();
  for(int i=1; i<=m; i++)
  {
    int sum=Dfs(lson[i],rson[i],3);//ֱ�Ӵ����Ӻ��Һ��ӿ�ʼ,���Գ�ʼ�ڵ�Ϊ����
    if(sum>ans && OK)
      ans=sum;
    OK=1;
  }
  cout<<ans<<endl;
  return 0;
}

