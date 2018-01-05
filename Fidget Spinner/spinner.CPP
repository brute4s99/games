#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#define mid (110+78)/2
#define fps 60
int b_lvl,f_lvl;
void naming();
void fall();
void flask();
void burettelvl();
void flasklvl();
void quad(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy);
void burette();
void load();
void main(){
int v1,v2;
float n1,n2;
char val[50],i=0;
int gd=DETECT,gm;
clrscr();
printf("Normality of given sol : ");
scanf("%f",&n1);
printf("Vol of given sol taken in flask : ");
scanf("%d",&v1);
printf("Vol of KMnO4 used : ");
scanf("%d",&v2);
if(v2+v1>50 ){ printf("Flask will overflow !!");
getch();
return;}
printf("Let's Experiment !");
getch();
clrscr();
b_lvl=0;
f_lvl=v1;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
burette();
burettelvl();
flasklvl();
sprintf(val,"Normality of given sol = %f N",n1);
outtextxy(200,100,val);
sprintf(val,"Vol of given sol in the flask = %d ml",v1);
outtextxy(200,120,val);

for(i=0;i<v2;i++){
setcolor(WHITE);
if(i!=0){
	n2=n1*v1/i;
	sprintf(val,"Normality of KMnO4 = %f N",n2);}
else sprintf(val,"Normality of KMnO4 = ??? N");
outtextxy(200,110,val);
sprintf(val,"Vol of KMnO4 in the flask = %d ml",i);
outtextxy(200,130,val);
load();
setcolor(BLACK);
if(i!=0){
	sprintf(val,"Normality of KMnO4 = %f N",n2);}
else sprintf(val,"Normality of KMnO4 = ??? N");
outtextxy(200,110,val);
sprintf(val,"Vol of KMnO4 in the flask = %d ml",i);
outtextxy(200,130,val);
}
setcolor(CYAN);
n2=n1*v1/i;
sprintf(val,"Normality of KMnO4 = %f N",n2);
outtextxy(200,110,val);
sprintf(val,"Vol of KMnO4 in the flask = %d ml",i);
outtextxy(200,130,val);
setfillstyle(1,LIGHTMAGENTA);
setcolor(WHITE);
floodfill(mid,433,WHITE);
naming();
getch();
closegraph();
}
void naming(){
settextstyle(4,0,2);
outtextxy(350,316,"by Piyush Aggarwal");
settextstyle(7,0,3);
outtextxy(350,357,"06914802716");
}
void burette(){
int i;
quad(mid-68,450,mid+68,450,mid+60,435,mid-60,435);
line(32,388+50,10,388+50);
line(30,390+50,10,390+50);
line(10,390+50,10,15);
line(10,50,75,50);
line(10,52,75,52);
quad(75,46,78,46,78,56,75,56);
quad(75+35,46,79+35,46,79+35,56,75+35,56);
// burette
line(110,25,110,330);
line(78,25,78,330);
arc(mid,44,90-38,90+38,25);
line(mid-1,345,78,330);
line(mid+1,345,110,330);
ellipse(mid,344,0,360,3,1);       //(78+110)/2,344 is crit point
// MARKINGS
outtextxy(78+3,307,"50");
outtextxy(78+3,307-24*2,"40");
outtextxy(78+3,307-24*4,"30");
outtextxy(78+3,307-24*6,"20");
outtextxy(78+3,307-24*8,"10");
outtextxy(78+9,307-24*10,"0");
for(i=0;i<=50;i++){             // y=70<->310
	int a=70+4.8*i;
	if(i%10==0) line(98,a,110,a);
	else if(i%5==0) line(102,a,110,a);
	else line(105,a,110,a);
}
//FLASK
flask();
}
void flask(){

line(mid-40,434,mid+40,434);
line(mid-40,434,mid-40,430);
line(mid+40,434,mid+40,430);
line(mid-40,430,mid-12,380);
line(mid+40,430,mid+12,380);
line(mid+12,380,mid+12,360);
line(mid-12,380,mid-12,360);
ellipse(mid,357,0,360,16,4);
ellipse(mid,356,0,360,10,4);
}
void burettelvl(){
int y=b_lvl;
setcolor(WHITE);
y=y*2.4*2+70;
line(78,y,110,y);
setfillstyle(1,MAGENTA);
floodfill(79,1+y,WHITE);
setcolor(MAGENTA);
line(78,y,110,y);
setcolor(WHITE);
burette();
}
void quad(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy){
line(ax,ay,bx,by);
line(bx,by,cx,cy);
line(cx,cy,dx,dy);
line(ax,ay,dx,dy);
}
void load(){
int i;
setfillstyle(1,MAGENTA);
for(i=0;i<fps;i++){
setcolor(MAGENTA);       //fps=60
ellipse(mid,344+i/10,0,360,i/20,i/10);
floodfill(mid,344+i/10,MAGENTA);
delay(1000/60);
setcolor(WHITE);
ellipse(mid,344,0,180,3,1);
}
b_lvl++;
fall();
}
void fall(){
float n;
int i;
setcolor(LIGHTMAGENTA);
ellipse(mid,350,0,360,3,6);
setfillstyle(1,BLACK);
floodfill(mid,350,LIGHTMAGENTA);
n=(b_lvl-1)*2*2.4+70;
quad(78,70,110,70,110,n+4.8,78,n+4.8);
floodfill(78+1,n+1,LIGHTMAGENTA);
setcolor(BLACK);
ellipse(mid,350,0,360,3,6);
line(78,70,110,70);
line(78,n,110,n);
line(78,n+4.8,110,n+4.8);
//floodfill(mid,344,BLACK);
setcolor(WHITE);
burette();
burettelvl();
flasklvl();
for(i=5;i<fps-5;i++){
int y=346+i*88/60.0;
setfillstyle(1,LIGHTMAGENTA);
setcolor(LIGHTMAGENTA);
ellipse(mid,y,0,360,4,5);
floodfill(mid,y,LIGHTMAGENTA);
setcolor(WHITE);
ellipse(mid,357,0,360,16,4);
ellipse(mid,356,0,360,10,4);
delay(1000/60);
setfillstyle(1,BLACK);
setcolor(BLACK);
ellipse(mid,y,0,360,4,5);
floodfill(mid,y,BLACK);
setcolor(WHITE);
ellipse(mid,357,0,360,16,4);
ellipse(mid,356,0,360,10,4);
if(getpixel(mid+5,y+5)==LIGHTMAGENTA||getpixel(mid+5,y+4)==LIGHTMAGENTA) break;
}
setfillstyle(1,LIGHTMAGENTA);
f_lvl++;
flasklvl();
}
void flasklvl(){
int y,x1,x2,i;
setcolor(WHITE);
y=434-f_lvl*77/50.0;
if(y>=430){x1=mid-40;x2=mid+40;}
else if(y>=380){ for(i=mid;i>mid-40;i--) if(getpixel(i,y)==WHITE){ x1=i; break;} x2=mid+mid-x1;}
else{x1=mid-12;x2=mid+12;}
line(x1,y,x2,y);
setfillstyle(1,BLACK);
floodfill(mid,y+1,WHITE);
setcolor(LIGHTMAGENTA);
line(x1,y,x2,y);
setcolor(WHITE);
flask();
}