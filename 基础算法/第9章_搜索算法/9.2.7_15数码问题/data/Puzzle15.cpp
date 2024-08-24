#include<bits/stdc++.h>
using namespace std;
const int n=16;
const int Pos[]= {15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int t,a[n+1],zero,limit;
char step[1000];

inline int Read()                        //以字符串形式读入数字可提速
{
  int x=0;
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
  return x;
}

inline int Manhattan(int O)
{
  int sum=0;
  for(register int x=0; x<=15; x++)
    sum+=abs((x>>2)-(Pos[a[x]]>>2))+abs((x&3)-(Pos[a[x]]&3));
  return sum-(abs((O>>2)-(Pos[a[O]]>>2))+abs((O&3)-(Pos[a[O]]&3)));
}

inline void swap(int &a,int &b)
{
  a^=b,b^=a,a^=b;
}

int nxt[4]= {-4,1,-1,4};

bool Dfs(int zero,int dep=0)
{
  int k=Manhattan(zero),z;
  if(!k)
    return true;
  if(dep+k>limit)
    return false;
  for(int i=0; i<4; i++)
  {
    z=zero+nxt[i];
    if(i==0 && step[dep]!='D' && zero>3)
      step[dep+1]='U';
    else if (i==1 && step[dep]!='L' && (zero & 3)<3)
      step[dep+1]='R';
    else if (i==2 && step[dep]!='R' && (zero & 3))
      step[dep+1]='L';
    else if (i==3 && step[dep]!='U' && zero<12)
      step[dep+1]='D';
    else
      continue;
    swap(a[zero],a[z]);
    if(Dfs(z,dep+1))
      return true;
    swap(a[zero],a[z]);
  }
  return false;
  /* //拆开的代码速度会略快一些
    if(step[dep]!='D' && zero>3)
    {
      z=zero-4;
      swap(a[zero],a[z]);
      step[dep+1]='U';
      if(Dfs(z,dep+1))
        return true;
      swap(a[zero],a[z]);
    }
    if(step[dep]!='L' && (zero & 3)<3)
    {
      z=zero+1;
      swap(a[zero],a[z]);
      step[dep+1]='R';
      if(Dfs(z,dep+1))
        return true;
      swap(a[zero],a[z]);
    }
    if(step[dep]!='R' && (zero & 3))
    {
      z=zero-1;
      swap(a[zero],a[z]);
      step[dep+1]='L';
      if(Dfs(z,dep+1))
        return true;
      swap(a[zero],a[z]);
    }
    if(step[dep]!='U' && zero<12)
    {
      z=zero+4;
      swap(a[zero],a[z]);
      step[dep+1]='D';
      if(Dfs(z,dep+1))
        return true;
      swap(a[zero],a[z]);
    }*/
  return false;
}

int main()
{
  freopen("Puzzle15.in","r",stdin);
  freopen("Puzzle15.out","w",stdout);
  for(t=Read(); t; t--)
  {
    int cnt=0;
    for(register int i=0; i<n; ++i)
    {
      a[i]=Read();
      if(!a[i])
        zero=i;                        //获取0的位置
      else
        for(register int j=0; j<i; ++j)//求逆序对
          if(a[i]<a[j])
            ++cnt;
    }
    if(cnt-(3-zero/4) & 1)                        //逆序对为奇数无解
      printf("This puzzle is not solvable.\n");
    else
    {
      limit=Manhattan(zero);
      while(limit<=50 && !Dfs(zero))
        ++limit;
      printf("%s\n",step+1);
    }
  }
  return 0;
}
