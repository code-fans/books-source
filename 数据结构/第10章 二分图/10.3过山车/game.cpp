//��ɽ��
#include<bits/stdc++.h>
using namespace std;
#define N 510
int n,m,k;
bool Graphi[N][N];
int Boy[N],Girl[N];            //Boy[x]=y��ʾ��x��Ůy��Giry[x]=y��ʾŮx����y
int pre[N],visit[N];           //pre[]����һ���,visit[x]=y��ʾŮx����y���ʹ�

int FindMatch(int iBoy)
{
  queue<int> q;
  q.push(iBoy);                    //����iBoy�����
  pre[iBoy]=-1;
  bool flag=0;
  while(!q.empty()&&!flag)         //�����в�Ϊ�ղ���δ�ҵ�ƥ��ʱ
  {
    int boy=q.front();             //ȡ����������
    q.pop();
    for(int girl=1; girl<=m && !flag; girl++) //δ�ҵ�ƥ��ʱ��ö������Ů��
      if(Graphi[boy][girl]&&visit[girl]!=iBoy)//�����Ů��������δ��iboy���ʹ�
      {
        visit[girl]=iBoy;          //���girlΪ�ѷ���
        q.push(Girl[girl]);        //��girl����������˶�Ա����У�����Ϊ-1��
        if(Girl[girl]>=0)          //��û������·��,�ͻص�ѭ��ö���¸�Ů��
          pre[Girl[girl]]=boy;     //���λ���Ա������Ƹ��Ľ����״̬
        else                       //���������·
        {
          flag=1;
          int bb=boy,gg=girl;
          while(bb!=-1)            //���ƣ����Ľ�����״̬
          {
            int t=Boy[bb];
            Boy[bb]=gg,Girl[gg]=bb;
            bb=pre[bb],gg=t;
          }
        }
      }
  }
  return Boy[iBoy]!=-1;
}

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  while(~scanf("%d",&k) && k)
  {
    memset(Boy,-1,sizeof(Boy));
    memset(Girl,-1,sizeof(Girl));
    memset(visit,-1,sizeof(visit));
    memset(Graphi,0,sizeof(Graphi));
    scanf("%d%d",&n,&m);
    int a,b;
    while(k--)
    {
      scanf("%d%d",&a,&b);
      Graphi[a][b]=1;
    }
    int ans=0;
    for(int i=1; i<=n; i++)        //ö��ÿ������i
      if(Boy[i] == -1)             //�����iû��ƥ��
        if(FindMatch(i))           //�����i����һ������·��
          ans++;                   //ƥ����++
    printf("%d\n",ans);
  }
  return 0;
}

