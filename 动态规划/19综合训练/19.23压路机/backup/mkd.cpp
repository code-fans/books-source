#include<iostream>
#include<windows.h>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
int N=100,M=100,flag=2;
int R(int x){return ((rand()<<15)+rand())%x+1;}
int get(){return !flag?1:flag==1?R(2)-1:flag==2?R(2)&1?R(10):R(100):R(100);}
int main()
{
//	freopen("roller.in","w",stdout);
	srand(time(0)); Sleep(1000);
	scanf("%d%d%d",&N,&M,&flag);
	rep(_,10){
		int n=R(N/2)+N/2,m=R(M/2)+M/2;
		printf("%d %d %d %d %d %d\n",n,m,R(n),R(m),R(n),R(m));
		rep(i,n){
			rep(j,m-1) printf(" %d",get()); puts("");
			if (i<n) rep(j,m) printf("%d%s",get(),j<m?" ":"\n");
		}
	}
	puts("0 0 0 0 0 0");
	return 0;
}
