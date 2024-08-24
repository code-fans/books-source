/*
  Name: USACO 4.3.1 Buy Low,Buy lower
  Copyright: USACO
  Author: NOCOW
  Date: 20-08-10 22:41
  Description: 动态规划 
*/
#include<fstream> 
#include<cstring>
#define cprint fout
#define BIG 5005
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

ofstream fout ("buylow.out",ios::out);
ifstream fin ("buylow.in",ios::in);

struct elect
{
    long ele[BIG],len;
    long MAXN(){return ele[len];}
    long refresh(long VAL){ele[++len]=VAL;return len;}
    long change(long VAL){  //二分查找
        long left=1,right=len,mid=(left+right)>>1;
        while(left<right)
            if(VAL>ele[mid]){
                left=mid+1;
                mid=(left+right)>>1;
            }
            else{
                right=mid;
                mid=(left+right)>>1;
            }
        ele[left]=VAL;
        return left;
    }
}num;

class Plus
{
    int num[80],len;
    public:
    void refresh(){num[++len]=1;}
    friend Plus operator + (const Plus &A,const Plus &B){
        Plus C;
        int LEN=MAX(A.len,B.len);
        for(int i=1;i<=LEN;i++){
            C.num[i]+=A.num[i]+B.num[i];
            C.num[i+1]+=(C.num[i])/10;
            C.num[i]%=10;
        }
        if(C.num[LEN+1]!=0) C.len=++LEN;
            else C.len=LEN;
        return C;
    }
    void operator = (const Plus &A){
        for(int i=1;i<=A.len;i++) num[i]=A.num[i];
        len=A.len;
    }
    void print(){for(int i=len;i>=1;i--) cprint<<num[i];cprint<<endl;}
    Plus(){memset(num,0,sizeof(num));len=0;}
}sum[BIG];
long val[BIG][2],n;
bool Find[BIG],flag;//Find保证不重复计数
Plus tot;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++) fin>>val[i][0];
    for(int i=n;i>=1;i--)
        if(val[i][0]>num.MAXN()) val[i][1]=num.refresh(val[i][0]);
            else{if(val[i][0]<num.MAXN()) val[i][1]=num.change(val[i][0]);
                 else val[i][1]=num.len;}
    for(int i=n;i>=1;i--){
        flag=false;
        for(int j=n;j>=i+1;j--){
            if(!Find[j] && val[i][0]>val[j][0] && val[i][1]==val[j][1]+1){
                sum[i]=sum[i]+sum[j];
                flag=true;
            }
            else if(val[i][0]==val[j][0]) Find[j]=true;//避免重复，保留最当前的
        }
        if(!flag) sum[i].refresh();//未找到满足的，初始化为1
    }
    for(int i=n;i>=1;i--) if(!Find[i] && val[i][1]==num.len) tot=tot+sum[i];
    fout<<num.len<<' ';
    tot.print();
    return 0;
}
