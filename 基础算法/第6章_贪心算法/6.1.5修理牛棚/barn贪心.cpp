//����ţ��
//̰���㷨����Ȼ��������ľ�������ʱ��������̡�����m��ľ��ʱ��m-1����϶��
//���ڵ�Ŀ�������ܼ�϶��󡣽�����������ţ��ţ��֮������ţ��������
//ѡȡ����m-1����Ϊ��϶������ط���ľ���ס���ɡ�
//���ܳ��ȼ�ȥm-1����󳤶ȵĿհ�
#include<bits/stdc++.h>
using namespace std;

int cow[210],gap[210];

int main()
{
  freopen("barn.in","r",stdin);
  freopen("barn.out","w",stdout);
  int m,s,c;
  scanf("%d%d%d",&m,&s,&c);     //m:ľ�������Ŀ,s:ţ������,c:ţ������
  for (int i=1; i<=c; i++)
    scanf("%d",&cow[i]);
  sort(cow+1,cow+c+1);          //����Ŵ������ź�ţ��
  int ans=cow[c]-cow[1]+1;      //ȫ�������ܳ���
  for (int i=1; i<=c-1; i++)
    gap[i]=cow[i+1]-cow[i]-1;     //�����϶�ĳ���
  sort(gap+1,gap+c);
  for (int i=c-1; i>=c-m+1; i--)//�����Ŀ�϶��ʼ����m-1��
    ans-=gap[i];
  printf("%d\n",ans);
  return 0;
}
