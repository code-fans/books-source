//������ ���ݹ��㷨
#include<bits/stdc++.h>
using namespace std;

int step,num;
string End="1000000000";          //����״̬����0λ�ϸ˲���
string sta="1111111111";          //��ʼ״̬����0λ�ϸ˲���
string ans[500]= {"111111111"};

void Turn(int n)                  //��ת��nλ
{
  if(sta==End)                    //��ɾ�����ж�
    return;
  if(sta[n-1]=='0')               //������һλΪ�ϸ�
    Turn(n-1);
  for(int i=n-2; i>=1; i--)       //����1~n-2λ��Ϊ�¸�
    if(sta[i]=='1')
      Turn(i);
  sta[n]=(sta[n]=='1'?'0':'1');   //��ת��ǰλ
  ans[++step]=sta.substr(1,9);    //���浱ǰ״̬
}

int main()
{
  freopen("ring.in","r",stdin);
  freopen("ring.out","w",stdout);
  for(int i=9; i>=1; i--)         //��Ϊ�����Ӱ��ǰ��ģ����ԴӺ���ǰ��ת
    Turn(i);
  while(cin>>num)
    cout<<(num>step?"-1":ans[num])<<endl;
  return 0;
}
