/*
程序名称：USACO1.1.4 Broken Necklace
程序说明：动态规划法，两个同样的珠子相连成线形，此处不需对白珠子进行动态转换，
而使用笨方法即设w全为r,进行扫描，再设w全为b,进行扫描，因此设f数组为二维
最后从左至右及从右向左扫描，找出rr,rl,br,bl 
程序作者：ZXH (2010-7-27)
程序备注：注意ans>n情况的出现 
*/
#include <stdio.h>
 
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int i,ans=0,n;
	char f[2][702];
	int s[4][702]={0};//即rl,rr,bl,br 
	scanf("%d%s",&n,f);
	for(i=0;i<n;i++)
      f[1][i]=f[0][i];
	for(i=0;i<n;i++)//将两个相同的项链连成一串 
    {
		if(f[0][i]=='w')
          f[0][i]='r';//w全变成红的 
        f[0][n+i]=f[0][i];
		if(f[1][i]=='w')
          f[1][i]='b';//或w全变成蓝的 
        f[1][n+i]=f[1][i];
	}
	if(f[0][0]=='r')//此处计算rr,br 
      s[0][0]=1;//rr
	if(f[1][0]=='b')
      s[1][0]=1;//br
	for(i=1;i<2*n;i++)
    {
		if(f[0][i]=='r')
        {
			if(f[0][i-1]=='r')
              s[0][i]=s[0][i-1]+1;
			else 
              s[0][i]=1;
		}
		if(f[1][i]=='b')
        {
			if(f[1][i-1]=='b')
              s[1][i]=s[1][i-1]+1;
			else 
              s[1][i]=1;
		}
	}
	if(f[2][2*n-1]=='r')//此处计算rl,bl 
      s[2][2*n-1]=1;//rl
	if(f[3][2*n-1]=='b')
      s[3][2*n-1]=1;//bl
	for(i=2*n-2;i>=0;i--)//从右向左 
    {
		if(f[0][i]=='r')
        {
			if(f[0][i+1]=='r')
              s[2][i]=s[2][i+1]+1;
			else 
              s[2][i]=1;
		}
		if(f[1][i]=='b')
        {
			if(f[1][i+1]=='b')
              s[3][i]=s[3][i+1]+1;
			else 
              s[3][i]=1;
		}
	}
	for(i=1;i<2*n;i++)
    {
	  if(ans<(s[0][i]>s[1][i]?s[0][i]:s[1][i])+(s[2][i+1]>s[3][i+1]?s[2][i+1]:s[3][i+1]))
	    ans=(s[0][i]>s[1][i]?s[0][i]:s[1][i])+(s[2][i+1]>s[3][i+1]?s[2][i+1]:s[3][i+1]);
	}
	printf("%d\n",ans>n?n:ans);
	return 0;
}
