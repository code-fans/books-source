//�ڰ�Ϳɫ-������㷨
#include <bits/stdc++.h>
using namespace std;

int Edg[110][110],Set[505],tmp[505];
int n,m,cnt,maxx;

void dfs(int x)
{
  if(x>n)                                       // ���ö�������еĽ��
  {
    maxx=cnt;
    memcpy(Set,tmp,sizeof(tmp));   //��һ������ļ��������ԭ�еļ�����
    return;
  }
  bool flag=true;
  for(int i=1; i<x; i++)//����¼���ĵ��Ƿ����е�������㶼����һ����
    if(tmp[i] && !Edg[i][x])              //���i�������У�������û�б�
    {
      flag=false;
      break;
    }

  if(flag)                              //����ý���������������
  {
    tmp[x]=1,cnt++;                     //�ý�㱻���뵽��ȫ��ͼ��ȥ
    dfs(x+1);
    tmp[x]=0,cnt--;                     //�ָ�ԭֵ
  }
  if (cnt+n-x>maxx)                     //���򲻼���x����֦,��֤��Ԫ�ظ�������
    dfs(x+1);
}

int main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    memset(Set,0,sizeof(Set));
    memset(tmp,0,sizeof(tmp));
    maxx=cnt=0;
    for(int i=0; i<110; i++)
      fill(Edg[i],Edg[i]+110,1);        //��ÿһ������Ԫ��ȫ�����Ϊ1
    for(int i=1; i<=m; i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      Edg[a][b]= Edg[b][a]=0;           //������ͼ
    }
    dfs(1);                             //�ӽ��1��ʼ����
    printf("%d\n",maxx);
    for(int i=1,k=0; i<=n; i++)
      if(Set[i])
        k++==0? printf("%d",i):printf(" %d",i);
    printf("\n");
  }
  return 0;
}

