//������ - ����
#include <bits/stdc++.h>
using namespace std;

const int MAXN=370000;
int final;
int Queue[MAXN], Deep[MAXN];
bool visit[MAXN];                        //��״̬�Ƿ��Ѿ����ֹ�
int s[9]= {1,2,3,8,0,4,7,6,5};           //���浱ǰ�������״̬
int front = 1,rear = 1;                  //������β

int To_Digit()                           //ת��������
{
  int ans = 0;
  for(int i = 0; i < 9; i++)
    ans = (ans<<3)+(ans<<1) + s[i];
  return ans;
}

int Cantor()                             //����չ��
{
  bool used[9] = {0};
  int ans = 0;
  for(int i = 8; i >= 1; i--)
  {
    int no = 0;
    used[s[8 - i]] = true;
    for(int j = 0; j < s[8 - i]; j++)    //�����Ƿ����ù�����
      if(used[j])
        no++;
    ans = (ans + s[8 - i] - no) * i;     //����չ��ʽ����
  }
  return ans;
}

void Ucan(int num)                       //�������е�����numչ����s[]
{
  for(int i = 8; i >= 0; i--)
  {
    s[i] = num % 10;
    num /= 10;
  }
}

int Findzero()                           //�ҵ�0��λ��
{
  for(int i = 0; i < 9; i++)
    if(s[i] == 0)
      return i;
}

void BFS(int c,int p)
{
  swap(s[p],s[p+c]);                     //��������
  int num = Cantor();
  if(!visit[num])
  {
    Queue[++rear] = To_Digit();          //��������
    visit[num] = true;
    Deep[rear] = Deep[front] + 1;
    if(num == final)                     //�õ���
      printf("%d\n",Deep[rear]),exit(0);
  }
  swap(s[p],s[p+c]);                     //�ָ�
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  final = Cantor();                      //��Ŀ��״̬����final
  for(int i = 0; i < 9; i++)             //��״̬תΪ9λ������n
    scanf("%d", &s[i]);
  Queue[1] = To_Digit();                 //��ʼ״̬�������
  visit[Cantor()] = true;                //��״̬�����Ϊ�Ѵ���
  if(visit[final] == true)               //��״̬��ĩ״̬
  {
    printf("0\n");
    return 0;
  }
  while(front <= rear)
  {
    Ucan(Queue[front]);                  //�����׵����л�ԭ��s[]����
    int p = Findzero();                  //����0��λ��
    if(p >= 3)                           //��������
      BFS(-3,p);
    if(p < 6)
      BFS(3,p);                          //��������
    if((p % 3) > 0)
      BFS(-1,p);                         //��������
    if((p % 3) < 2)
      BFS(1,p);                          //��������
    front++;                             //����Ԫ�س���
  }
  printf("-1\n");
  return 0;
}

