//����ѡ�Σ����鱳��
#include <bits/stdc++.h>
using namespace std;

int w[110][110],f[110];
int n,m;

int main()
{
  //freopen("course.in","r",stdin);
  //freopen("course.out","w",stdout);
  while(scanf("%d %d",&n,&m) && n && m)
  {
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        scanf("%d",&w[i][j]);
    memset(f,0,sizeof(f));
    for(int i = 1; i <= n; i++)          //ö�����������
      for(int j = m; j >= 0; j--)        //����ö�ٿγ�
        for(int k = 1; k <= j; k++)      //ö��ѧϰ����
          f[j] =max(f[j],f[j-k]+w[i][k]);
    printf("%d\n",f[m]);
  }
  return 0;
}

