//�����С��
#include<bits/stdc++.h>
using namespace std;
#define N 10005

int n,m,k,x[N],y[N],low[N],high[N],f[N][2005];
bool flag[N];

int main()
{
  freopen("bird.in","r",stdin);
  freopen("bird.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  for (int i=1; i<=n; i++)
    scanf("%d%d",&x[i],&y[i]);
  for (int i=1; i<=n; i++)
  {
    high[i]=m;    //��ʼ����ܵ�m
    low[i]=1;     //��ʼ����ܵ�1
  }
  for (int i=1,P,L,H; i<=k; i++)
  {
    scanf("%d%d%d",&P,&L,&H);
    flag[P]=1;
    low[P]=L+1;   //ע�����ظ߶�Ҫ��1
    high[P]=H-1;  //ע�����ظ߶�Ҫ��1
  }
  memset(f,0x3f3f3f,sizeof(f));
  for (int i=1; i<=m; i++)
    f[0][i]=0;
  for (int i=1; i<=n; i++)            //���ҳ���
  {
    for (int j=x[i]+1; j<=x[i]+m; j++)//������һ��,��ȫ����
      f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);//ǰһ��λ����������
    for (int j=m+1; j<=x[i]+m; j++)   //�ɳ����컨����������
      f[i][m]=min(f[i][m],f[i][j]);
    for (int j=1; j<=m-y[i]; j++)     //�½���һ��
      f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
    for (int j=1; j<low[i]; j++)      //�����޷�ͨ���ĵط�
      f[i][j]=0x3f3f3f;
    for (int j=high[i]+1; j<=m; j++)
      f[i][j]=0x3f3f3f;
  }
  int ans=0x3f3f3f;
  for (int i=1; i<=m; i++)
    ans=min(ans,f[n][i]);
  if (ans<0x3f3f3f)                   //����ͨ����ֱ�������
    printf("1\n%d\n",ans);
  else
  {
    ans=0;
    for(int i = 1 ; i <= n ; ++ i)
      for(int j = 1 ; j <= m ; ++ j)
        if(flag[i] && f[i][j] < 0x3f3f3f )
        {
          ans++;
          break;
        }
    printf("0\n%d\n",ans);
  }
  return 0;
}
//��f[i][j]��ʾ������Ϊiʱ�߶�Ϊj�����ٵ��������
//������������ʾ�����ܴﵽ���״̬��
//�������ǿ��Է�����״̬ת�Ƶķ�ʽ��
//����������ȫ����ת�Ʒ�ʽ
//�½�����01����ת�Ʒ�ʽ
//����m��Ϊm��������
//����Ҳ�����������������Ż���ɹ�ȫ������
