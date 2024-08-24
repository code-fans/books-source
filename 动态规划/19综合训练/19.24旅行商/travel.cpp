	#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define Exit(...)    printf(__VA_ARGS__),exit(0)
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Rep(i,a,b)   for(int i=(int)a;i< (int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef	double		db;
typedef	long long	ll;
const	int N=500005;
const	ll	Inf=(ll)1e10;
const	int inf=(int)1e9;
const	int	mo=ll(1e9+7);

inline int IN(){
	char ch;CH; int f=0,x=0;
	for(;pend(ch);CH); if(ch=='-')f=1,CH;
	for(;!pend(ch);CH) x=x*10+ch-'0';
	return (f)?(-x):(x);
}

int Pow(int x,int y,int p){
	int A=1;
	for(;y;y>>=1,x=(ll)x*x%p) if(y&1) A=(ll)A*x%p;
	return A;
}

int n,U,D,S,tmp[N],dp[N],ans;
int maxu[N*4],maxd[N*4];
struct event{
	int tim,pos,val;
	inline int operator <(const event &a)const{
		if(tim!=a.tim) return tim<a.tim;
		return pos<a.pos;
	}
}t[N];

//f[i]=f[j]+s[j]*D-s[i]*D s[i]>s[j]
//f[i]=f[j]-s[j]*U+s[i]*U s[i]<s[j]

void modify(int x,int L,int R,int pos,int val,int *Max){
	if(L==R){
		if(val>Max[x]) Max[x]=val;
		return;
	}
	int md=(L+R)>>1;
	if(pos<=md) modify(x*2,L,md,pos,val,Max);
	else modify(x*2+1,md+1,R,pos,val,Max);
	Max[x]=max(Max[x*2],Max[x*2+1]);
}

int query(int x,int L,int R,int ll,int rr,int *Max){
	if(ll<=L&&R<=rr) return Max[x];
	int md=(L+R)>>1;
	int an=-inf;
	if(ll<=md) an=max(an,query(x*2,L,md,ll,rr,Max));
	if(md<rr)  an=max(an,query(x*2+1,md+1,R,ll,rr,Max));
	return an;
}

int query(int x){
	int key=-inf,ans=-inf;
	key=query(1,1,500001,1,x,maxd)-x*D;
	if(key>ans) ans=key;
	key=query(1,1,500001,x+1,500001,maxu)+x*U;
	if(key>ans) ans=key;
	return ans;
}

void change(int x,int val){
	int key;
	key=val+x*D; modify(1,1,500001,x,key,maxd);
	key=val-x*U; modify(1,1,500001,x,key,maxu);
}

int main(){
	scanf("%d%d%d%d",&n,&U,&D,&S);
	memset(maxd,200,sizeof maxd);
	memset(maxu,200,sizeof maxu);
	For(i,1,n)
		scanf("%d%d%d",&t[i].tim,&t[i].pos,&t[i].val);
	change(S,0);
	sort(t+1,t+n+1);
	For(i,1,n){
		int j=i,Gt=0;
		while(t[j].tim==t[i].tim&&j<=n)++j;--j;
		For(k,i,j)
			dp[k]=tmp[k]=query(t[k].pos)+t[k].val;
		Gt=tmp[i];
		For(k,i+1,j){
			Gt+=-(t[k].pos-t[k-1].pos)*D+t[k].val;
			if(Gt>dp[k]) dp[k]=Gt;
			if(tmp[k]>Gt) Gt=tmp[k];
		}
		Gt=tmp[j];
		Forn(k,j-1,i){
			Gt+=-(t[k+1].pos-t[k].pos)*U+t[k].val;
			if(Gt>dp[k]) dp[k]=Gt;
			if(tmp[k]>Gt) Gt=tmp[k];
		}
		For(k,i,j){
			change(t[k].pos,dp[k]);
			int key;
			if(t[k].pos<S){
				key=dp[k]-(S-t[k].pos)*D;
				if(key>ans) ans=key;
			}else{
				key=dp[k]-(t[k].pos-S)*U;
				if(key>ans) ans=key;
			}
		}
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}




