//九连环 —递归算法
#include<bits/stdc++.h>
using namespace std;

int step,num;
string End="1000000000";          //结束状态，第0位上杆不用
string sta="1111111111";          //初始状态，第0位上杆不用
string ans[500]= {"111111111"};

void Turn(int n)                  //翻转第n位
{
  if(sta==End)                    //可删除此判断
    return;
  if(sta[n-1]=='0')               //必须上一位为上杆
    Turn(n-1);
  for(int i=n-2; i>=1; i--)       //必须1~n-2位均为下杆
    if(sta[i]=='1')
      Turn(i);
  sta[n]=(sta[n]=='1'?'0':'1');   //翻转当前位
  ans[++step]=sta.substr(1,9);    //保存当前状态
}

int main()
{
  freopen("ring.in","r",stdin);
  freopen("ring.out","w",stdout);
  for(int i=9; i>=1; i--)         //因为后面的影响前面的，所以从后向前翻转
    Turn(i);
  while(cin>>num)
    cout<<(num>step?"-1":ans[num])<<endl;
  return 0;
}
