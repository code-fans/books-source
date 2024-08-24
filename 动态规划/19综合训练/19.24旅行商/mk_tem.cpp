#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mk make_pair
#define For(i,x,y)  for(int i=(int)x;i<=(int)y;i++)
#define Forn(i,x,y) for(int i=(int)x;i>=(int)y;i--)
using namespace std;
typedef long long	ll;
typedef long double	db;

string NAME="salesman";	// Problem Name is Here
string NUM[]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};

int ran(){
	return (rand()<<15)+rand();
}

int ran(int l,int r){
	return ran()%(r-l+1)+l;
}

void gene(int N){
	int T=5;
	printf("%d\n",T);
	For(i,1,T){
		printf("%d %d\n",N,N);
		For(j,1,N){
			printf("%d %d\n",ran(5e6,1e7),ran(0,100)); 
		}
		For(j,1,N){
			printf("%d %d\n",ran(5e6,1e7),ran(0,N/2)); 
		}
	}
}

int n,U,D,S;
map<int,int> Mps;

int main(){
	srand((int)time(0));
	for(int k=1;k<=10;k++){
		//freopen((NAME+NUM[k]+".in").c_str(),"w",stdout);
		int N=(k<=3)?(5):(2000);
		int D=ran(1,10),U=ran(1,10),S=ran(1,2001);
		printf("%d %d %d %d\n",N,D,U,S);
		Mps.clear();
		Mps[S]=1;
		int Pre=1;
		For(i,1,N){
			int T=ran(1,2001);
			while(Mps[T]) T=ran(1,2001);
			Mps[T]=1;
			printf("%d %d %d\n",Pre,T,ran(1,4000));
			Pre++;
		}
	}
	return 0;
}

