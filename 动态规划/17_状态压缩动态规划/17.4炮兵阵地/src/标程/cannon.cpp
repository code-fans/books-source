//�ڱ����
#include<bits/stdc++.h>
using namespace std;

struct st
{
  int state, num;
} s[105];
int Line[105], dp[105][105][105];

inline int Getnum(int x,int t=0)       //����xת�����������ж���1
{
  for(; x>0; t++)
    x=x&(x-1);
  return t;
}

int main()
{
  freopen("cannon.in","r",stdin);
  freopen("cannon.out","w",stdout);
  int n, m, cnt=0,ans=0;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    {
      char c;
      cin>>c;
      Line[i]=(Line[i]<<1)+(c=='P');   //���е��δ�Ϊ�����ƣ���ƽԭΪ1��ɽ��Ϊ0
    }
  for(int i=0; i<(1<<m); i++)          //ö��000...000~111...111���п��ܷ���
  {
    if(i&(i<<1) || i&(i<<2) || i&(i>>1) || i&(i>>2))//�ж�һ���Ƿ����ҳ�ͻ
      continue;
    s[++cnt].state = i;             //���δ����״̬,����ɢ����ɲ��ù��������Ż�
    s[cnt].num=Getnum(i);              //ͳ�Ƹ�״̬���ڱ�������
    if((i & Line[1]) == i)             //�����״̬�ɷ��ڵ�һ��
      dp[1][0][cnt] = s[cnt].num;      //��һ�ж����ʼ��
  }
  for(int i = 1; i <= cnt; i++)        //�ڶ��ж����ʼ��
    for(int j = 1; j <= cnt; j++)
      if(!(s[i].state & s[j].state) && (Line[2] & s[j].state)==s[j].state)
        dp[2][i][j] = dp[1][0][i]+s[j].num;
  for(int i = 3; i <= n; i++)          //�ӵ����п�ʼ����
    for(int a = 1; a <= cnt; a++)
      if((Line[i] & s[a].state) == s[a].state)//a״̬�ɷ��ڵ�i��
        for(int b = 1; b <= cnt; b++)
          if(!(s[a].state & s[b].state))//a,b״̬����ͻ
            for(int c = 1; c <= cnt; c++)
              if(!(s[b].state & s[c].state) && !(s[a].state & s[c].state))
                dp[i][b][a]=max(dp[i][b][a], dp[i-1][c][b]+s[a].num);
  for(int i=1; i<=cnt; i++)
    for(int j=1; j<=cnt; j++)
      ans=max(ans, dp[n][i][j]);
  printf("%d\n", ans);
  return 0;
}

