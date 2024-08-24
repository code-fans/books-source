/*  ���ಢ�鼯+��ɢ��
����������ֻ�� 0��1����ôʹ�ȿ�һ��s�����ʾǰ׺�ͣ���ô��
s[j]-s[i-1]������ʱ���� [i..j]�����е�1�ĸ���Ϊ��������֮��Ϊż��
��������[l,r]�����˵[l,r][l,r]��������1����ôsum{l-1}��sum r��ǰ׺����ż�Աض�����ȡ�
ż��ͬ��
���Է�Ϊ��ż��������,
ÿ����һ���ش��������жϵ�ǰ��������˵����ż�ԣ�
�ٶ��ڡ�even���ش�����˵����Ҷ˵㡰���ˡ��ļ����л��Ҷ˵�����˵㡰���ˡ��ļ����У���ش����
�ڶ��ڡ�odd���ش�����˵����Ҷ˵㡰���ѡ��ļ����л��Ҷ˵�����˵㡰���ѡ��ļ����У���ش����
����ش�����ȷ�ģ������Ǿͽ��кϲ�������
�ٶ��ڡ�even�������ǽ���˵���Ҷ˵�ġ����ѡ��������ˡ����Ϸֱ�ϲ�
�ڶ��ڡ�odd�������ǽ���˵�ġ����ѡ����Ҷ˵�ġ����ˡ��ϲ�������˵�ġ����ˡ����Ҷ˵�ġ����ѡ��ϲ�
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,tot,b[100010],father[100010];

struct node
{
  int u,v;
  string op;
} a[100010];

inline int Find(int x)
{
  return father[x]==x?x:father[x]=Find(father[x]);
}

int main()
{
  freopen("parity.in","r",stdin);
  freopen("parity.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
  {
    cin>>a[i].u>>a[i].v>>a[i].op;
    b[++tot]=a[i].u;                //��ɢ����׼��
    b[++tot]=a[i].v;
  }
  sort(b+1,b+1+tot);                            //STLʵ����ɢ����������
  int size=unique(b+1,b+1+tot)-(b+1);           //unique�������һ��Ԫ�ص�ַ
  for(int i=1; i<=m; i++)
  {
    a[i].u=lower_bound(b+1,b+1+size,a[i].u-1)-b;//�ҵ�����λ��
    a[i].v=lower_bound(b+1,b+1+size,a[i].v)-b;
  }
  for(int i=size<<1; i>=1; i--)                 //�������鼯
    father[i]=i;
  for(int i=1; i<=m; i++)
    if(a[i].op=="even")                         //����ش���ż����
    {
      if(Find(a[i].u)==Find(a[i].v+size) || Find(a[i].u+size)==Find(a[i].v))//�ж���ż��
      {
        printf("%d\n",i-1);
        return 0;
      }
      father[Find(a[i].u)]=Find(a[i].v);
      father[Find(a[i].u+size)]=Find(a[i].v+size);
    }
    else
    {
      if(Find(a[i].u)==Find(a[i].v) || Find(a[i].u+size)==Find(a[i].v+size))
      {
        printf("%d\n",i-1);
        return 0;
      }
      father[Find(a[i].u)]=Find(a[i].v+size);
      father[Find(a[i].u+size)]=Find(a[i].v);
    }
  printf("%d\n",m);
  return 0;
}
