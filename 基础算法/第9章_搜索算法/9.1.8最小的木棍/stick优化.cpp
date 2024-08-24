//最小的木棍
#include<bits/stdc++.h>
using namespace std;

int num,cnt,len,OK;//num为原始木棍的根数，len为原始木棍的长度
int stick[101],Next[101];
bool used[101]; //used记录每根木棍是否用过

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

void DFS(int now,int last,int rest) //now:正在拼第几根木棍,last:正拼木棍的前一节，rest为剩下长度
{
  int i;
  if(OK==1)
    return;
  if(!rest)  //未拼的长度为0，说明这根原始长棍拼完了，准备拼下一个
  {
    if(now==num)//拼的根数够了，输出答案
    {
      OK=1;
      return;
    }
    for(i=1; i<=cnt && used[i]; i++);//找还没用的最长的木棍做下一根,反正每根木头都要用
    used[i]=1;
    DFS(now+1,i,len-stick[i]);//拼下一根
    used[i]=0;
  }
  int l=last+1, r=cnt;//优化:二分找第一个木棍长度不大于未拼长度rest的位置
  while(l<r)
  {
    int mid=(l+r)>>1;
    stick[mid]<=rest? r=mid:l=mid+1;
  }
  for(i=l; i<=cnt; i++)//从不超过rest的木棍开始
  {
    if(!used[i])  //判断木棍是否用过
    {
      used[i]=1;
      DFS(now,i,rest-stick[i]);
      used[i]=0;
      /*(1)当前长棍剩余的未拼长度等于当前木棍的长度时，这根木棍在最优情况下显然
      是拼到这（如果用更多短木根拼完剩下的这段，把这根木棍留到后面显然不如把更多
      总长相等的短木棍扔到后面）。如果在最优情况下继续拼下去失败了，那肯定是之前
      的木棍用错了，回溯改即可。*/
      /*(2)当前长棍剩余的未拼长度等于原始长度时，说明这根原来的长棍还一点没拼，
      现在正在放入一根木棍。很明显，这根木棍还没有跟其它棍子拼接，如果现在拼下去
      能成功话，它肯定是能用上的，即自组或与其它还没用的木棍拼接。但继续拼下去
      却失败，说明现在这根木棍不能用上，无法完成拼接，所以回溯改之前的木棍。*/
      if(rest==stick[i] || rest==len) return; //优化(1)(2)
      i=Next[i]; //选下一个与当前木棍的不等长的木棍，免得白费劲
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
      if(t<=50)                          //优化:除去不合格的
      {
        stick[++cnt]=t;
        sum+=t;
      }
    }
    sort(stick+1,stick+cnt+1,greater<int>());       //优化:木棍按长度从大到小排序
    Next[cnt]=cnt;
    for(int i=cnt-1; i>0; i--)           //优化:预处理Next数组
      Next[i]=(stick[i]==stick[i+1]?Next[i+1]:Next[i]=i);
    int MaxLen=(sum>>1);
    for(len=stick[1]; len<=MaxLen; ++len)//优化：从最长的一根试到sum/2
    {
      if(sum%len)
        continue;                        //优化：如果不能拼出整数根就跳过
      num=sum/len;                       //优化:先计算出根数
      used[1]=1;
      DFS(1,1,len-stick[1]);             //优化：长度至少是最长的一个
      if(OK==1)
        break;
      used[1]=0;
    }
    printf("%d\n",OK==1?len:sum);
  }
  return 0;
}
