//����Ѳ�ӡ�DP
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#define N 1555
using namespace std;
int money[N];
int son[N][N];
int dp[N][4];
void dfs(int x)
{
  if(!son[x][0])
  {
    dp[x][1] = money[x];
    dp[x][3] = money[x];
    dp[x][2] = 0;
    return ;
  }
  else
  {
    for(int i = 1; i<=son[x][0]; i++)
    {
      dfs(son[x][i]);
    }
    for(int i = 1; i<=son[x][0]; i++)
    {
      int s = son[x][i];
      dp[x][1] += min(dp[s][2],min(dp[s][3],dp[s][1]));//�Լ�
      dp[x][2] += min(dp[s][1],dp[s][3]);//����
    }
    bool flag = 0;
    int bu = 2147438647;
    for(int i = 1; i<=son[x][0]; i++)
    {
      int s = son[x][i];
      dp[x][3] += min(dp[s][1],dp[s][3]);
      if(dp[s][3]>=dp[s][1])
      {
        flag = 1;
      }
      bu = min(bu,dp[s][1]-dp[s][3]);
    }
    if(flag==0)
    {
      dp[x][3]+=bu;
    }
  }
}
int main()
{
  //freopen("Net.in","r",stdin);
  //freopen("Net.out","w",stdout);
  int n;
  scanf("%d",&n);
  int root;
  for(int i = 1; i<=n; i++)
  {
    int num;
    scanf("%d",&num);
    if(i==1)
    {
      root = num;
    }
    scanf("%d",&money[num]);
    dp[num][1] = money[num];
    scanf("%d",&son[num][0]);
    for(int j = 1; j<=son[num][0]; j++)
    {
      scanf("%d",&son[num][j]);
    }
  }
  dfs(root);
  printf("%d\n",min(dp[root][1],dp[root][3]));
  return 0;
}

//�Ժ�������������DP��
//
//���ȶ�ά״̬��dp[i][j]��j��{1,2,3}
//
//dp[i][1]��ʾ����㱻�Լ�������
//
//dp[i][2]��ʾ����㱻����������
//
//dp[i][3]��ʾ����㱻����������
//
//��������DP������·�����ȣ�DFS��������Ҷ�ڵ㣬Ȼ�����ϸ��¡�
//
//�������㱻�Լ���������ô���Ķ��ӿ���������״̬���ȿ������Լ��������ֿ��ܱ��������������п��ܱ����Ķ���������
//
//��s������x�Ķ��ӣ����ԣ�
//
//dp[x][1] += min(dp[s][2],min(dp[s][3],dp[s][1]))��
//
//�������㱻������������ô���Ķ���ֻ���ܱ��Լ����������߱����Ķ���������
//
//dp[x][2] += min(dp[s][1],dp[s][3]);
//
//��ô�����ѵ�������㱻�Լ��Ķ�����������ô�������ж���ͬ��������״̬��
//���Լ��������߱����Ķ�����������һ������һ�����ӱ��Լ�������
//
//���������һȦ�󣬷������еĶ����Լ������Ĵ��۶�Ҫ�������ǵĶ�������
//���ǵļ�ֵ����x�Ķ���s�����ļ�ֵ����s�Ķ��������ļ�ֵ����
//������Ҫ����һ��s�Լ�������s�Ķ��������Ĳ��������ұ�֤���������С��
//
//ע������е��Լ������Լ�������ȸ���ֵ��
