//N�ʺ����⡪λ���� 
#include <bits/stdc++.h>
using namespace std;

int upperlim,sum,n;

void Test(int row,int ld,int rd)
{
  if(row!=upperlim)                     //δ����������Ϊ11111111ʱ
  {
    int pos=upperlim & ~(row | ld | rd);//ȡ����õ����п��Էŵ�λ��
    while(pos!=0)
    {
      int p=pos & -pos;                 //ȡ�����ұߵ�1���г���
      pos-=p;                           //����λ�õ�P��pos���Ƴ�
      Test(row+p,(ld+p)<<1,(rd+p)>>1);
    }
  }
  else
    sum++;
}

int main()
{
  //freopen("queen.in","r",stdin);
  //freopen("queen.out","w",stdout);
  cin>>n;
  upperlim=(1 << n)-1;//���Ϊ11111111
  Test(0,0,0);        //�����������У���Խ��ߣ��ҶԽ����Ƿ�ռ��
  cout<<sum<<endl;
  return 0;
}

