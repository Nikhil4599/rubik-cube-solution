#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char f[3][3],b[3][3],l[3][3],r[3][3],bo[3][3],u[3][3],temp,t[3];
int top=-1,fq=-1,rq=-1;
char *stack[200][4],*queue[200][4];
void F()
{
    int i,j,k=3;
    while(k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = f[i][j];
            f[i][j] = f[j][3-1-i];
            f[j][3-1-i] = f[3-1-i][3-1-j];
            f[3-1-i][3-1-j] = f[3-1-j][i];
            f[3-1-j][i] = temp;
        }
    }

    t[0]=l[2][2];t[1]=l[1][2];t[2]=l[0][2];
    l[0][2]=bo[0][0];l[1][2]=bo[0][1];l[2][2]=bo[0][2];
    bo[0][0]=r[2][0];bo[0][1]=r[1][0];bo[0][2]=r[0][0];
    r[0][0]=u[2][0];r[1][0]=u[2][1];r[2][0]=u[2][2];
    u[2][0]=t[0];u[2][1]=t[1];u[2][2]=t[2];
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="F";}
    else{rq++;queue[rq][0]="F";}
    top++;
    stack[top][0]="Fi";
}
void Fi()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = f[i][j];
            f[i][j] = f[j][3-1-i];
            f[j][3-1-i] = f[3-1-i][3-1-j];
            f[3-1-i][3-1-j] = f[3-1-j][i];
            f[3-1-j][i] = temp;
        }
    }
    while(k--)
    {
    t[0]=l[2][2];t[1]=l[1][2];t[2]=l[0][2];
    l[0][2]=bo[0][0];l[1][2]=bo[0][1];l[2][2]=bo[0][2];
    bo[0][0]=r[2][0];bo[0][1]=r[1][0];bo[0][2]=r[0][0];
    r[0][0]=u[2][0];r[1][0]=u[2][1];r[2][0]=u[2][2];
    u[2][0]=t[0];u[2][1]=t[1];u[2][2]=t[2];
    }
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Fi";}
    else{rq++;queue[rq][0]="Fi";}
    top++;
    stack[top][0]="F";
}

