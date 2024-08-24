//蚯蚓-优先队列
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("earthworm.in","r",stdin);
  freopen("earthworm.out","w",stdout);
  priority_queue<int> earthworm;  //优先队列默认由大到小排列
  int n,m,t,q,u,v,sum=0;          //sum用于保存累计增加的q值
  cin>>n>>m>>q>>u>>v>>t;
  double p=double(u)/v;
  for(int i=0,temp; i<n; ++i)
  {
    cin>>temp;
    earthworm.push(temp);         //入队列
  }
  for(int i=1; i<=m; i++)
  {
    int Big=earthworm.top()+sum;  //队首为最大值，出队时还原回真实值
    earthworm.pop();              //删除队首的蚯蚓
    if(!(i%t))                    //输出第i*t秒切的蚯蚓
      cout<<Big<<" ";
    int cut=floor(p*double(Big)); //用floor以防因编译器不同而出现误差
    earthworm.push(cut-sum-q);    //切割的蚯蚓无需加q,所以先减去
    earthworm.push(Big-cut-sum-q);
    sum+=q;                       //累计总的增长量
  }
  cout<<'\n';
  for(int i=1; i<=n+m; ++i)
  {
    if(!(i%t))
      cout<<earthworm.top()+sum<<' ';
    earthworm.pop();
  }
  cout<<'\n';
  return 0;
}

