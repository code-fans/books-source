//�ǰ׺
#include <bits/stdc++.h>
using namespace std;

int f[200005]= {1},MaxLen,ans;
set<string> P[20];

int main()
{
  //freopen("Prefix.in","r",stdin);
  //freopen("Prefix.out","w",stdout);
  for (string s; cin>>s,s!=".";)
  {
    P[s.size()].insert(s);          //���볤����ͬ�ĵļ�����
    MaxLen=max(MaxLen,int(s.size()));
  }
  string S=" ";
  for(string s; cin>>s; S+=s);
  for (int i=1; i<S.size(); i++)    //ö��S��
    for (int j=min(i,MaxLen); j>=1; j--)
    {
      string t=S.substr(i-j+1,j);   //�س��Ӵ�
      if (f[i-j]==1 && P[t.size()].count(t))
      {
        f[i]=true;
        ans=i;
        break;
      }
    }
  cout<<ans<<endl;
  return 0;
}
