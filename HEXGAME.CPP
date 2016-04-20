#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void left(int,int,int,int);
void left1(int,int,int,int,int);
void right(int,int,int,int);
void right1(int,int,int,int,int);
void main()
{
int gdriver=DETECT,gmode;
int i,a,b,c,d,e,f,g,h;
clrscr();
initgraph(&gdriver,&gmode,"C:\\TC\\BGI ");
line(320,100,310,110);
line(310,110,310,120);
line(310,120,320,130);
line(320,130,330,120);
line(330,120,330,110);
line(330,110,320,100);
a=310;
b=120;
c=320;
d=130;
left(a,b,c,d);
getch();
}
void left(int a,int b,int c,int d)
{
int i,g,h,e,f;
for(i=0;i<8;i++)
{
line(a,b,c-20,d);
line(a-10,b+10,c-20,d+10);
line(a-10,b+20,c-10,d+20);
line(a,b+30,c,d+10);
line(a+10,b+20,c,d);
g=a;
h=b+30;
e=c;
f=d+10;
a=a-10;
b=b+20;
c=c-10;
d=d+20;
}
right(320,130,330,120);
right(g,h,e,f);
}
void right(int g,int h,int e,int f)
{
int i,a,b,c,d,j=7;
for(i=0;i<8;i++)
{
line(g,h,e,f);
line(g,h,e-10,f+20);
line(g,h+10,e,f+30);
line(g+10,h+20,e+10,f+20);
line(g+20,h+10,e+10,f+10);
line(g+20,h,e,f);
a=g;
b=h+10;
c=e;
d=f+30;
g=g+10;
h=h+20;
e=e+10;
f=f+20;
if(a>=320 && a<=380 && b>=140 && b<=260 && c>=330 && c<=390 && d>=150 && d<=270)
{
left1(a,b,c,d,j) ;
}

j=j-1;
}
if(a==390 && b==280 && c==400 && d==290)
{
left1(a,b,c,d,7);
}
}
void left1(int a,int b,int c,int d,int j)
{
int i,e,g,h,f;
for(i=0;i<j;i++)
{
line(a,b,c-20,d);
line(a-10,b+10,c-20,d+10);
line(a-10,b+20,c-10,d+20);
line(a,b+30,c,d+10);
line(a+10,b+20,c,d);
g=a;
h=b+30;
e=c;
f=d+10;
a=a-10;
b=b+20;
c=c-10;
d=d+20;
if(g>=260 && g<=380 && h==290 && e>=270 && e<=390 && f==280)
{
right1(g,h,e,f,j-1);
}
}
}
void right1(int g,int h,int e,int f,int j)
{
int i,a,b,c,d;
for(i=0;i<j;i++)
{
line(g,h,e,f);
line(g,h,e-10,f+20);
line(g,h+10,e,f+30);
line(g+10,h+20,e+10,f+20);
line(g+20,h+10,e+10,f+10);
line(g+20,h,e,f);
g=g+10;
h=h+20;
e=e+10;
f=f+20;
}
}
