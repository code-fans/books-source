//�ɶԵ�
#include<bits/stdc++.h>
using namespace std;

int result[110],lamp[110];
set<string> ans;

int main()
{
  //freopen("lamps.in","r",stdin);
  //freopen("lamps.out","w",stdout);
  int n,C;
  scanf("%d%d",&n,&C);
  memset(result,-1,sizeof(result));
  for(int k; scanf("%d",&k) && k!=-1; result[k]=1);//��������ŵƵ�״̬
  for(int k; scanf("%d",&k) && k!=-1; result[k]=0);//���������ŵƵ�״̬
  for(int key1=0; key1<=1; key1++)        //Ҫô������Ҫô��һ�Σ���ż���ε���û��
    for(int key2=0; key2<=1; key2++)
      for(int key3=0; key3<=1; key3++)
        for(int key4=0,t; key4<=1; key4++) //ö��ÿһ��ѡ��
          if((key1+key2+key3+key4)%2==C%2 && key1+key2+key3+key4<=C)//��ż�Բ�ͬ��һ��������c
          {
            //�Ҳ��������Ҳû��ϵ��set��ȥ��
            for(t=1; t<=n; t++)           //��ʼ���еƶ���
              lamp[t]=1;
            if(key1)                      //��ť1
              for(t=1; t<=n; t++)         //���Ƶ��Ⱥ�˳���޹ؽ��
                lamp[t]=1-lamp[t];
            if(key2)                      //��ť2
              for(t=1; t<=n; t+=2)
                lamp[t]=1-lamp[t];
            if(key3)                      //��ť3
              for(t=2; t<=n; t+=2)
                lamp[t]=1-lamp[t];
            if(key4)                      //��ť4
              for(t=1; t<=n; t+=3)
                lamp[t]=1-lamp[t];
            for(t=1; t<=n; t++)       //�Ƚ�
              if((lamp[t]!=result[t]) && result[t]!=-1)
                break;
            if(t>n)                      //�ɹ�����ӵ�set��
            {
              string temp;
              for(int t=1; t<=n; t++)
                temp+=lamp[t]+'0';
              ans.insert(temp);           //���Զ�����
            }
          }
  if(ans.empty())
    printf("IMPOSSIBLE\n");
  else
    for(set<string>::iterator it = ans.begin(); it != ans.end(); it++)
      cout << *it << endl;//��������6��һѭ�������Ի������Ż�
  return 0;
}
