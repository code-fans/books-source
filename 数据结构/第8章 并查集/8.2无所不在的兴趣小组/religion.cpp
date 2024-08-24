//�������ڵ���ȤС��
#include <bits/stdc++.h>
using namespace std;

int father[50001];
int Rank[50001];                       //Rankֵ��¼���ĸ߶�

int Find(int X)                        //�ݹ�д��
{
  return father[X]==X?X:Find(father[X]);//ע��ĳЩ�����õݹ�ᳬʱ
}

void Union(int x,int y)               //�ϲ�
{
  int r1=Find(x);
  int r2=Find(y);
  if(r1==r2)                          //��Ԫ������ͬһ�������˳�
    return;
  if(Rank[r1]>Rank[r2])               //rankֵ��С�ļ��Ϻϲ�����ļ�����
    father[r2]=r1;
  else
  {
    if(Rank[r1] == Rank[r2] )//rankֵ��ȵ����ϲ���rankҪ����һ
      Rank[r2]++;
    father[r1]=r2;
  }
}

int main()
{
  freopen("religion.in","r",stdin);
  freopen("religion.out","w",stdout);
  int m,n,a,b,Case=0;
  while(cin>>n>>m && n+m!=0)
  {
    Case++;
    memset(Rank,0,sizeof(Rank));      //���ĳ�ʼ�߶�Ϊ0
    for(int i=1; i<=n; i++)
      father[i]=i;                    //ע������ָ������
    for(int i=0; i<m; i++)
    {
      cin>>a>>b;
      if(Find(a)!=Find(b))            //���ڲ�ͬ�ļ��ϣ���ϲ�
      {
        n--;                          //����һ
        Union(Find(a),Find(b));
      }
    }
    cout<<"Case "<<Case<<": "<<n<<endl;
  }
  return 0;
}

