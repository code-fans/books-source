//���鱳�����⣬˼·�ǰ�ÿһ�鿴��һ����Ʒ��ת��Ϊ01������
//����ѭ��������������㣬ö���������м�㣬ĳ����Ʒö�������ڲ�
//����Ա�֤һ������Ҫôѡһ��Ҫô��ѡ��
//��Ϊ������ͨ��ö����Ʒ��������ת�ƣ������ǲ���ģ��������Ʒ��Ʒ�֣�
//���ң�����ֻ��ת��һ�����Ծͱ�֤�˷��鱳����ԭ��
#include <bits/stdc++.h>
using namespace std;

int stone[1001],w[1001],f[1001],ID[101][1001];

int main()
{
  freopen("kbag.in","r",stdin);
  freopen("kbag.out","w",stdout);
  int m,n,K;
  scanf("%d%d",&m,&n);
  for(int i=1,c; i<=n; i++)
  {
    scanf("%d%d%d",&stone[i],&w[i],&c);
    ID[c][++ID[c][0]]=i;               //ID[c][x]����c���x��ʯͷ�ı��
    K=max(K,c);                        //Kȷ������ж�����
  }
  for(int k=1; k<=K; k++)              //ö�����,����ѭ��������
    for(int j=m; j>=0; j--)            //����������ѭ��,��ö��k����Ʒ֮��
      for(int i=1; i<=ID[k][0]; i++)   //ö��k��������Ʒ
        if(stone[ID[k][i]]<=j)         //������Է�
          f[j]=max(f[j],f[j-stone[ID[k][i]]]+w[ID[k][i]]);
  printf("%d\n",f[m]);
  return 0;
}

