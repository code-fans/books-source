//��������
#include<bits/stdc++.h>
using namespace std;

int m,n;
int f[11][16],value[11][16];

void Show(int x,int num)    //������x����˾��ʣnum̨����û����
{
  if (x==0)
    return;
  for (int i=0; i<=num; i++)//�����ж����Ž��Ƿ���i������
    if (f[x][num]==f[x-1][i]+value[x][num-i])
    {
      Show(x-1,i);
      cout<<x<<' '<<num-i<<endl;
      break;                    //���һ������˳����Է����������
    }
}

int main()
{
  freopen("machine.in","r",stdin);
  freopen("machine.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      scanf("%d",&value[i][j]);
  for(int i=1; i<=n; i++)              //ö�ٲ���
    for(int j=1; j<=m; j++)            //ö����Դ
      for(int k=0; k<=j; k++)          //ö���и��
        f[i][j]=max(f[i-1][k]+value[i][j-k],f[i][j]);
  printf("%d\n",f[n][m]);              //������ӯ��ֵ
  Show(n,m);                           //����������
  return 0;
}

