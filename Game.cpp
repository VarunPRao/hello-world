#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<stdio.h>

//Function to calculate perpendicular distnace from a line to a point.
float linedistance(int x, int y, int hX, int hY)
{
 float dist,A,B,C;
 if(x!=0)
 {
  A=1;
  B=y;
  C=-x;
  }
 else
 {
  B=1;
  A=x;
  C=-y;
  }

 dist=abs((((A*hX)+(B*hY)+C)/(sqrt((A*A)+(B*B)))));

 return dist;
 }

//Function to produce a certain sound.
void noise(int x)
{
 sound(700);
 delay(80);
 nosound();
 }

//Function to calculate distance between two points.
float distance(int x1, int x2, int y1, int y2)
{
 float dis;
 float xdis=x2-x1;
 float ydis=y2-y1;
 dis=sqrt(pow(xdis,2)+pow(ydis,2));
 return dis;
 }

//Function to change directon of the square.
int direction(char x)
 {
  int count;
  switch(x)
    {
     case 77: count=1;
	       break;
     case 75: count=2;
	      break;
     case 72: count=3;
	      break;
     case 80:count=4;
	      break;
     case 27 :count=5;
	      break;
     }
    return count;
  }

//Function to create a border.
void border(int a, int b)
{
 setcolor(15);
 setfillstyle(SOLID_FILL,GREEN);
 rectangle(0,0,a,b);
 rectangle(5,5,a-5,b-5);
 floodfill(1,1,WHITE);
 }

