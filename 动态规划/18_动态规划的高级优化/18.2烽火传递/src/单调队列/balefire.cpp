//��𴫵�
#include <bits/stdc++.h>
using namespace std;

int head,tail;                          //����ָ��Ͷ�βָ��
int q[1000010],w[1000010],f[1000010];   //����ģ����У�Ҳ����STL������

int main()
{
  //freopen("balefire.in","r",stdin);
  //freopen("balefire.out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  for (int i=1; i<=n; ++i)
    scanf("%d",&w[i]);
  for (int i=1; i<=n; ++i)
  {
    while (q[head]<i-m && head<=tail)    //ά�������С�������в�Ϊ��ʱ
      head++;                            //����ָ����ƣ�������Ԫ�س���
    f[i]=f[q[head]]+w[i];                //ȡ��Сֵ�������׵�Ԫ��ֵ
    while (f[q[tail]]>f[i] && head<=tail)//ά��������
      tail--;                            //��β����Ӱ�쵥���Ե�ֵ
    q[++tail]=i;                         //���̨������
  }
  int ans=0x7fffffff;
  for (int i=n-m+1; i<=n; ++i)
    ans=min(ans,f[i]);
  printf("%d\n",ans);
}

