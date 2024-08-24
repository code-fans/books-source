//Ψһ���· ����С������1
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10001;

int n,m,del;                           //delΪɾ���ıߵ��±�
int dad[110];                          //���鼯����,��μ����鼯һ��
bool flag[MAXN];                       //���ĳ�����Ƿ�����С��������
struct data
{
  int x,y,w;
} edge[MAXN];                          //��¼�ߵ������յ㣬����Ȩֵ

int Cmp(data a,data b)
{
  return a.w<b.w;
}

int FindFather(int x)                  //Ѱ�Ҹ���㲢·��ѹ��
{
  return dad[x]==x?x:dad[x]=FindFather(dad[x]);
}

int Kruskal()
{
  int ans=0,count=0,index=0;
  for(int i=1; i<=n; i++)
    dad[i]=i;                         //���鼯��ʼ��
  while(count<n-1)                    //��û�������С��ʱ
  {
    index++;                          //index��1��ʼ
    if(index!=del)                    //����kruskalʱ��del=0,���Բ��ᴥ���ж�
    {
      int x=FindFather(edge[index].x);//Ѱ�Ҹ����
      int y=FindFather(edge[index].y);
      if(x!=y)
      {
        count++;
        ans+=edge[index].w;
        dad[x]=dad[y];                //�ϲ�����
        if(del==0)                    //��һ��������С��ʱ
          flag[index]=1;              //��Ǹñ�����С��������
      }
    }
  }
  return ans;
}

int main()
{
  freopen("OnePath.in","r",stdin);
  freopen("OnePath.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
    scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
  sort(edge+1,edge+1+m,Cmp);          //̰�ģ����򣬰�Ȩֵ
  memset(flag,0,sizeof(flag));        //��ʼ��Ϊδ��ʹ�ù�
  int ans=Kruskal();
  if(m==n-1)                          //Ψһ��С��������ֱ��������
  {
    printf("%d\n",ans);
    return 0;
  }
  for(int t=1; t<=n-1; t++)           //����n-1��ɾ�ߵĲ���
    for(int i=++del; i<=m; i++)       //Ѱ����һ��ɾ���ı�
      if(flag[i])                     //����ñ�����С��������
      {
        del=i;                        //ȷ����һ��Ҫɾ���ı�
        if(Kruskal()==ans)            //���ɴ�С��С�����Һ���С��������ֵ
        {
          printf("Not Unique!\n");
          exit(0);
        }
      }
  printf("%d\n",ans);
  return 0;
}

