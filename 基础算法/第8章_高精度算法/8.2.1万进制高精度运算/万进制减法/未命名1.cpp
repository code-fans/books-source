//����Ƹ߾��ȼӷ�
#include <bits/stdc++.h>
using namespace std;
const int BASE=10000;
const int Max=1260;
int x[Max],y[Max],ans[Max],len;

void Sub(int x[],int y[],int ans[])
{
  for(int i=Max-1; i>Max-len; i--)
  {
    ans[i]+=x[i]-y[i];
    if(ans[i]<0)
    {
      x[i-1]--;
      ans[i]=ans[i]+BASE;
    }
  }
}

void Output(int ans[])
{
  int st=0;
  for(; ans[st]==0 && st<Max-1; st++);
  printf("%d",ans[st]);                 //������λ��ǰ��0����
  for (int i=st+1; i<Max; i++)
    printf("%04d",ans[i]);
  printf("\n");
}

void Init(int result[],string in)       //stringת��������,4λ��һ��
{
  int k=1,m=0;                          //m��¼���õ�����Ԫ�ظ���
  for(int st=in.size()-1; st>=0; --st)  //���ַ������һλ��ʼ����ֵ
  {
    if(k>=10000)                        //��һ������Ԫ������4λ����ʱ
      k=1, m++;                         //k��ԭΪ1��λ��+1
    result[Max-m-1]+=(in[st]-'0')*k;    //��λ��Max-1,��0000000000123
    k*=10;
  }
}

int main()
{
  freopen("sub.in","r",stdin);
  freopen("sub.out","w",stdout);
  string a,b;
  cin>>a>>b;
  if((a<b && a.size()==b.size()) || a.size()<b.size())
  {
    cout<<'-';
    swap(a, b);
  }
  Init(x,a);
  Init(y,b);
  len=a.size()/4+1;
  Sub(x,y,ans);
  Output(ans);
  return 0;
}