void L()
{
    int i,j,k=3;
    while (k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = l[i][j];
            l[i][j] = l[j][3-1-i];
            l[j][3-1-i] = l[3-1-i][3-1-j];
            l[3-1-i][3-1-j] = l[3-1-j][i];
            l[3-1-j][i] = temp;
        }

    }
    k=3;
    while(k--)
    {
    t[0]=bo[0][0]; t[1]=bo[1][0]; t[2]=bo[2][0];
    bo[0][0]=b[0][0]; bo[1][0]=b[1][0]; bo[2][0]=b[2][0];
    b[0][0]=u[0][0]; b[1][0]=u[1][0]; b[2][0]=u[2][0];
    u[0][0]=f[0][0]; u[1][0]=f[1][0]; u[2][0]=f[2][0];
    f[0][0]=t[0];f[1][0]=t[1];f[2][0]=t[2];
   }
   if(rq==-1)
   {rq++;fq=0;queue[rq][0]="L";}
   else{rq++;queue[rq][0]="L";}
   top++;
   stack[top][0]="Li";
}
void Li()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = l[i][j];
            l[i][j] = l[j][3-1-i];
            l[j][3-1-i] = l[3-1-i][3-1-j];
            l[3-1-i][3-1-j] = l[3-1-j][i];
            l[3-1-j][i] = temp;
        }
    }

    t[0]=bo[0][0]; t[1]=bo[1][0]; t[2]=bo[2][0];
    bo[0][0]=b[0][0]; bo[1][0]=b[1][0]; bo[2][0]=b[2][0];
    b[0][0]=u[0][0]; b[1][0]=u[1][0]; b[2][0]=u[2][0];
    u[0][0]=f[0][0]; u[1][0]=f[1][0]; u[2][0]=f[2][0];
    f[0][0]=t[0];f[1][0]=t[1];f[2][0]=t[2];
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Li";}
    else{rq++;queue[rq][0]="Li";}
    top++;
    stack[top][0]="L";
}
void R()
{
    int i,j,k=3;
    while (k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = r[i][j];
            r[i][j] = r[j][3-1-i];
            r[j][3-1-i] = r[3-1-i][3-1-j];
            r[3-1-i][3-1-j] = r[3-1-j][i];
            r[3-1-j][i] = temp;
        }
    }
    t[0]=bo[0][2]; t[1]=bo[1][2]; t[2]=bo[2][2];
    bo[0][2]=b[0][2]; bo[1][2]=b[1][2]; bo[2][2]=b[2][2];
    b[0][2]=u[0][2]; b[1][2]=u[1][2]; b[2][2]=u[2][2];
    u[0][2]=f[0][2]; u[1][2]=f[1][2]; u[2][2]=f[2][2];
    f[0][2]=t[0];f[1][2]=t[1];f[2][2]=t[2];
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="R";}
    else{rq++;queue[rq][0]="R";}
    top++;
    stack[top][0]="Ri";
}
void Ri()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = r[i][j];
            r[i][j] = r[j][3-1-i];
            r[j][3-1-i] = r[3-1-i][3-1-j];
            r[3-1-i][3-1-j] = r[3-1-j][i];
            r[3-1-j][i] = temp;
        }
    }
    while (k--)
    {
    t[0]=bo[0][2]; t[1]=bo[1][2]; t[2]=bo[2][2];
    bo[0][2]=b[0][2]; bo[1][2]=b[1][2]; bo[2][2]=b[2][2];
    b[0][2]=u[0][2]; b[1][2]=u[1][2]; b[2][2]=u[2][2];
    u[0][2]=f[0][2]; u[1][2]=f[1][2]; u[2][2]=f[2][2];
    f[0][2]=t[0];f[1][2]=t[1];f[2][2]=t[2];
    }
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Ri";}
    else{rq++;queue[rq][0]="Ri";}
    top++;
    stack[top][0]="R";
}
void U()
{
    int i,j,k=3;
    while (k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = u[i][j];
            u[i][j] = u[j][3-1-i];
            u[j][3-1-i] = u[3-1-i][3-1-j];
            u[3-1-i][3-1-j] = u[3-1-j][i];
            u[3-1-j][i] = temp;
        }
    }
     t[0]=f[0][0];t[1]=f[0][1];t[2]=f[0][2];
     f[0][0]=r[0][0];f[0][1]=r[0][1];f[0][2]=r[0][2];
     r[0][0]=b[2][2];r[0][1]=b[2][1];r[0][2]=b[2][0];
     b[2][0]=l[0][2];b[2][1]=l[0][1];b[2][2]=l[0][0];
     l[0][0]=t[0];l[0][1]=t[1];l[0][2]=t[2];
     if(rq==-1)
    {rq++;fq=0;queue[rq][0]="U";}
    else{rq++;queue[rq][0]="U";}
     top++;
    stack[top][0]="Ui";
}
void Ui()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = u[i][j];
            u[i][j] = u[j][3-1-i];
            u[j][3-1-i] = u[3-1-i][3-1-j];
            u[3-1-i][3-1-j] = u[3-1-j][i];
            u[3-1-j][i] = temp;
        }
    }
    while(k--)
    {
     t[0]=f[0][0];t[1]=f[0][1];t[2]=f[0][2];
     f[0][0]=r[0][0];f[0][1]=r[0][1];f[0][2]=r[0][2];
     r[0][0]=b[2][2];r[0][1]=b[2][1];r[0][2]=b[2][0];
     b[2][0]=l[0][2];b[2][1]=l[0][1];b[2][2]=l[0][0];
     l[0][0]=t[0];l[0][1]=t[1];l[0][2]=t[2];
     }
     if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Ui";}
    else{rq++;queue[rq][0]="Ui";}
     top++;
    stack[top][0]="U";
}
void B()
{
    int i,j,k=3;
    while (k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = b[i][j];
            b[i][j] = b[j][3-1-i];
            b[j][3-1-i] = b[3-1-i][3-1-j];
            b[3-1-i][3-1-j] = b[3-1-j][i];
            b[3-1-j][i] = temp;
        }
    }
    t[0]=l[0][0];t[1]=l[1][0];t[2]=l[2][0];
    l[0][0]=u[0][2];l[1][0]=u[0][1];l[2][0]=u[0][0];
    u[0][0]=r[0][2];u[0][1]=r[1][2];u[0][2]=r[2][2];
    r[0][2]=bo[2][2];r[1][2]=bo[2][1];r[2][2]=bo[2][0];
    bo[2][0]=t[0];bo[2][1]=t[1];bo[2][2]=t[2];
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="B";}
    else{rq++;queue[rq][0]="B";}
    top++;
    stack[top][0]="Bi";
}
void Bi()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = b[i][j];
            b[i][j] = b[j][3-1-i];
            b[j][3-1-i] = b[3-1-i][3-1-j];
            b[3-1-i][3-1-j] = b[3-1-j][i];
            b[3-1-j][i] = temp;
        }
    }
    while(k--)
    {
    t[0]=l[0][0];t[1]=l[1][0];t[2]=l[2][0];
    l[0][0]=u[0][2];l[1][0]=u[0][1];l[2][0]=u[0][0];
    u[0][0]=r[0][2];u[0][1]=r[1][2];u[0][2]=r[2][2];
    r[0][2]=bo[2][2];r[1][2]=bo[2][1];r[2][2]=bo[2][0];
    bo[2][0]=t[0];bo[2][1]=t[1];bo[2][2]=t[2];
   }
   if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Bi";}
    else{rq++;queue[rq][0]="Bi";}
   top++;
    stack[top][0]="B";
}
void Bo()
{
    int i,j,k=3;
    while (k--)
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = bo[i][j];
            bo[i][j] = bo[j][3-1-i];
            bo[j][3-1-i] = bo[3-1-i][3-1-j];
            bo[3-1-i][3-1-j] = bo[3-1-j][i];
            bo[3-1-j][i] = temp;
        }
    }
    t[0]=b[0][0]; t[1]=b[0][1]; t[2]=b[0][2];
    b[0][0]=r[2][2];b[0][1]=r[2][1];b[0][2]=r[2][0];
    r[2][0]=f[2][0];r[2][1]=f[2][1];r[2][2]=f[2][2];
    f[2][0]=l[2][0];f[2][1]=l[2][1];f[2][2]=l[2][2];
    l[2][0]=t[2];l[2][1]=t[1];l[2][2]=t[0];
     if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Bo";}
    else{rq++;queue[rq][0]="Bo";}
     top++;
    stack[top][0]="Boi";
}
void Boi()
{
    int i,j,k=3;
    for (i = 0; i < 3 / 2; i++)
    {
        for (j = i; j< 3-1-i; j++)
        {
            temp = bo[i][j];
            bo[i][j] = bo[j][3-1-i];
            bo[j][3-1-i] = bo[3-1-i][3-1-j];
            bo[3-1-i][3-1-j] = bo[3-1-j][i];
            bo[3-1-j][i] = temp;
        }
    }
    while(k--)
    {
    t[0]=b[0][0]; t[1]=b[0][1]; t[2]=b[0][2];
    b[0][0]=r[2][2];b[0][1]=r[2][1];b[0][2]=r[2][0];
    r[2][0]=f[2][0];r[2][1]=f[2][1];r[2][2]=f[2][2];
    f[2][0]=l[2][0];f[2][1]=l[2][1];f[2][2]=l[2][2];
    l[2][0]=t[2];l[2][1]=t[1];l[2][2]=t[0];
    }
    if(rq==-1)
    {rq++;fq=0;queue[rq][0]="Boi";}
    else{rq++;queue[rq][0]="Boi";}
    top++;
    stack[top][0]="Bo";
}
void scan(char a[3][3],int n)
{
    int i,j,p=0,q=0,k=0;
    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            if((i==1&&j==0)&&(a[i][j]==bo[1][1])||(i==0&&j==1)&&(a[i][j]==bo[1][1])||(i==2&&j==1)&&(a[i][j]==bo[1][1])||(i==1&&j==2)&&(a[i][j]==bo[1][1]))
             {k++;}
    while(k!=0)
    {
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            if((i==1&&j==0)&&(a[i][j]==bo[1][1]))
            {
                p=i;
                q=j;
            }
        }
    }
    switch(n)
    {
            case 1:
                   if(p==1&&q==0)
                   {
                       if(u[1][0]!=bo[1][1])
                       {
                           Li();Li();k--;
                       }
                       else U();
                   }
                   else Bo();
            break;
            case 3:
                   if (p==1&&q==0)
                   {
                     if(u[1][0]!=bo[1][1])
                     {
                         Li();k--;
                     }
                     else
                     {
                        U();
                     }
                   }
                   else
                       F();
            break;
            case 4:
                   if (p==1&&q==0)
                   {
                     if(u[1][0]!=bo[1][1])
                     {
                         L();k--;
                     }
                     else
                     {
                        U();
                     }
                   }
                   else B();
            break;
            case 5:
                  if (p==1&&q==0)
                   {
                     if(u[2][1]!=bo[1][1])
                     {
                         Fi();k--;
                     }
                     else
                     {
                        U();
                     }
                   }
                   else R();
            break;
            case 6:
                  if (p==1&&q==0)
                   {
                     if(u[0][1]!=bo[1][1])
                     {
                         Bi();k--;
                     }
                     else
                     {
                        U();
                     }
                   }
                   else L();
            break;
        }
    }

}
void cross()
{
  void white_cross(char a[3][3],int n);
   scan(bo,1);
   scan(f,3);
   scan(b,4);
   scan(r,5);
   scan(l,6);
   scan(bo,1);
   scan(f,3);
   scan(b,4);
   scan(r,5);
   scan(l,6);
   scan(bo,1);
   scan(f,3);
   scan(b,4);
   scan(r,5);
   scan(l,6);
   scan(bo,1);
   scan(f,3);
   scan(b,4);
   scan(r,5);
   scan(l,6);
   white_cross(f,3);
   white_cross(b,4);
   white_cross(r,5);
   white_cross(l,6);
}
void white_cross(char a[3][3],int n)
{
    int k=4;
    while(k--)
    {
    switch(n)
    {
        case 3:
                if((a[1][1]==a[0][1])&&(u[2][1]==bo[1][1]))
                {F();F();}
                else U();
        break;
        case 4:
                if((a[1][1]==a[2][1])&&(u[0][1]==bo[1][1]))
                {B();B();}
                else U();
        break;
        case 5:
                if((a[1][1]==a[0][1])&&(u[1][2]==bo[1][1]))
                {R();R();}
                else U();
        break;
        case 6:
                 if((a[1][1]==a[0][1])&&(u[1][0]==bo[1][1]))
                 {L();L();}
                 else U();
        break;
    }
    }
}
void first_layer2()
{
    int k=4;
    void first_layer(char a[3][3],int num);
    while(k--)
    {first_layer(f,3);first_layer(f,3);
    first_layer(u,2);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    first_layer(u,2);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    first_layer(l,6);first_layer(f,3);first_layer(f,3);
    first_layer(r,5);first_layer(f,3);first_layer(f,3);
    first_layer(u,2);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    first_layer(u,2);first_layer(f,3);
    first_layer(b,4);first_layer(f,3);first_layer(f,3);
    }

}
void first_layer(char a[3][3],int num)
{
    int i,j,k=0,p=1,q=1,m=1,n=1,count=0;
                    for(i=0;i<=2;i++)
                    {
                          for(j=0;j<=2;j++)
                          {
                          if((i==0&&j==0)&&(a[i][j]==bo[1][1])||(i==0&&j==2)&&(a[i][j]==bo[1][1]))
                           {
                              p=i;
                              q=j;
                           }
                           if((i==2&&j==0)&&(a[i][j]==bo[1][1])||(i==2&&j==2)&&(a[i][j]==bo[1][1]))
                           {
                              m=i;
                              n=j;
                           }
                           }
                    }
                switch(num)
                {
                case 2:
                    for(i=0;i<=2;i++)
                   for(j=0;j<=2;j++)
                  if(((i==0&&j==0)&&(a[i][j]==bo[1][1]))||((i==0&&j==2)&&(a[i][j]==bo[1][1]))||((i==2&&j==0)&&(a[i][j]==bo[1][1]))||((i==2&&j==2)&&(a[i][j]==bo[1][1])))
                  {k++;}
                 while(k)
                 {
                if(a[0][0]==bo[1][1]&&bo[2][0]!=bo[1][1])
                {
                    L();U();Li();Ui();k=0;
                }
                else if(a[0][2]==bo[1][1]&&bo[2][2]!=bo[1][1])
                {
                    Ri();U();R();Ui();k=0;
                }
                else if(a[2][0]==bo[1][1]&&bo[0][0]!=bo[1][1])
                {
                    Li();U();L();Ui();k=0;
                }
                else if(a[2][2]==bo[1][1]&&bo[0][2]!=bo[1][1])
                {
                    R();U();Ri();Ui();k=0;
                }
                else U();
                 }
                break;
                case 3:
                    for(i=0;i<=2;i++)
                   for(j=0;j<=2;j++)
                  if(((i==0&&j==0)&&(a[i][j]==bo[1][1]))||((i==0&&j==2)&&(a[i][j]==bo[1][1]))||((i==2&&j==0)&&(a[i][j]==bo[1][1]))||((i==2&&j==2)&&(a[i][j]==bo[1][1])))
                  {k++;}
                while(k)
                {
                    for(i=0;i<=2;i++)
                    {
                          for(j=0;j<=2;j++)
                          {
                          if((i==0&&j==0)&&(f[i][j]==bo[1][1])||(i==0&&j==2)&&(f[i][j]==bo[1][1]))
                           {
                              p=i;
                              q=j;
                           }
                           if((i==2&&j==0)&&(f[i][j]==bo[1][1])||(i==2&&j==2)&&(f[i][j]==bo[1][1]))
                           {
                              m=i;
                              n=j;
                           }
                           }
                    }
                if((p==0&&q==0)||(p==0&&q==2))
                {
                   if(p==0&&q==0)
                   {
                        if((l[1][1]==l[0][2])&&(f[0][0]==bo[1][1]))
                        {
                            F();U();Fi();k--;
                        }
                        else if((f[1][1]==f[0][2])&&(r[0][0]==bo[1][1]))
                        {
                            R();U();Ri();k--;
                        }
                        else if((r[1][1]==r[0][2])&&(b[2][2]==bo[1][1]))
                        {
                            B();U();Bi();k--;
                        }
                        else if((b[1][1]==b[2][0])&&(l[0][0]==bo[1][1]))
                        {
                            L();U();Li();k--;
                        }
                        else Ui();
                    }
                    else if(p==0&&q==2)
                    {
                       if((r[1][1]==r[0][0])&&(f[0][2]==bo[1][1]))
                        {
                            Fi();Ui();F();k--;
                        }
                        else if((f[1][1]==f[0][0])&&(l[0][2]==bo[1][1]))
                        {
                            Li();Ui();L();k--;
                        }
                        else if((l[1][1]==l[0][0])&&(b[2][0]==bo[1][1]))
                        {
                            Bi();Ui();B();k--;
                        }
                        else if((b[1][1]==b[2][2])&&(r[0][2]==bo[1][1]))
                        {
                            Ri();Ui();R();k--;
                        }
                        else U();
                    }
                  }
                else if((m==2&&n==0)||(m==2&&n==2))
                 {
                   if(m==2&&n==0)
                   {
                       Li();U();L();k=0;
                   }
                   if(m==2&&n==2)
                   {
                       R();Ui();Ri();k=0;
                   }
                 }
                 if(count==5)k=0; else count++;
                }
                break;
                case 4:
                if((m==2&&n==0)||(m==2&&n==2))
                {
                    U();U();
                }
                else if((p==0&&q==0)||(p==0&&q==2))
                {
                   if(p==0&&q==0){L();Ui();Li();U();U();}
                   else if(p==0&&q==2){Ri();U();R();U();U();}
                }
                break;
                case 5:

                if((p==0&&q==0)||(p==0&&q==2))
                U();
                else if((m==2&&n==0)||(m==2&&n==2))
                {
                   if(m==2&&n==0){Fi();U();F();U();}
                   else if(m==2&&n==2){B();Ui();Bi();U();}
                }
                break;
                case 6:
                if((p==0&&q==0)||(p==0&&q==2))
                Ui();
                else if((m==2&&n==0)||(m==2&&n==2))
                {
                   if(m==2&&n==2){F();Ui();Fi();Ui();}
                   else if(m==2&&n==0){Bi();U();B();Ui();}
                }
                break;
              }
}
void middle_layer2()
{int k=6;
    while(k--){
    middle_layer(f,3);middle_layer(f,3);
    middle_layer(r,5);middle_layer(f,3);
    middle_layer(l,6);middle_layer(f,3);
    middle_layer(b,4);middle_layer(f,3);

    middle_layer(f,3);middle_layer(f,3);
    middle_layer(r,5);middle_layer(f,3);
    middle_layer(l,6);middle_layer(f,3);
    middle_layer(b,4);middle_layer(f,3);
    }
}
void middle_layer(char a[3][3], int n)
{
    int i,j,k=1;
            if((f[0][1]!=u[1][1]&&u[2][1]!=u[1][1])||(b[2][1]!=u[1][1]&&u[0][1]!=u[1][1])||(r[0][1]!=u[1][1]&&u[1][0]!=u[1][1])||(l[0][1]!=u[1][1]&&u[1][2]!=u[1][1]))
            {switch (n)
            {
                case 3:
                       if(a[0][1]!=u[1][1]&&u[2][1]!=u[1][1])
                       {
                           while(k)
                           {
                           if(((f[1][1]==f[0][1])&&(u[2][1]==l[1][1]))||((f[1][1]==f[0][1])&&(u[2][1]==r[1][1])))
                            {
                                  if(u[2][1]==l[1][1])
                                  {Ui();Li();U();L();U();F();Ui();Fi();k=0;}
                               else if(u[2][1]==r[1][1])
                                  {U();R();Ui();Ri();Ui();Fi();U();F();k=0;}
                            }
                           else if(((l[1][1]==l[0][1])&&(u[1][0]==b[1][1]))||((l[1][1]==l[0][1])&&(u[1][0]==f[1][1])))
                               {
                                   if(u[1][0]==b[1][1]){Ui();Bi();U();B();U();L();Ui();Li();k=0;}
                                else if(u[1][0]==f[1][1]){U();F();Ui();Fi();Ui();Li();U();L();k=0;}
                               }
                           else if(((b[1][1]==b[2][1])&&(u[0][1]==r[1][1]))||((b[1][1]==b[2][1])&&(u[0][1]==l[1][1])))
                               {
                                   if(u[0][1]==r[1][1]){Ui();Ri();U();R();U();B();Ui();Bi();k=0;}
                                else if(u[0][1]==l[1][1]){U();L();Ui();Li();Ui();Bi();U();B();k=0;}
                               }
                           else if(((r[1][1]==r[0][1])&&(u[1][2]==f[1][1]))||((r[1][1]==r[0][1])&&(u[1][2]==b[1][1])))
                                {
                                    if(u[1][2]==f[1][1]){Ui();Fi();U();F();U();R();Ui();Ri();k=0;}
                                else if(u[1][2]==b[1][1]){U();B();Ui();Bi();Ui();Ri();U();R();k=0;}
                                }
                           else U();
                           }
                       }
                break;
                case 4:if(a[2][1]!=2&&u[0][1]!=2){U();U();}
                break;
                case 5:if(a[0][1]!=2&&u[1][2]!=2){U();}
                break;
                case 6:if(a[0][1]!=2&&u[1][0]!=2){Ui();}
                break;
            }}
            else
            {
            switch (n)
             {
                case 3:if((f[1][0]!=u[1][1]&&l[1][2]!=u[1][1])&&(f[1][0]!=f[1][1]&&l[1][2]!=l[1][1]))
                {Ui();Li();U();L();U();F();Ui();Fi();}
                break;
                case 4:if((b[1][2]!=u[1][1]&&r[1][2]!=u[1][1])&&(b[1][2]!=b[1][1]&&r[1][2]!=r[1][1]))
                {Ui();Ri();U();R();U();B();Ui();Bi();}
                break;
                case 5:if((r[1][0]!=u[1][1]&&f[1][2]!=u[1][1])&&(r[1][0]!=r[1][1]&&f[1][2]!=f[1][1]))
                {Ui();Fi();U();F();U();R();Ui();Ri();}
                break;
                case 6:if((l[1][0]!=u[1][1]&&b[1][0]!=u[1][1])&&(l[1][0]!=l[1][1]&&b[1][0]!=b[1][1]))
                {Ui();Bi();U();B();U();L();Ui();Li();}
                break;
            }}
}
   void uppercross()
   {
    int k=0;
    if((u[0][0]!=u[1][1])||(u[0][1]!=u[1][1])||(u[0][2]!=u[1][1])||(u[1][0]!=u[1][1])||(u[1][0]!=u[1][1])
          ||(u[1][2]!=u[1][1])||(u[2][0]!=u[1][1])||(u[2][1]!=u[1][1])||(u[2][2]!=u[1][1]))
    {
        while((u[0][1]!=u[1][1])||(u[1][0]!=u[1][1])||(u[1][2]!=u[1][1])||(u[2][1]!=u[1][1]))
            {
                if((u[0][1]==u[1][1])&&(u[1][0]==u[1][1]))
                {F();U();R();Ui();Ri();Fi();}
                else if((u[0][1]==u[1][1])&&(u[1][2]==u[1][1]))
                {L();U();F();Ui();Fi();Li();}
                else if((u[1][2]==u[1][1])&&(u[2][1]==u[1][1]))
                {B();U();L();Ui();Li();Bi();}
                else if((u[1][0]==u[1][1])&&(u[2][1]==u[1][1]))
                {R();U();B();Ui();Bi();Ri();}
                else
                { F();U();R();Ui();Ri();Fi();}
            }
    }
}
void fullupper()
{
    int i;
    printf("\n\t1.FOR GETTING FISH SHAPE TAKE CORNER COLOUR AT LEFT BOTTOM\n");
    do{
    printf("R U Ri U R U2 Ri\nif done enter (0)");scanf("%d",&i);if(i==0)printf("make right is your front\n");else printf("restart\n");}while(i==0);
    printf("\n\t2.FOR DIGONAL COLOUR \n");
    do{
    printf("R U Ri U R U2 Ri\nif done enter (0)");scanf("%d",&i);if(i==0)printf("make right is your front\n");else printf("restart\n");}while(i==0);

}
void headlight()
{
    int i;
    printf("\n\t1.ALGORITHUM\n");
    do{
    printf("Ri F Ri B B R Fi Ri B B R R \nif done enter (0)");scanf("%d",&i);if(i==0)printf("make right is your front\n");else printf("restart\n");}while(i==0);
    printf("\n\t2.ALGORITHUM\n");
    do{
    printf("R Ui R U R U R Ui Ri Ui R R\nif done enter (0)");scanf("%d",&i);if(i==0)printf("make right is your front\n");else printf("restart\n");}while(i==0);

}
void pop()
{
    if(top==-1)printf("\nStack is empty\n");
    else{while(top!=-1){printf(" %s ",stack[top][0]);top--;}}
}
void display_queue()
{
    if(fq==-1&&rq==-1)printf("\nQueue is empty\n");
    else{fq=0;while(fq<=rq){printf(" %s ",queue[fq][0]);fq++;}fq=-1;rq=-1;}
}
void read(char c[3][3])
{
    int i,j;
    char op;
    do{for(i=0;i<=2;i++)
       {
           fflush(stdin);
           for(j=0;j<=2;j++)
           {fflush(stdin);
                scanf("%c",&c[i][j]);
           }
           printf("\n");
       }printf("\nIF DONE PRESS \"ENTER\"");op=getch();printf("\n");}while(op!=13);
}
void display(char c[3][3])
{
    int i,j;
    for(i=0;i<=2;i++)
    {
           for(j=0;j<=2;j++)
           {
                printf("%c ",c[i][j]);
           }
           printf("\n");
    }
    printf("\n");
}
void print()
{
   printf("BACK   side\n");
   display(b);
   printf("UPPER side\n");
   display(u);
   printf("LEFT side\n");
   display(l);
   printf("FRONT side\n");
   display(f);
   printf("RIGHT side\n");
   display(r);
   printf("BOTTOM side\n");
   display(bo);
}
void choice()
{
    int option;
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("(  U=upper clockwise\tUi =upper anti clockwise\t)\n)  F=Front clockwise\tFi =Front anti clockwise\t)\n(  B=back clockwise\tBi =back anti clockwise\t\t(\n)  R=right clockwise\tRi =right anti clockwise\t)\n(  L=left clockwise\tLi =left anti clockwise\t\t(\n)  Bo =bottom clockwise\tBoi=bottom  anti clockwise\t)\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    do
   {
    printf("\n==========================");
    printf("\n||\tMENU\t\t||\n||1.Steps\t\t||\n||2.reverse Steps\t||\n||3.display all colors\t||\n||4.EXIST\t\t||\n||\t\t\t||\n||**Enter Your Choice**\t||\n||\t\t\t||\n");
    printf("==========================\n=>");
    scanf("%d",&option);
   switch(option)
   {
    case 1:display_queue();
    break;
    case 2:pop();
    break;
    case 3:print();
    break;
    case 4:top=-1;fq=-1;rq=-1;
    break;
   }
   }while(option!=4);
}
int main()
{
   printf("\t\t*****************************************");
   printf("\n\t\t*\t          NOTE:\t\t\t*\n\t\t*green => front\t\torange => left\t*\n\t\t*red   => right\t\tyellow => top\t*\n\t\t*White => bottom\tBlue   => Back\t*\n");
   printf("\t\t*****************************************");
   printf("\nenter cube color\n");
   printf("\nenter back side\n");
   read(b);
   printf("\nenter upper side\n");
   read(u);
   printf("\nenter left side\n");
   read(l);
   printf("\nenter front side\n");
   read(f);
   printf("\nenter right side\n");
   read(r);
   printf("\nenter bottom side\n");
   read(bo);
  printf("\nCross\n");
   cross();
   choice();
   printf("\nFirst Layer\n");
   first_layer2();
   choice();
   printf("\nMiddle Layer\n");
   middle_layer2();
   choice();
   printf("\nUPPER Cross \n");
   uppercross();
   choice();
   printf("\nFOR FULL LAYER\n");
   fullupper();
   printf("FOR SOLVING HEDLIGHTS OF LAST LAYER");
   headlight();
   return 0;
}