void main()
{

 //Initializing graphics mode.
 int gd = DETECT,gm;
 initgraph(&gd,&gm,"C://TURBOC3/BGI");

 //Initializing variables required.
 int mx,my,speed=5,cx,cy,count=1,ch,menu,lives=5,mmenu,mmenuselec=1,diamonds=0;
 int head_posX=40,boo,gemone=0,gemtwo=0,gemthree=0,gemfour=0,prevcom,once[4]={0,0,0,0};
 int headposY=200,page=0,minx=5,miny=5,nextry=5,ccy=210,count2=0,count3=0,D[163];
 mx=getmaxx();
 my=getmaxy();
 cx=mx/2;
 cy=my/2;
 float d1,d2,d3,d4,d5,dg1,dg2,dg3,dg4,a[8];
 int blobposX=cx-10,blobposY=ccy-30,blob2posX=cx-250,blob2posY=40,blob3posY=my-105;
 int bblobposX=mx-20, bblobposY=ccy,x,y,i,blob4posX=mx-55,blob4posY=ccy+160,count4=0;
 int l1points[66]={cx+42,my-162,cx+42,my-70,5,my-70,5,ccy+35,207,ccy+35,207,my-140,212,my-140,212,ccy+30,212,ccy+30,5,ccy+30,5,ccy-30,212,ccy-30,212,80,207,80,207,ccy-35,5,ccy-35,5,5,cx+42,5,cx+42,122,mx-105,122,mx-105,117,cx+47,117,cx+47,5,mx-5,5,mx-5,my-70,cx+47,my-70,cx+47,my-157,mx-105,my-157,mx-105,my-162,cx+42,my-162};
 int gem1[12]={30,ccy-70,46,ccy-70,52,ccy-64,38,ccy-48,24,ccy-64,30,ccy-70};
 int gem2[12]={30,ccy+60,46,ccy+60,52,ccy+66,38,ccy+82,24,ccy+66,30,ccy+60};
 int gem3[12]={cx+86,54,cx+102,54,cx+108,61,cx+94,77,cx+80,61,cx+86,54};
 int gem4[12]={cx+86,my-123,cx+102,my-123,cx+108,my-116,cx+94,my-100,cx+80,my-116,cx+86,my-123};
 char livescount[15],diacount[15];
 int p=cx+80,q=ccy-20;

 //Main menu.
 cleardevice();
 mainmenu:;
 setfillstyle(SOLID_FILL,RED);
 rectangle(0,0,mx,my);
 rectangle(5,5,mx-5,my-5);
 floodfill(1,1,WHITE);

 rectangle(p+20,q+50,p+80,q+100);
 rectangle(p+25,q+20,p+75,q+50);
 line(p,q+20,p+100,q+20);
 rectangle(p+25,q,p+75,q+20);
 rectangle(p,q+50,p+20,q+90);
 rectangle(p+80,q+50,p+100,q+90);
 circle(p+40,q+35,5);
 circle(p+60,q+35,5);
 setfillstyle(SOLID_FILL,RED);
 floodfill(p+25,q+55,WHITE);
 floodfill(p+30,q+5,WHITE);
 floodfill(p+85,q+55,WHITE);
 floodfill(p+5,q+55,WHITE);
 setfillstyle(SOLID_FILL,15);
 floodfill(p+26,q+21,WHITE);

 settextstyle(3,HORIZ_DIR,5);
 outtextxy(cx-150,40,"Diamond Hunter");
 settextstyle(8,HORIZ_DIR,3);
 outtextxy(cx-80,100,"Main Menu");
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(100,200,"PLAY");
 outtextxy(100,240,"INSTRUCTIONS");
 outtextxy(100,280,"EXIT");

 setcolor(15);
 rectangle(85,190,300,220);
 setcolor(0);
 rectangle(85,230,300,260);
 setcolor(0);
 rectangle(85,270,300,300);

 //Main menu selection.
 tryagain:;
 mmenu=getch();

 if(mmenu==72)
  --mmenuselec;
 else if(mmenu==80)
  ++mmenuselec;
 else if(mmenu==13)
 {
  if(mmenuselec==1)
   {
    nextry=5;
    lives=0;
    cleardevice();
    goto retry;
    }
  else if(mmenuselec==2)
   goto instructions;
  else if(mmenuselec==3)
   exit(0);
  }

 if(mmenuselec<=1)
 {
  setcolor(15);
  rectangle(85,190,300,220);
  setcolor(0);
  rectangle(85,230,300,260);
  rectangle(85,270,300,300);
  mmenuselec=1;
  nextry=5;
  goto tryagain;
  }
 else if(mmenuselec==2)
 {
  setcolor(15);
  rectangle(85,230,300,260);
  setcolor(0);
  rectangle(85,190,300,220);
  rectangle(85,270,300,300);
  goto tryagain;
  }
 else if(mmenuselec>=3)
 {
  setcolor(15);
  rectangle(85,270,300,300);
  setcolor(0);
  rectangle(85,230,300,260);
  rectangle(85,190,300,220);
  mmenuselec=3;
  goto tryagain;
  }

 //Instructions.
 instructions:;
 cleardevice();
 setbkcolor(1);

 border(mx,my);
 settextstyle(1,HORIZ_DIR,1);
 outtextxy(60,50,"Change direction of the square using the arrow keys.");
 outtextxy(60,100,"The objective is to collect the diamonds without");
 outtextxy(60,120,"being eaten by a blob or crashing into a wall.");
 outtextxy(60,170,"Try not to collide with the blue walls in and around");
 outtextxy(60,190,"the arena.");
 outtextxy(60,240,"Also avoid the circular blobs that move around the");
 outtextxy(60,260,"place.");
 outtextxy(60,310,"The yellow blobs move at high speeds in predetermined");
 outtextxy(60,330,"paths.");
 outtextxy(60,380,"The blue blob moves slowly, but follows you around the");
 outtextxy(60,400,"map. It can also move through walls.");
 getch();

 cleardevice();
 setbkcolor(0);
 mmenuselec=1;
 goto mainmenu;

 retry:;
 while(1)
 {
   cleardevice();

  //Resetting positions after restarting the game.
  if(nextry!=0)
  {
   head_posX=40;
   headposY=ccy-10;
   nextry=0;
   count=1;
   blob2posX=cx-240;
   blob2posY=40;
   count2=0;
   bblobposX=mx-20;
   bblobposY=ccy;
   count3=0;
   blobposX=cx-10;
   blobposY=ccy-30;
   count4=0;
   blob4posY=ccy+160;
   if(lives==0)
   {
    gemone=0;
    gemtwo=0;
    gemthree=0;
    gemfour=0;
    lives=5;
    diamonds=0;
    for(int i=0;i<4;++i)
     once[i]=0;
    }
   }

  //Rendering graphics.
  setcolor(15);
  rectangle (0,0,mx,my);
  rectangle (minx,my-65,mx-5,my-5);
  setfillstyle(SOLID_FILL,BLUE);
  drawpoly (33,l1points);
  floodfill(2,2,WHITE);

 //Rendering player depending on direction specified.
 if(count==4)
 {
  rectangle(head_posX+4,headposY+10,head_posX+16,headposY+20);
  rectangle(head_posX+5,headposY+4,head_posX+15,headposY+10);
  line(head_posX,headposY+4,head_posX+20,headposY+4);
  rectangle(head_posX+5,headposY,head_posX+15,headposY+4);
  rectangle(head_posX,headposY+10,head_posX+4,headposY+18);
  rectangle(head_posX+16,headposY+10,head_posX+20,headposY+18);
  circle(head_posX+8,headposY+7,1);
  circle(head_posX+12,headposY+7,1);
  setfillstyle(SOLID_FILL,RED);
  floodfill(head_posX+5,headposY+11,WHITE);
  floodfill(head_posX+6,headposY+1,WHITE);
  floodfill(head_posX+17,headposY+11,WHITE);
  floodfill(head_posX+1,headposY+11,WHITE);
  setfillstyle(SOLID_FILL,15);
  floodfill(head_posX+6,headposY+5,WHITE);
  }

 if(count==3)
 {
  rectangle(head_posX+4,headposY+10,head_posX+16,headposY+20);
  rectangle(head_posX+5,headposY+4,head_posX+15,headposY+10);
  line(head_posX,headposY+4,head_posX+20,headposY+4);
  rectangle(head_posX+5,headposY,head_posX+15,headposY+4);
  rectangle(head_posX,headposY+10,head_posX+4,headposY+18);
  rectangle(head_posX+16,headposY+10,head_posX+20,headposY+18);
  setfillstyle(SOLID_FILL,RED);
  floodfill(head_posX+5,headposY+11,WHITE);
  floodfill(head_posX+6,headposY+1,WHITE);
  floodfill(head_posX+17,headposY+11,WHITE);
  floodfill(head_posX+1,headposY+11,WHITE);
  setfillstyle(SOLID_FILL,15);
  floodfill(head_posX+6,headposY+5,WHITE);
  }
 if(count==2)
 {
  rectangle(head_posX+4,headposY+10,head_posX+16,headposY+20);
  rectangle(head_posX+5,headposY+4,head_posX+15,headposY+10);
  line(head_posX,headposY+4,head_posX+20,headposY+4);
  rectangle(head_posX+5,headposY,head_posX+15,headposY+4);
  rectangle(head_posX+8,headposY+10,head_posX+12,headposY+18);
  circle(head_posX+8,headposY+7,1);
  setfillstyle(SOLID_FILL,RED);
  floodfill(head_posX+5,headposY+11,WHITE);
  floodfill(head_posX+6,headposY+1,WHITE);
  floodfill(head_posX+9,headposY+11,WHITE);
  setfillstyle(SOLID_FILL,15);
  floodfill(head_posX+6,headposY+5,WHITE);
  }

 if(count==1)
 {
  rectangle(head_posX+4,headposY+10,head_posX+16,headposY+20);
  rectangle(head_posX+5,headposY+4,head_posX+15,headposY+10);
  line(head_posX,headposY+4,head_posX+20,headposY+4);
  rectangle(head_posX+5,headposY,head_posX+15,headposY+4);
  rectangle(head_posX+8,headposY+10,head_posX+12,headposY+18);
  circle(head_posX+12,headposY+7,1);
  setfillstyle(SOLID_FILL,RED);
  floodfill(head_posX+5,headposY+11,WHITE);
  floodfill(head_posX+6,headposY+1,WHITE);
  floodfill(head_posX+9,headposY+11,WHITE);
  setfillstyle(SOLID_FILL,15);
  floodfill(head_posX+6,headposY+5,WHITE);
  }

  setfillstyle(SOLID_FILL,YELLOW);

  circle(blobposX,blobposY,10);
  floodfill(blobposX,blobposY,WHITE);
  circle(blob2posX,blob2posY,10);
  floodfill(blob2posX,blob2posY,WHITE);
  circle(blob2posX,blob3posY,10);
  floodfill(blob2posX,blob3posY,WHITE);
  circle(blob4posX,blob4posY,10);
  floodfill(blob4posX,blob4posY,WHITE);

  settextstyle(1,HORIZ_DIR,1);
  setfillstyle(SOLID_FILL,7);
  sprintf(livescount,"Lives: %d/5",lives);
  outtextxy(40,my-50,livescount);
  settextstyle(2,HORIZ_DIR,4);
  outtextxy(cx+50,my-50,"Hit esc to pause.");
  outtextxy(cx+50,my-30,"Use the arrow keys to change your direction.");
  settextstyle(1,HORIZ_DIR,1);
  sprintf(diacount,"Diamonds: %d/4",diamonds);
  outtextxy(180,my-50,diacount);

  //Checking whether the diamonds have been removed.
  if(gemone==0)
  {
   drawpoly(6,gem1);
   floodfill(31,ccy-69,WHITE);
   }
  if(gemtwo==0)
  {
   drawpoly(6,gem2);
   floodfill(31,ccy+61,WHITE);
   }
  if(gemthree==0)
  {
   drawpoly(6,gem3);
   floodfill(cx+87,55,WHITE);
   }
  if(gemfour==0)
  {
   drawpoly(6,gem4);
   floodfill(cx+87,my-122,WHITE);
   }

  //Rendering blue blob.
  setfillstyle(SOLID_FILL,BLUE);
  circle(bblobposX,bblobposY,10);
  floodfill(bblobposX,bblobposY,WHITE);

  //Calling function to check distance between two points.
  d1=distance(blobposX,head_posX+10,blobposY,headposY+10);
  d2=distance(blob2posX,head_posX+10,blob2posY,headposY+10);
  d3=distance(blob2posX,head_posX+10,blob3posY,headposY+10);
  d4=distance(bblobposX,head_posX+10,bblobposY,headposY+10);
  d5=distance(blob4posX,head_posX+10,blob4posY,headposY+10);
  dg1=distance(38,head_posX,ccy-59,headposY);
  dg2=distance(38,head_posX,ccy+71,headposY);
  dg3=distance(cx+94,head_posX,65,headposY);
  dg4=distance(cx+94,head_posX,my-111,headposY);

  //Victory conditions and screen.
  if((gemone==1)&&(gemtwo==1)&&(gemthree==1)&&(gemfour==1))
  {
   settextstyle(9,HORIZ_DIR,4);
   outtextxy(cx-101,cy-40,"VICTORY!");
   sound(200);
   delay(120);
   sound(700);
   delay(140);
   sound(200);
   delay(160);
   sound(1000);
   delay(200);
   nosound();
   getch();
   cleardevice();
   gemone=0;
   gemtwo=0;
   gemthree=0;
   gemfour=0;
   goto mainmenu;
   }

  //Going to 'Game Over' menu if points meet.
  if(d1<=25)
   goto out;
  if(d2<=25)
   goto out;
  if(d3<=25)
   goto out;
  if(d4<=25)
   goto out;
  if(d5<=25)
   goto out;

  //Checking if square hit the diamond.
  if(dg1<=30)
  {
   gemone=1;
   if(once[0]==0)
   {
    diamonds++;
    once[0]=1;
    noise(0);
    }
   }
  if(dg2<=30)
  {
   gemtwo=1;
   if(once[1]==0)
   {
    diamonds++;
    once[1]=1;
    noise(0);
    }
   }
  if(dg3<=30)
  {
   gemthree=1;
   if(once[2]==0)
   {
    diamonds++;
    once[2]=1;
    noise(0);
    }
   }
  if(dg4<=30)
  {
   gemfour=1;
   if(once[3]==0)
   {
    diamonds++;
    once[3]=1;
    noise(0);
    }
   }

  //Calling function to check distance between a point and line.
  D[0]=linedistance(209,0,head_posX+10,headposY+10);
  D[1]=linedistance(210,0,head_posX+10,headposY+10);
  D[2]=linedistance(0,ccy+32,head_posX+10,headposY+10);
  D[3]=linedistance(0,ccy+33,head_posX+10,headposY+10);
  D[4]=linedistance(cx+44,0,head_posX+10,headposY+10);
  D[5]=linedistance(cx+45,0,head_posX+10,headposY+10);
  D[6]=linedistance(0,my-159,head_posX+10,headposY+10);
  D[7]=linedistance(0,my-160,head_posX+10,headposY+10);
  D[8]=linedistance(0,119,head_posX+10,headposY+10);
  D[9]=linedistance(0,120,head_posX+10,headposY+10);
  D[10]=linedistance(cx+44,0,head_posX+10,headposY+10);
  D[11]=linedistance(cx+45,0,head_posX+10,headposY+10);
  D[12]=linedistance(209,0,head_posX+10,headposY+10);
  D[13]=linedistance(210,0,head_posX+10,headposY+10);
  D[14]=linedistance(0,ccy-33,head_posX+10,headposY+10);
  D[15]=linedistance(0,ccy-32,head_posX+10,headposY+10);


  //Going to 'Game Over' menu if point touches line.
  if((D[0]<=12)&&(headposY>=ccy+30)&&(headposY<=my-140))
   goto out;
  if((D[1]<=12)&&(headposY>=ccy+30)&&(headposY<=my-140))
   goto out;
  if((D[2]<=12)&&(head_posX>=5)&&(head_posX<=210))
   goto out;
  if((D[3]<=12)&&(head_posX>=5)&&(head_posX<=210))
   goto out;
  if((D[4]<=12)&&(headposY<=my-70)&&(headposY>=my-161))
   goto out;
  if((D[5]<=12)&&(headposY<=my-70)&&(headposY>=my-162))
   goto out;
  if((D[6]<=12)&&(head_posX>=cx+43)&&(head_posX<=mx-105))
   goto out;
  if((D[7]<=12)&&(head_posX>=cx+44)&&(head_posX<=mx-105))
   goto out;
  if((D[8]<=12)&&(head_posX>=cx+40)&&(head_posX<=mx-105))
   goto out;
  if((D[9]<=12)&&(head_posX>=cx+41)&&(head_posX<=mx-105))
   goto out;
  if((D[10]<=12)&&(headposY<=121)&&(headposY>=5))
   goto out;
  if((D[11]<=12)&&(headposY<=120)&&(headposY>=5))
   goto out;
  if((D[12]<=12)&&(headposY>=70)&&(headposY<=ccy-32))
   goto out;
  if((D[13]<=12)&&(headposY>=70)&&(headposY<=ccy-31))
   goto out;
  if((D[14]<=12)&&(head_posX>=5)&&(head_posX<=210))
   goto out;
  if((D[15]<=12)&&(head_posX>=5)&&(head_posX<=211))
   goto out;


  //Going to 'Game Over' menu if point touches borders.
  if((head_posX+20)>=(mx-5)||(headposY+20)>=(my-70))
   goto out;
  if((head_posX)<=(minx)||(headposY)<=(miny))
   goto out;

  //Storing the previous command in a variable before pausing.
  if(count!=5)
   prevcom=count;

   //Moving the square depending on direction inputted.
   if(count==1)
    head_posX+=speed;
   else if(count==2)
    head_posX-=speed;
   else if(count==3)
    headposY-=speed;
   else if(count==4)
    headposY+=speed;
   else if(count==5)
   {
    goto pause;
    }

   //Moving the middle yellow circle.
   if(count3==0)
    blobposX+=2*speed;
   else if(count3==1)
    blobposY+=2*speed;
   else if(count3==2)
    blobposX-=2*speed;
   else if(count3==3)
    blobposY-=2*speed;

   //Specifying direction to move the middle yellow circle.
   if((blobposX==cx-10)&&(blobposY==ccy-30))
    count3=0;
   else if((blobposY==ccy-30)&&(blobposX==cx+160))
    count3=1;
   if((blobposX==cx+160)&&(blobposY==ccy+30))
    count3=2;
   if((blobposY==ccy+30)&&(blobposX==cx-10))
    count3=3;

   //Specifying direction to move the other yellow circles.
   if(blob2posX>cx)
    count2=1;
   if(blob2posX<cx-250)
    count2=0;

   //Specifying direction of the yellow circle on the right.
   if(blob4posY==ccy-160)
    count4=0;
   else if(blob4posY==ccy+160)
    count4=1;

   //Moving the yellow circle on the right.
   if(count4==0)
    blob4posY+=2*speed;
   if(count4==1)
    blob4posY-=2*speed;

   //Moving the blue circle.
   if(bblobposX>head_posX+10)
    bblobposX-=(speed-4);
   if(bblobposX<head_posX+10)
    bblobposX+=(speed-4);
   if(bblobposY>headposY+10)
    bblobposY-=(speed-4);
   if(bblobposY<headposY+10)
    bblobposY+=(speed-4);

  //Moving the other yellow circles.
  if(count2==0)
    blob2posX+=2*speed;
   else if(count2==1)
    blob2posX-=2*speed;

   //Detecting if keyboard is hit, and calling the function to specify direction.
   if(kbhit())
   {
    count=direction(getch());
    }

  //Delaying to reduce rate of loops.
  delay(40);
  goto cont;

  //Pause menu.
  pause:;
  settextstyle(4,HORIZ_DIR,4);
  outtextxy(cx-90,ccy,"Game Paused");
  settextstyle(1,HORIZ_DIR,1);
  outtextxy(cx-110,ccy+40,"Hit a button to continue.");
  count=prevcom;
  getch();
  goto cont;

  //'Game Over' menu.
   out:;
   sound(350);
   delay(200);
   nosound();
   --lives;
   settextstyle(4,HORIZ_DIR,4);
   outtextxy(cx-80,cy,"Game Over");
   settextstyle(1,HORIZ_DIR,1);

   outtextxy(cx-70,cy+50,"RETRY");
   outtextxy(cx+20,cy+50,"MENU");
   rectangle(cx-75,cy+50,cx-10,cy+75);
   boo=1;

  //Selecting whether to retry or quit.
  select:;
  menu=getch();
  if(menu==75)
  {
   setcolor(0);
   rectangle(cx+15,cy+50,cx+75,cy+75);
   setcolor(15);
   rectangle(cx-75,cy+50,cx-10,cy+75);
   boo=1;
   goto select;
   }
  else if(menu==77)
  {
   setcolor(0);
   rectangle(cx-75,cy+50,cx-10,cy+75);
   setcolor(15);
   rectangle(cx+15,cy+50,cx+75,cy+75);
   boo=2;
   goto select;
   }
  else if(menu==13)
  {
   if(boo==2)
   {
    cleardevice();
    mmenuselec=1;
    goto mainmenu;
    }
   if(boo==1)
   {
    nextry=5;
    goto retry;
    }
   }
  else
   goto select;

  brk:;
  break;

  cont:;
 }

 closegraph();
 }
