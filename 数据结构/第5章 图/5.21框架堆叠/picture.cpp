//框架堆叠
#include <bits/stdc++.h>
using namespace std;
const int MAXN=50;

int LL[MAXN],RR[MAXN],Up[MAXN],Dn[MAXN],ind[MAXN],ans[MAXN],h,w,n=0;
bool Use[MAXN],Line[MAXN][MAXN],visited[MAXN];
char Map[MAXN][MAXN];

void Dfs(int x,int d)
{
  ans[d]=x;
  visited[x]=true;
  if(d>=n)
  {
    for(int i=1; i<=n; i++)
      printf("%c",ans[i]+'A'-1);
    printf("\n");
  }
  else if(ind[x]==0)
  {
    for(int i=1; i<=26; i++)
      if(Line[x][i])
        ind[i]--;
    for(int i=1; i<=26; i++)
      if(ind[i]==0 && !visited[i] && Use[i])
      {
        Dfs(i,d+1);
        visited[i]=false;
      }
    for(int i=1; i<=26; i++)             //恢复
      if(Line[x][i])
        ind[i]++;
  }
}

void MakeTopo(int alph,int tmp)          //创建拓扑关系
{
  if(!Line[alph][tmp] && tmp!=alph)
  {
    ind[tmp]++;                          //入度加1
    Line[alph][tmp]=true;                //alph被tmp1覆盖
  }
}

int main()
{
  //freopen("picture.in","r",stdin);
  //freopen("picture.out","w",stdout);
  scanf("%d%d\n",&h,&w);
  for(int i=1; i<=h; i++)
    scanf("%s",&Map[i][1]);
  for(int i=1; i<=h; i++)
    for(int j=1; j<=w; j++)
    {
      if(Map[i][j]=='.')
        continue;
      int alph=Map[i][j]-'A'+1;
      if(!Use[alph])
        n++;
      Up[alph]=(Up[alph]==0 ? i : min(Up[alph],i));//字母alph上界
      Dn[alph]=(Dn[alph]==0 ? i : max(Dn[alph],i));//字母alph下界
      LL[alph]=(LL[alph]==0 ? j : min(LL[alph],j));//字母alph左界
      RR[alph]=(RR[alph]==0 ? j : max(RR[alph],j));//字母alph右界
      Use[alph]=true;
    }
  for(int alph=1; alph<=26; alph++)
  {
    for(int j=LL[alph]; j<=RR[alph]; j++)     //扫描方框的两个横行上的字母
    {
      if(!Use[alph] || Map[Up[alph]][j]=='.' || Map[Dn[alph]][j]=='.')
        continue;
      MakeTopo(alph,Map[Up[alph]][j]-'A'+1);  //创建拓扑关系
      MakeTopo(alph,Map[Dn[alph]][j]-'A'+1);  //左右看上下
    }
    for(int j=Up[alph]; j<=Dn[alph]; j++)     //扫描方框的两个纵列上的字母
    {
      if(!Use[alph] || Map[j][LL[alph]]=='.' || Map[j][RR[alph]]=='.')
        continue;
      MakeTopo(alph,Map[j][LL[alph]]-'A'+1);  //创建拓扑关系
      MakeTopo(alph,Map[j][RR[alph]]-'A'+1);  //上下看左右
    }
  }
  for(int i=1; i<=26; i++)                    //拓扑排序
  {
    memset(visited,0,sizeof(visited));
    if(Use[i])                                //因为有多种组合
      Dfs(i,1);                               //所以DFS
  }
  return 0;
}
