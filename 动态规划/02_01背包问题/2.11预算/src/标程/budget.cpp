//Ԥ��
//���ǵ�ÿ���������ֻ��2������,���Կ��Կ�����01�����ķ���
//ö������,��ôת��״̬��ʱ������⼸�����:
//1.ֻѡ�����Ͳ�ѡ
//2.ѡһ��������ͬʱѡһ������
//3.ѡһ��������ͬʱѡ����һ������
//4.ѡһ��������ͬʱѡ��������
#include <bits/stdc++.h>
using namespace std;

int mv[40000],mvp[40000],fv[40000][3],fvp[40000][3],f[40000];

int main()
{
  //freopen("budget.in","r",stdin);
  //freopen("budget.out","w",stdout);
  int m,n;
  cin>>n>>m;
  for(int i=1,v,p,q; i<=m; i++)
  {
    cin>>v>>p>>q;
    if(!q)                             //���������
    {
      mv[i]=v;
      mvp[i]=v*p;                      //������ֵ����Ҫ�ȳ˻�
    }
    else                               //����Ǹ���
    {
      fv[q][++fv[q][0]]=v;             //fv[q][0]ͳ�Ƹ�������
      fvp[q][fv[q][0]]=v*p;
    }
  }
  for(int i=1; i<=m; i++)              //ö����Ʒ
    for(int j=n; j>=mv[i]; j--)        //01�����Ż�ģ��
    {
      f[j]=max(f[j],f[j-mv[i]]+mvp[i]);//���1��ֻҪ�����Ͳ�Ҫ����
      if(j>=mv[i]+fv[i][1])            //���2�������͸���1������ѡ���Ľϴ�ֵ�Ƚ�
        f[j]=max(f[j],f[j-mv[i]-fv[i][1]]+mvp[i]+fvp[i][1]);
      if(j>=mv[i]+fv[i][2])            //���3�������͸���2������ѡ���Ľϴ�ֵ�Ƚ�
        f[j]=max(f[j],f[j-mv[i]-fv[i][2]]+mvp[i]+fvp[i][2]);
      if(j>=mv[i]+fv[i][1]+fv[i][2])   //���4��ȫ����Ҫ
        f[j]=max(f[j],f[j-mv[i]-fv[i][1]-fv[i][2]]+mvp[i]+fvp[i][1]+fvp[i][2]);
    }
  cout<<f[n]<<endl;                    //����ڼ�ֵΪnʱ�ܵõ������ֵ
  return 0;
}
