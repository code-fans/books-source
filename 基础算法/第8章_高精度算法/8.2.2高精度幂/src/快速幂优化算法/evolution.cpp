//�߾����ݵ��Ż��㷨
//��νָ�뽻�������ַ�ķ�������ʹ���������ٶ�ƽ�����5������ԭ���Ǹı�����
//ָ���ָ���ʡ��������������֮�临�ƵĹ��̡������������c[]������c[]������
//x[]��ͨ�������ǽ�����c[]������x[]�Ľ���ȴ���һ��ʱ����temp[]���ٽ�temp[]
//��ֵ���θ��Ƶ�����c[]������ɸ�������c[]��Ŀ�ġ���ʹ��ָ�뽻�������ַ����ʱ��
//ֻ�����ָ������c[]��ָ��ĳ�ָ����ʱ����temp[]��ָ�뼴�ɡ�
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int a[10001],x[10001],c[10001];
int b,*pa,*pc,*px;

int Mul(int &len_a,int &len_b,bool bj)
{
  int i,j,r=0;
  for(i=1; i<=len_a+len_b && i<=1000; i++)
    pc[i]=0;                                       //pc�����ʼΪ0
  for(i=1; i<=len_a; i++)                          //�߾��ȼ���
    for(j=1; j<=len_b && i+j-1<=1000; j++)
      pc[i+j-1]+=(pa[i])*(bj?pa[j]:px[j]);
  for(int i=1; i<=len_a+len_b-1 && i<=1000; i++)   //����
  {
    if(pc[i]+r>9)
    {
      pc[i]+=r;
      r=pc[i]/10;
      pc[i]%=10;
    }
    else
    {
      pc[i]+=r;
      r=0;
    }
  }
  if(i>1000)
    len_b=1000;
  else if(r)
  {
    pc[len_a+len_b]=r;
    len_b=len_b+len_a;
  }
  else
    len_b=len_b+len_a-1;
  int *change;                                     //������ַ
  if(!bj)
  {
    change=px;
    px=pc;
    pc=change;
  }
  else
  {
    change=pa;
    pa=pc;
    pc=change;
  }
}

int main()
{
  string s;
  int len_a=0,len_x=1;
  cin>>s>>b;
  int len=s.size();
  for(int i=1; i<=len; i++)                        //���ַ�����תΪ��������
    a[i]=s[len-i]-'0';
  len_a=len;
  pa=a;                                            //paָ��ָ��a����
  pc=c;                                            //pcָ��ָ��c����
  px=x;                                            //pxָ��ָ��x����
  px[1]=1;                                         //px���鱣����
  while(b>1)                                       //�����㷨
  {
    if(b%2==1)
      Mul(len_a,len_x,0);
    Mul(len_a,len_a,1);
    b=b>>1;                                        //b=b/2
  }
  Mul(len_a,len_x,0);
  for(int i=len_x; i>=1; i--)                      //�����
    cout<<px[i];
  cout<<endl;
  return 0;
}

