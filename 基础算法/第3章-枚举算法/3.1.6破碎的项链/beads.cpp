//���������
#include<bits/stdc++.h>
using namespace std;
int n, ans = -1;
string s;
int Calc(int pos)
{
  int i,Len = 2, L=(pos-1+n) % n, R = pos;           //l,r�������ҷָ���λ��
  for(; (R + 1) % n != pos && s[R % n] == 'w'; R++, Len++);//�����ұ�������w,ȷ��R��λ��
  for(i=1; i<n && (s[R%n]==s[(R+i)% n] || s[(R+i)%n]=='w'); i++,Len++);//����
  for(i=2; i<n && (s[L]==s[(pos-i+n)%n] || s[(pos-i+n)%n]=='w'); i++,Len++);//����
  return Len>n?n:Len;//����ɷָ��ȫ����ͬ: wwwrrrr �������
}

int main()
{
  freopen("beads.in","r",stdin);
  freopen("beads.out","w",stdout);
  cin>>n>>s;
  for(int i = 0; i < n; i++)
    if(s[(i-1+n)%n]!=s[i] && s[(i-1+n)%n]!='w')
      ans = max(ans, Calc(i));
  cout<<(ans==-1 ? n:ans)<<endl;//-1��ʾ�޷��ָȫ����ɫ��ͬ
  return 0;
}
