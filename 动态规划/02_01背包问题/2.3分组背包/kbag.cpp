//���鱳�����⣬˼·�ǰ�ÿһ�鿴��һ����Ʒ��ת��Ϊ01������
//����ѭ��������������㣬ö���������м�㣬ĳ����Ʒö�������ڲ�
//����Ա�֤һ������Ҫôѡһ��Ҫô��ѡ��
//��Ϊ������ͨ��ö����Ʒ��������ת�ƣ������ǲ���ģ��������Ʒ��Ʒ�֣�
//���ң�����ֻ��ת��һ�����Ծͱ�֤�˷��鱳����ԭ��
#include <bits/stdc++.h>
using namespace std;

int m,n,p,K;
int w[10001],c[10001],f[10001],stone[10001][1001];

int main()
{
  freopen("kbag.in","r",stdin);
  freopen("kbag.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d%d%d",&w[i],&c[i],&p);
    stone[p][++stone[p][0]]=i;
    K=max(K,p);                          //ͳ������ж�����
  }
  for(int k=1; k<=K; k++)                //ö������
    for(int j=m; j>=0; j--)              //����ö�ٱ�������
      for(int i=1; i<=stone[k][0]; i++)  //ö��k�����������Ʒ
        if(w[stone[k][i]]<=j)            //������Է�
          f[j]=max(f[j],f[j-w[stone[k][i]]]+c[stone[k][i]]);
  printf("%d\n",f[m]);
}
