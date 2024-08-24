//时钟问题 —普通枚举
#include<bits/stdc++.h>
using namespace std;

int a[10],b[10];

int main()
{
  //freopen("clock.in","r",stdin);
  //freopen("clock.out","w",stdout);
  for(int i=1; i<=9; i++)
    cin>>a[i];
  for(int p1=0; p1<=3; p1++)
    for(int p2=0; p2<=3; p2++)
      for(int p3=0; p3<=3; p3++)
        for(int p4=0; p4<=3; p4++)
          for(int p5=0; p5<=3; p5++)
            for(int p6=0; p6<=3; p6++)
              for(int p7=0; p7<=3; p7++)
                for(int p8=0; p8<=3; p8++)
                  for(int p9=0; p9<=3; p9++)
                    if((p1+p2+p4)%4==(4-a[1])%4
                        && (p1+p2+p3+p5)%4==(4-a[2])%4
                        &&(p2+p3+p6)%4==(4-a[3])%4
                        && (p1+p4+p5+p7)%4==(4-a[4])%4
                        &&(p1+p3+p5+p7+p9)%4==(4-a[5])%4
                        && (p3+p5+p6+p9)%4==(4-a[6])%4
                        &&(p4+p7+p8)%4==(4-a[7])%4
                        && (p5+p7+p8+p9)%4==(4-a[8])%4
                        &&(p6+p8+p9)%4==(4-a[9])%4)
                    {
                      b[1]=p1;
                      b[2]=p2;
                      b[3]=p3;
                      b[4]=p4;
                      b[5]=p5;
                      b[6]=p6;
                      b[7]=p7;
                      b[8]=p8;
                      b[9]=p9;
                      for(int i=1; i<=9; i++)
                        if(b[i]>0)
                          for(int j=1; j<=b[i]; j++)
                            cout<<i;
                      cout<<endl;
                      return 0;
                    }
}
