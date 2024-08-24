//̫�ձ���
#include <bits/stdc++.h>
using namespace std;

struct
{
  int a,b,sum;
} t[200040];
int people[50010];                        //people[50010]���ÿ�����ϵĴ���

void BuildTree(int x,int y,int num)       //�����߶���
{
  t[num].a=x;                             //ȷ����˵�Ϊx
  t[num].b=y;                             //ȷ���Ҷ˵�Ϊy
  if(x==y)                                //���x==y��˵���Ѿ���Ҷ�ӽ����
    t[num].sum=people[y];                 //������Ϊ�����ı��ݷɴ���
  else
  {
    int Lson=num<<1,Rson=Lson|1;          //���ӽ��Ϊnum*2,���ӽ��Ϊnum*2+1
    BuildTree(x,((x+y)>>1),Lson);         //�ݹ鹹���������
    BuildTree(((x+y)>>1)+1,y,Rson);       //�ݹ鹹���Ҷ�����
    t[num].sum=t[Lson].sum+t[Rson].sum;   //�������������ӽ��ĺ�
  }
}

int Query(int L,int R,int num)            //��ʼnumΪ1�����Ӹ���㿪ʼ����
{
  if(L <= t[num].a && R >= t[num].b)      //����ڰ��������ڣ��򷵻�ֵ
    return t[num].sum;
  int min = (t[num].a+t[num].b)>>1;       //ȡ���Ҷ˵���м�
  int ans = 0;
  if(L <= min)
    ans += Query(L, R, num<<1);           //�ݹ�������
  if(R > min)
    ans += Query(L, R, num<<1|1);         //�ݹ�������
  return ans;
}

void Update(int i,int j,int num)          //��i���������ӻ����j���ɴ�
{
  t[num].sum+=j;
  if(t[num].a==i && t[num].b==i)          //����ҵ�i��Ҷ�ӽ�㣬��ֹͣ
    return;
  if(i>(t[num].a+(t[num].b)>>1))          //�����i�ڸ��߶ε��ұ�
    Update(i,j,num<<1|1);                 //��ݹ�������ӽ��
  else
    Update(i,j,num<<1);                   //����ݹ�������ӽ��
}

int main()
{
  freopen("fort.in","r",stdin);
  freopen("fort.out","w",stdout);
  int a,b,n,t,Case=0;
  cin>>t;
  while(t--)
  {
    scanf("%d",&n);                       //ע���дҪ���٣�����ᳬʱ
    people[0]=0;
    for(int i=1; i<=n; i++)
      scanf("%d",&people[i]);
    BuildTree(1,n,1);                     //�Ӹ����t[1]��ʼ���߶���
    printf("Case %d:\n",++Case);
    getchar();                            //���ں��Ի��з�
    for(string command; cin>>command;)
    {
      if(command=="End")
        break;
      cin>>a>>b;
      if(command=="Query")
        printf("%d\n",Query(a,b,1));      //�Ӹ����t[1]��ʼ
      if(command=="Add")
        Update(a,b,1);                    //�Ӹ����t[1]��ʼ
      if(command=="Sub")
        Update(a,-b,1);                   //�Ӹ����t[1]��ʼ
    }
  }
  return 0;
}

