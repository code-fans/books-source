//��ծ���㡪ʹ��string����߾���
//ɾ��С�������м��㣬�����ӻ�С������У���λ��Ϊ������С��λ����
#include <bits/stdc++.h>
using namespace std;

string Mul(string a, string b)       //����a*b
{
  string ans(b.size()+a.size(),'0'); //��ʼ������ַ���
  for (int i=0; i<b.size(); i++)
  {
    int now = 0;
    for (int j=0; j<a.size(); j++)
    {
      now=(a[j]-'0')*(b[i]-'0')+(ans[i+j]-'0')+now/10;
      ans[i+j]=now%10+'0';
      if (j==a.size()-1)
        ans[i+j+1]=now/10+'0';      //���λ��λ
    }
  }
  if (ans[b.size()+a.size()-1]=='0')//�������λû�н�λ
    ans.erase(b.size()+a.size()-1,1);
  return ans;
}

string Expo(string R, int n)        //������
{
  if (n == 1)
    return R;
  string ans = "1", base = R;
  for(; n != 0; n>>=1)
  {
    if (n & 1)
      ans = Mul(ans, base);         //����ǰ��Ҫִ��һ��
    base = Mul(base, base);
  }
  return ans;
}

int main()
{
  freopen("debt.in","r",stdin);
  freopen("debt.out","w",stdout);
  string R, Ans;
  int n;
  while (cin>>R>>n)
  {
    if (n!=0)
    {
      for (int i=0; R[i]!='.' && R[i]=='0'; R.erase(i,1));//����С����ǰ�����0
      reverse(R.begin(), R.end());
      for(int i=0; R[0]=='0'; R.erase(0,1));//����С����ĩβ�����0
      int pos = R.find('.');              //���¼���С����λ��
      R.erase(pos, 1);                //ȥ��С����
      Ans=Expo(R, n);                 //����������������ans�ַ�����
      int len = pos*n;                //ȷ��С����λ��
      if (len>=Ans.size())            //���С��λ���������λ��
      {
        int O=len-Ans.size();
        while(O--)
          Ans+='0';                   //����0
        Ans+='.';
      }
      else
        Ans.insert(len,1,'.');        //����С����
      if (Ans[0]=='.')                //���������
        Ans.erase(0,1);               //ɾ��С����
      reverse(Ans.begin(), Ans.end());
      cout<<(Ans.size()==0?"0":Ans)<<endl;
    }
    else
      cout<<"1\n";
  }
  return 0;
}
