//��ţ�����ˡ�Multiset�Ż�
#include <bits/stdc++.h>
using namespace std;

int GCD(int m,int n)
{
  return n==0?m:GCD(n,m%n);
}

inline int Read(int x=0)                 //���ַ�����ʽ�������ֿ�����
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
  return x;
}

int main()
{
  freopen("poorcow.in","r",stdin);
  freopen("poorcow.out","w",stdout);
  int n,T=Read();
  while(T--)
  {
    cin>>n;
    multiset <pair<int ,int> >cow[11][11];//pair�����������ţ�ı��
    int Milk[1001][11]= {0};
    int Zq[11]= {0};               //Zq[i]��ʾ������Ϊi��ţ
    for(int i=1,zq; i<=n; i++)
    {
      zq=Read();
      Zq[zq]=1;//��ʾ�������
      for(int j=1,m; j<=zq; j++)
      {
        Milk[i][j]=Read();
        cow[zq][j].insert(make_pair(Milk[i][j],i));
      }
    }
    int count=1;
    for(int i=1; i<10; i++)       //���������ڵ���С������
      if(Zq[i])                   //������������
        count=count*i/GCD(count,i);
    int last = 0, cnt = n;
    count<<=1;                    //����Ϊ��������С������
    for(int k=1; k<=count && cnt!=0; k++)
    {
      int Minpos = -1,MinI=-1, Min = 0x7FFFFFFF;
      for(int i=1; i<=10; i++)    //ö��10�����ڵ�ţȺ
      {
        int j=(k-1)%i+1;
        if(Zq[i] && cow[i][j].size()>0)
        {
          multiset<pair<int ,int> >::iterator ii=cow[i][j].begin();
          if((*ii).first<Min )    //�������ٲ�������ţ
          {
            Minpos=(*ii).second;//���
            Min=(*ii).first;//����
            MinI=i;//����
            if(cow[i][j].size()>1) //ͬ���ڵ�ţȺ�У����ٲ�������ͬ�Ŀ����ж�ͷ
            {
              ii++;
              if((*ii).first==Min)
                Minpos=-1;
            }
          }
          else if((*ii).first==Min)//�������ڵ�ţȺ������ͬ���ٲ�������ţ
            Minpos=-1;
        }
      }
      if(Minpos!=-1)               //�ҵ��˵�����������ٵ�Ψһһͷţ
      {
        last=k;
        for(int i=1; i<=MinI; i++) //ɾ���������ٵ�ţ
          cow[MinI][i].erase(cow[MinI][i].find(make_pair(Milk[Minpos][i],Minpos)));
        cnt--;
      }
    }
    printf("%d %d\n", cnt,last);
  }
  return 0;
}

