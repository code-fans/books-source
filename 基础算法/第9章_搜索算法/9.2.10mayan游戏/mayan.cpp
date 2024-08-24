//Mayan��Ϸ
#include <bits/stdc++.h>
using namespace std;

struct T
{
  short x,y,ops;             //ops��ǲ���
} ans[10];
short st[6][8];
int n;

void Down()                //ģ������Ĺ���
{
  for (short i=0; i<5; i++)  //����
    for (short h=1; h<7; h++)//���д��µ���
      if(st[i][h])         //�����������ɫ
        for(short H=h; H-1>=0 && !st[i][H-1]; H--)//�����ǿյľ�������
          swap(st[i][H],st[i][H-1]);
}

bool Clear(short flag=0)//�����
{
  int del[6][8]= {0};
  for(short i=0; i<5; i++)
    for(short j=0; j<7; j++)
    {
      if(st[i][j] && i-1>=0 && i+1<5 &&st[i][j]==st[i-1][j] && st[i][j]==st[i+1][j])
        del[i-1][j]=del[i+1][j]=del[i][j]=flag=1;
      if(st[i][j] && j-1>=0 && j+1<7 &&st[i][j]==st[i][j+1] && st[i][j]==st[i][j-1])
        del[i][j]=del[i][j+1]=del[i][j-1]=flag=1;
    }
  if(!flag) return flag;
  for(short i=0; i<5; i++)
    for(short h=0; h<7; h++)
      if(del[i][h])
        st[i][h]=0;
  return flag;
}

void DFS(int step)
{
  if(step > n)
  {
    if(st[0][0]+st[1][0]+st[2][0]+st[3][0]+st[4][0]==0)
    {
      for(short i = 1; i <= n; i++)
        printf("%d %d %d\n",ans[i].x+ans[i].ops,ans[i].y,ans[i].ops?-1:1);
      exit(0);
    }
    return;
  }
  for(short x = 0; x < 4; x++)
    for(short y = 0; y < 7; y++)
      if(st[x][y] != st[x+1][y])    //��ɫ��ͬ�ľͲ��ý�����
      {
        ans[step].x = x;
        ans[step].y = y;
        ans[step].ops = (!st[x][y]);//�����ǰ��һ���ǿյĻ�����ô�Ͱ����ұ���һ�����ƣ������˷��������
        int temp[6][8];
        memcpy(temp,st,sizeof temp);//���浱ǰ״̬
        swap(st[x][y],st[x+1][y]);
        for(Down(); Clear(); Down());//����֮����ܲ���������Ӧ������ѭ��
        DFS(step+1);//��������
        memcpy(st,temp,sizeof st);//�˴��ָ�������ôд���޷��ָ�
      }
}

int main()
{
  //freopen("mayan.in","r",stdin);
  //freopen("mayan.out","w",stdout);
  scanf("%d",&n);
  for(short i = 0; i < 5; i++)//ö����
    for(short h=0; scanf("%d",&st[i][h]) && st[i][h]; h++);//ö����
  DFS(1);
  printf("-1\n");
  return 0;
}

