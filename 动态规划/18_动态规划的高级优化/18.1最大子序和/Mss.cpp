//��������
#include <bits/stdc++.h>
using namespace std;

long long s[300005];                  //ǰ�������
list<int> Q;                           //�˴�ʹ��STL���list����������

int main()
{
  freopen("Mss.in","r",stdin);
  freopen("Mss.out","w",stdout);
  Q.push_front(0);
  int n,m;
  cin>>n>>m;
  for (int i=1; i<=n; i++)
  {
    cin>>s[i];
    s[i]+=s[i-1];                         //����ǰ׺��
  }
  long long maxx=s[1];
  for (int i=1; i<=n; i++)
  {
    while(!Q.empty() && s[Q.front()]>s[i])//ע��˴�frontΪ��β
      Q.pop_front();                      //ɾ�����ֵ�����
    Q.push_front(i);                      //���뵱ǰ����
    while(!Q.empty() && i-m>Q.back())     //��֤i-m>=queue.back()
      Q.pop_back();                       //ɾ������Ԫ��(backΪ����)��ά�������С
    maxx=max(maxx,s[i]-s[Q.back()]);    //������ֵ
  }
  cout<<maxx<<endl;
  return 0;
}

