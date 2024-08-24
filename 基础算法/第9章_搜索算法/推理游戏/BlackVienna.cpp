//推理游戏
#include<bits/stdc++.h>
using namespace std;
const int Three=3,h=15, q=5,m=13;//通过定义常数防止栈溢出

char quest[h][4],hand[Three+1][6];          //审问内容,实际手牌
char card[Three+1][q+1],eson[m];//可能手牌
int ask[h],reply[h];//被审问的人,审问答案
int mas[Three+1];
int v,T;//审问次数

int msn(char a1[],char a2[])
{
  int n=0;
  for(int i=0; i<5; i++)
    for(int j=0; j<3; j++)
      if(a1[i]==a2[j])
        n++;
  return n;
}

int mqn(char jook[][q+1])
{
  int t=0;
  while(t<T &&msn(jook[ask[t]],quest[t])==reply[t])
    t++;
  return t;
}

void men(int r,char l[])
{
  if(r==(18-5))
  {
    if (card[Three][0] == l[r-Three])
      return;
    v = max(v, mqn(card));
  }
  else
  {
    for(int j=0; j<=Three; j++)
    {
      if((j<Three && mas[j]<5) || (j==Three && mas[j]<3))
      {
        card[j][mas[j]]=l[r];
        mas[j]++;
        men(r+1,l);
        mas[j]--;
      }
    }
  }
}

int main()
{
  //freopen("BlackVienna.in","r",stdin);
  //freopen("BlackVienna.out","w",stdout);
  while(scanf("%d",&T)!=EOF && T>0)
  {
    for(int i=0; i<=Three; i++)
      scanf("%s",&hand[i]);      //输入三人拿的牌
    for(int i=0; i<T; i++)
    {
      scanf("%d",&ask[i]);       //询问人
      ask[i]--;
      scanf("%s",&quest[i]);
      scanf("%d",&reply[i]);
    }
    int k=h;
    for(int i=0; i<Three; i++)
    {
      memset(eson,0,sizeof(eson));//将数组中元素初始为0
      for(int j=0; j<=Three; j++)
        if(j!=i)
          strcat(eson,hand[j]);//连接另两个人的牌 
      strcpy(card[i],hand[i]);
      mas[i] = q;
      v = 0;
      men(0,eson);
      memset(card[i],'\0',sizeof(card[i]));//如上方的清0方法
      mas[i]=0;
      if(v<k)
        k=v;
    }
    if(k<T)
      printf("%d\n",k+1);
    else
      printf("?\n");
  }
  return 0;
}


