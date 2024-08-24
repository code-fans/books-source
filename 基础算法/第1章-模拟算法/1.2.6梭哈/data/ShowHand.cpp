//梭哈
#include <bits/stdc++.h>
using namespace std;

struct card
{
  int n,f;                             //牌的点数，花色
} a[6],b[6];

bool operator <(card a, card b)        //运算符重载
{
  return(a.n>b.n)||((a.n==b.n)&&(a.f>b.f));
}

bool StraightFlush(card t[])           //同花顺
{
  for (int i = 1; i<5; i++)
    if ((t[i].f != t[i + 1].f) || (t[i].n != t[i + 1].n + 1))
      return false;
  return true;
}

bool FourofaKind(card t[])             //四条
{
  if(t[1].n==t[2].n && t[2].n==t[3].n && t[3].n==t[4].n)
    return true;
  if(t[2].n==t[3].n && t[3].n==t[4].n && t[4].n==t[5].n)
  {
    for(int i=1; i<=5; i++)
    {
      cout<<t[i].n<<' '<<t[i].f<<" ";
      cout<<endl;
    }
    swap(t[1],t[5]);//将四条调到前面去 
    sort(t+1, t+5);
    return true;
  }
  return false;
}

bool FullHouse(card t[])               //满堂红
{
  if(t[1].n==t[2].n && t[2].n==t[3].n && t[4].n==t[5].n)
    return true;
  if(t[1].n==t[2].n && t[3].n==t[4].n && t[4].n==t[5].n)
  {
    swap(t[1],t[5]);                   //整理牌
    swap(t[2],t[4]);
    sort(t + 1, t + 4);
    sort(t + 4, t + 6);
    return true;
  }
  return false;
}

bool Flush(card t[])                   //同花
{
  for (int i = 1; i<5; i++)
    if (t[i].f != t[i + 1].f)
      return false;
  return true;
}

bool Straight(card t[])                //顺子
{
  for (int i = 1; i<5; i++)
    if (t[i].n != t[i + 1].n + 1)
      return false;
  return true;
}

bool Threeofakind(card t[])            //三条
{
  if (t[1].n == t[2].n && t[2].n == t[3].n)
    return true;
  if (t[2].n == t[3].n && t[3].n == t[4].n)
  {
    swap(t[1],t[2]);                   //整理牌
    swap(t[2],t[3]);
    swap(t[3],t[4]);
    return true;
  }
  if (t[3].n == t[4].n && t[4].n == t[5].n)
  {
    swap(t[1],t[3]);                   //整理牌
    swap(t[2],t[4]);
    swap(t[3],t[5]);
    swap(t[4],t[5]);
    return true;
  }
  return false;
}

bool TwoPairs(card t[])                //两对
{
  if (t[1].n == t[2].n && t[3].n == t[4].n)
    return true;
  if (t[1].n == t[2].n && t[4].n == t[5].n)
  {
    swap(t[3],t[4]);                   //整理牌
    swap(t[4],t[5]);
    return true;
  }
  if (t[2].n == t[3].n && t[4].n == t[5].n)
  {
    swap(t[1], t[2]);                  //整理牌
    swap(t[2], t[3]);
    swap(t[3], t[4]);
    swap(t[4], t[5]);
    return true;
  }
  return false;
}

bool OnePair(card t[])                 //一对
{
  if (t[1].n == t[2].n)
    return true;
  if (t[2].n == t[3].n)
  {
    swap(t[1], t[2]);                  //整理牌
    swap(t[2], t[3]);
    return true;
  }
  if (t[3].n == t[4].n)
  {
    swap(t[1], t[3]);                  //整理牌
    swap(t[2], t[4]);
    return true;
  }
  if (t[4].n == t[5].n)
  {
    swap(t[2], t[4]);                  //整理牌
    swap(t[3], t[5]);
    swap(t[1], t[2]);
    swap(t[2], t[3]);
    return true;
  }
  return false;
}

int Count(card t[])                    //计算玩家手上牌的分值
{
  if((t[1].n==14)&&(t[2].n==5)&&(t[3].n==4)&&(t[4].n==3)&&(t[5].n==2))
    for(int i=1; i<=5; i++)
      t[i].n = 6 - i;                  //将A,1,2,3,4变为5,4,3,2,1
  if(StraightFlush(t))                 //同花顺
    return 9;
  else if(FourofaKind(t))              //四条
    return 8;
  else if(FullHouse(t))                //满堂红
    return 7;
  else if(Flush(t))                    //同花
    return 6;
  else if(Straight(t))                 //顺子
    return 5;
  else if(Threeofakind(t))             //三条
    return 4;
  else if(TwoPairs(t))                 //两对
    return 3;
  else if(OnePair(t))                  //一对
    return 2;
  else                                 //无对
    return 1;
}

int main()
{
  freopen("ShowHand.in","r",stdin);
  freopen("ShowHand.out","w",stdout);
  for (int i; scanf("%d%d",&a[1].n,&a[1].f)==2;)
  {
    for (i = 2; i <= 5; i++)           //读牌
      scanf("%d%d", &a[i].n, &a[i].f);
    for (i = 1; i <= 5; i++)
      scanf("%d%d", &b[i].n, &b[i].f);
    for (i = 1; i <= 5; i++)
    {
      if (a[i].n == 1)                 //对A牌的处理
        a[i].n = 14;
      if (b[i].n == 1)
        b[i].n = 14;
      a[i].f = 5 - a[i].f;             //对牌的花色按大小赋值
      b[i].f = 5 - b[i].f;
    }
    sort(a + 1, a + 6);                //牌由大到小排序,注意运算符已重载
    sort(b + 1, b + 6);
    int A=Count(a);//计算a玩家分值
    int B=Count(b);//计算b玩家分值
    if(A>B)
      cout<<"Player A win!\n";
    else if(A<B)
      cout<<"Player B win!\n";
    else
    {
      for (i = 1; i <= 5; i++)
        if (a[i].n != b[i].n)
        {
          if (a[i].n>b[i].n)
            cout<<"Player A win!\n";
          if (a[i].n<b[i].n)
            cout<<"Player B win!\n";
          break;
        }
      if (i>5)
        cout<<"Player "<<(a[1].f>b[1].f?"A ":"B ")<<"win!\n";
    }
  }
  return 0;
}

