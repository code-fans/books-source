//����
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define p 1000000009
#define mod 1000000007

int c[260];
int cnt[20000];
char ch[MAXN];
long long H[MAXN];

void init()                                //�ַ�ӳ�䵽����
{
  for (int i='a'; i<='z'; ++i)
    c[i]=i-'a'+1;
  for (int i='A'; i<='Z'; ++i)
    c[i]=i-'A'+27;
  for (int i='0'; i<='9'; ++i)
    c[i]=i-'0'+53;
}

int main()
{
  freopen("interview.in","r",stdin);
  freopen("interview.out","w",stdout);
  init();
  int num;
  cin>>num;
  for (int i = 0; i < num; ++i)
  {
    scanf("%s",ch);
    int n = strlen(ch);
    for (int j=1; j<=n; ++j)               //����ÿ���ַ����Ĺ�ϣֵ
      H[j]=(H[j-1]*p+c[ch[j-1]]) % mod;
    cnt[i]=H[n];                           //��ÿ���ַ����Ĺ�ϣֵ����cnt[]
  }
  sort(cnt, cnt + num);//�������������uniqueȥ��,�ظ�Ԫ�ؽ����ں���
  printf("%d\n",unique(cnt,cnt+num)-cnt);  //���ȥ�غ�����鳤��
  return 0;
}

