//ʳ����
#include <bits/stdc++.h>
using namespace std;

int father[50005],Rank[50005];

int FindFather(int x)
{
  if(x!=father[x])
  {
    int t = father[x];
    father[x]= FindFather(father[x]);   //ѹ��·��
    Rank[x] = (Rank[x]+Rank[t])%3;      //����x��father[X]�Ĺ�ϵ
  }
  return father[x];
}

void Union(int x,int y,int d)           //�ϲ�x,y���ڵļ���
{
  int xf = FindFather(x);
  int yf = FindFather(y);
  father[xf] = yf;                      //������xf�ϲ���yf������
  Rank[xf]=(Rank[y]-Rank[x]+3+d)%3;     //���� xf ��father[xf]�Ĺ�ϵ
}

int main()
{
  freopen("food12.in","r",stdin);
  freopen("food12.ans","w",stdout);
  int total=0,n,k;
  cin>>n>>k;
  for(int i=1; i<=n; ++i)
    father[i]=i;
  while(k--)
  {
    int d,x,y;
    cin>>d>>x>>y;
    if(x>n||y>n||(d==2 && x == y))      //���x��y��n�󣬻�x��x���Ǽٻ�
      total++;                          //�ٻ�����һ
    else if(FindFather(x)== FindFather(y)) //���x��y�ĸ������ͬ
    {
      if((Rank[x]-Rank[y]+3)%3 != d-1)//����жϸ��Ĺ�ϵ�Ƿ���ȷ��
        total++;
    }
    else
      Union(x,y,d-1);                 //����ϲ�x��y
  }
  cout<<total<<endl;
  return 0;
}

