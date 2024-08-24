//��С��ľ��
#include<bits/stdc++.h>
using namespace std;

int num,cnt,len,OK;//numΪԭʼľ���ĸ�����lenΪԭʼľ���ĳ���
int stick[101],Next[101];
bool used[101]; //used��¼ÿ��ľ���Ƿ��ù�

inline int Read(int x=0)
{
  char c=getchar();
  for(; !isdigit(c); c=getchar());
  for(; isdigit(c);  c=getchar()) x=(x<<3)+(x<<1)+c-'0';
  return x;
}

bool Cmp(int a,int b)
{
  return a>b;
}

void DFS(int now,int last,int rest) //now:����ƴ�ڼ���ľ��,last:��ƴľ����ǰһ�ڣ�restΪʣ�³���
{
  int i;
  if(OK==1)
    return;
  if(!rest)  //δƴ�ĳ���Ϊ0��˵�����ԭʼ����ƴ���ˣ�׼��ƴ��һ��
  {
    if(now==num)//ƴ�ĸ������ˣ������
    {
      OK=1;
      return;
    }
    for(i=1; i<=cnt && used[i]; i++);//�һ�û�õ����ľ������һ��,����ÿ��ľͷ��Ҫ��
    used[i]=1;
    DFS(now+1,i,len-stick[i]);//ƴ��һ��
    used[i]=0;
  }
  int l=last+1, r=cnt;//�Ż�:�����ҵ�һ��ľ�����Ȳ�����δƴ����rest��λ��
  while(l<r)
  {
    int mid=(l+r)>>1;
    stick[mid]<=rest? r=mid:l=mid+1;
  }
  for(i=l; i<=cnt; i++)//�Ӳ�����rest��ľ����ʼ
  {
    if(!used[i])  //�ж�ľ���Ƿ��ù�
    {
      used[i]=1;
      DFS(now,i,rest-stick[i]);
      used[i]=0;
      /*(1)��ǰ����ʣ���δƴ���ȵ��ڵ�ǰľ���ĳ���ʱ�����ľ���������������Ȼ
      ��ƴ���⣨����ø����ľ��ƴ��ʣ�µ���Σ������ľ������������Ȼ����Ѹ���
      �ܳ���ȵĶ�ľ���ӵ����棩���������������¼���ƴ��ȥʧ���ˣ��ǿ϶���֮ǰ
      ��ľ���ô��ˣ����ݸļ��ɡ�*/
      /*(2)��ǰ����ʣ���δƴ���ȵ���ԭʼ����ʱ��˵�����ԭ���ĳ�����һ��ûƴ��
      �������ڷ���һ��ľ���������ԣ����ľ����û�и���������ƴ�ӣ��������ƴ��ȥ
      �ܳɹ��������϶��������ϵģ����������������û�õ�ľ��ƴ�ӡ�������ƴ��ȥ
      ȴʧ�ܣ�˵���������ľ���������ϣ��޷����ƴ�ӣ����Ի��ݸ�֮ǰ��ľ����*/
      if(rest==stick[i] || rest==len) return; //�Ż�(1)(2)
      i=Next[i]; //ѡ��һ���뵱ǰľ���Ĳ��ȳ���ľ������ð׷Ѿ�
      if(i==cnt) return;
    }
  }
}

int main()
{
  freopen("stick.in","r",stdin);
  freopen("stick.out","w",stdout);
  int n,sum;
  while(n=Read())
  {
    if(n==0)
      break;
    sum=cnt=OK=num=0;
    memset(used,0,sizeof(used));
    for(int i=1,t; i<=n; i++)
    {
      t=Read();
      if(t<=50)                          //�Ż�:��ȥ���ϸ��
      {
        stick[++cnt]=t;
        sum+=t;
      }
    }
    sort(stick+1,stick+cnt+1,greater<int>());       //�Ż�:ľ�������ȴӴ�С����
    Next[cnt]=cnt;
    for(int i=cnt-1; i>0; i--)           //�Ż�:Ԥ����Next����
      Next[i]=(stick[i]==stick[i+1]?Next[i+1]:Next[i]=i);
    int MaxLen=(sum>>1);
    for(len=stick[1]; len<=MaxLen; ++len)//�Ż��������һ���Ե�sum/2
    {
      if(sum%len)
        continue;                        //�Ż����������ƴ��������������
      num=sum/len;                       //�Ż�:�ȼ��������
      used[1]=1;
      DFS(1,1,len-stick[1]);             //�Ż����������������һ��
      if(OK==1)
        break;
      used[1]=0;
    }
    printf("%d\n",OK==1?len:sum);
  }
  return 0;
}
