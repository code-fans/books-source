//�ɶԵ�
//ÿ�����ذ�ż���ε�ʱ���൱��û��
#include<bits/stdc++.h>
using namespace std;

int flag[7],n,c,OK;
int state[9][7]=
{
  0,0,0,0,0,0,0,//���ź���
  1,0,0,0,0,0,0,
  2,0,0,1,1,1,0,
  1,0,1,0,1,0,1,
  1,0,1,1,0,1,1,
  2,1,0,0,1,0,0,
  1,1,0,1,0,1,0,
  2,1,1,0,0,0,1,
  0,1,1,1,1,1,1,
};//ѭ������6�������ܴﵽ��ֻ��8����ʽ,��һ�б���ﵽ��״̬��Ҫ�Ĳ���

int Loc(int x)//ӳ��Ϊ6��һѭ����λ��
{
  return (x%6==0?6:x%6);
}

int Check(int s)
{
  if (state[s][0]>c) return 0;//��������
  if (c==2 && s==4) return 0;//2�����ﲻ��011011״̬
  if (c==3 && ((s==2)||(s==5)||(s==7))) return 0;//3�����ﲻ��001110/100100/110001
  if (c==1 && s==8) return 0;//1�����ﲻ��111111״̬
  for (int i=1; i<=6; i++)
  {
    if (flag[i]==-1) continue;//״̬û�б䣬����
    if (state[s][i]!=flag[i]) return 0;
  }
  return 1;
}

int main()
{
  freopen("lamps.in","r",stdin);
  freopen("lamps.out","w",stdout);
  memset(flag,-1,sizeof(flag));
  scanf("%d%d",&n,&c);
  for(int k; scanf("%d",&k) && k!=-1; flag[Loc(k)]=1);
  for(int k; scanf("%d",&k) && k!=-1; flag[Loc(k)]=0);
  for (int i=1; i<=8; i++)//���8��״̬
    if (Check(i))
    {
      for (int j=1; j<=n; j++)
        printf("%d",state[i][Loc(j)]);
      printf("\n");
      OK=1;
    }
  if (!OK) printf("IMPOSSIBLE\n");
  return 0;
}
