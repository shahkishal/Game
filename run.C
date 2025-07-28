#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdio.h>
#include <dos.h>

int a=0,point=0,remain=5,stop=30,max=0,z=0;
void my_sounds(void);

int music(int pitch, int time)
{
sound(pitch);
delay(time);
nosound();
return(0);
}



void my_sounds()
 {
      setcolor(9);
      settextstyle(0,0,2);
      outtextxy(255,195,"1");
      music(130, 200);
      delay(400);

       setcolor(BLACK);
      outtextxy(255,195,"1");
       setcolor(RED);
      outtextxy(255,195,"2");

      music(145, 200);
      delay(400);

      setcolor(BLACK);
      outtextxy(255,195,"2");
       setcolor(YELLOW);
      outtextxy(255,195,"3");

      music(166, 200);
      delay(400);

       setcolor(BLACK);
      outtextxy(255,195,"3");
       setcolor(GREEN);
      outtextxy(175,195,"!! START !!");
	music(66, 200);
      delay(200);
       setcolor(BLACK);
      outtextxy(175,195,"!! START !!");

      settextstyle(0,0,1);


 }
void back_sound()
 {
      music(330, 50);

 }
void lost()
{
	music(66, 300);
	delay(50);
	music(45, 300);
	delay(50);
	music(30, 900);
}
void won()
{
	music(366, 100);
	delay(50);
	music(326, 100);
	delay(50);
	music(366, 100);
	delay(50);
	music(386, 500);
}
void hit()
{
	music(66,100);
	music(45,100);
	music(30,100);
}

struct BMP

    {

      char Type[2];                 //File type. Set to "BM".

      unsigned long Size;           //Size in BYTES of the file.

      unsigned long Reserved;      //Reserved. Set to zero.

      unsigned long OffSet;        //Offset to the data.

      unsigned long headsize;      //Size of rest of header. Set to 40.

      unsigned long Width;         //Width of bitmap in pixels.

      unsigned long Height;        //  Height of bitmap in pixels.

      unsigned int  Planes;        //Number of Planes. Set to 1.

      unsigned int  BitsPerPixel;  //Number of Bits per pixels.

      unsigned long Compression;   //Compression. Usually set to 0.

      unsigned long SizeImage;      //Size in bytes of the bitmap.

      unsigned long XPixelsPreMeter;  //Horizontal pixels per meter.

      unsigned long YPixelsPreMeter;  //Vertical pixels per meter.

      unsigned long ColorsUsed;       //Number of colors used.

      unsigned long ColorsImportant;  //Number of "important" colors.

    };



    int ShowBMP(int x, int y, char* FileName)

    {

	int b,a;

	struct  BMP Obj;



	unsigned char* Datas;

	int in=0;

	unsigned char c=0;

	FILE * fp;



	fp = fopen(FileName,"rb");

	if(!fp){

	printf("Error : Unable to open file ..");

	exit(0);

	}



	fread(&Obj, sizeof(Obj), 1, fp);

	if(Obj.BitsPerPixel!=4)  // This isn't a 16 color bmp we can read;

	{

	 fclose(fp);

	 printf("Error : File format not supported ..");

	 exit(0);

	};

	fseek(fp,Obj.OffSet,SEEK_SET);

	Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));

	for(b=Obj.Height;b>=0;b--)

	{

	 fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);

	 c=0;

	 in=0;

	 for(a=0;a<=Obj.Width;a+=2)

	 {

	     c = (Datas[in] | 0x00) >>4;

	     putpixel(a+x,b+y,c);

	     c = (Datas[in] | 0xF0) & 0x0F;

	     putpixel(a+1+x,b+y,c);

	     in++;

	 }

	}

	free (Datas);

	fclose(fp);

	return 1;

    }
///---img end


void elements();
void result1()
{       int i=0;
	cleardevice();


	while(1)
	{       if(kbhit())
		{getch();
		break;
		}
	setcolor(WHITE);
		rectangle(235,190,395,290);
		setcolor(YELLOW);
		outtextxy(265,240,"!! YOU WON !!");
		delay(80);
		setcolor(GREEN);
		outtextxy(265,240,"!! YOU WON !!");
		setcolor(GREEN);
		rectangle(245,200,385,280);
		delay(80);

		if(i==0)
		{
			won();
			i++;


		}

	}
}
void result2()
{       int i=0;
	cleardevice();
	while(1)
	{       if(kbhit())
		break;

		setcolor(WHITE);
		rectangle(235,190,395,290);
		setcolor(BLUE);
		outtextxy(260,240,"!! YOU LOST !!");
		delay(80);
		setcolor(RED);
		outtextxy(260,240,"!! YOU LOST !!");
		rectangle(245,200,385,280);
		delay(80);
		if(i==0)
		{
		lost();
		i++;
		}

	}
}

void erase(int i)
{
		setcolor(BLACK);
		line(450-i,200,525-i,200);
		line(450-i,200,453-i,203);
		line(450-i,200,453-i,197);
}

void draw(int i)
{
		setcolor(WHITE);
		line(450-i,200,525-i,200);
		line(450-i,200,453-i,203);
		line(450-i,200,453-i,197);
}

void points_display(int score)
{   char str[100];
    sprintf(str,"%d",point);
    setcolor(BLACK);
    outtextxy(470,20,str);
    point=point+score;
    sprintf(str,"%d",point);
    setcolor(WHITE);
    outtextxy(470,20,str);

}
void anime(int i)
{       hit();

	erase(i);
	delay(200);
	draw(i);
	delay(200);
	erase(i);
	delay(200);
	draw(i);
	delay(200);
	erase(i);

}



void arrow(int level)
{    int i=0 , color;
	while(1)
	{



		delay(1);
		if(525-i+1<435){
		setcolor(BLACK);
		line(450-i+1,200,525-i+1,200);
		line(450-i+1,200,453-i+1,203);
		line(450-i+1,200,453-i+1,197);

		setcolor(WHITE);

		line(450-i,200,525-i,200);
		line(450-i,200,453-i,203);
		line(450-i,200,453-i,197);
				}
		if(200>=45+a && 200<=60+a && 450-i>=44 && 450-i<=54)
		{

			points_display(5);
			anime(i);
			break;
		}
		else if(200>=35+a && 200<=70+a && 450-i>=33 && 450-i<=43)
		{
			points_display(4);
			anime(i);
			break;
		}
		else if(200>=25+a && 200<=80+a && 450-i>=22 && 450-i<=32)
		{
			points_display(3);
			anime(i);
			break;
		}
		else if(200>=15+a && 200<=90+a && 450-i>=11 && 450-i<=21)
		{
			points_display(2);
			anime(i);
			break;
		}
		else if(200>=5+a && 200<=100+a && 450-i>=1 && 450-i<=10)
		{
			points_display(1);
			anime(i);
			break;
		}
		else if(450-i==0)
		{       anime(i);
			break;
		}
		//level 3
		if(level==3 || level ==5)
		{
			//rectangle(300,30+stop,320,100+stop);
		       if(450-i>=300 && 450-i<=320 && 200>=30+stop && 200<=100+stop)
		       {
				anime(i);
				break;
		       }
		       //rectangle(200,330-stop,220,400-stop);
		       if(level==5)
		       {
				if(450-i>=200 && 450-i<=220 && 200>=330-stop && 200<=400-stop)
				{
					anime(i);
					break;
				}

		       }
		}

	    i++;


	}
}

void target(int level)
{
	int ch,i;
	char str[100];

     while(1)
     {   if(level==1)
	 delay(3);
	 else if(level == 2)
	 delay(2);
	 else if(level == 3)
	 delay(3);
	 else if(level == 4)
	 {
		delay(0);
		level=3;
	 }
	 else
	 {
		delay(0)  ;
	 }

	if(kbhit())
	{ ch=getch();
		if(ch==27)
		break;
		if(ch==' ')
		{   if(level==3)
			arrow(3);
		    else if(level==5)
			arrow(5);
		    else
			arrow(1);
		sprintf(str,"No. of Arrows : %d",remain);
		setcolor(BLACK);
		outtextxy(395,35,str);

		remain--;
		sprintf(str,"No. of Arrows : %d",remain);
		setcolor(WHITE);
		outtextxy(395,35,str);
	      /*
		setcolor(WHITE);
		line(450,200,525,200);
		line(450,200,453,203);
		line(450,200,453,197);
		*/
		if(remain==0)
		       break;
		}


	}


	if(stop==300)
	{       setcolor(WHITE);
		rectangle(290,310,330,420);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(310,399,15);
		floodfill(310,331,15);
		setcolor(BLACK);
		rectangle(300,325,320,395);
		rectangle(290,310,330,420);


		 if(level==5){
		 setcolor(2);
		rectangle(200,60,220,130);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(210,129,2);
		floodfill(210,61,2);
		setcolor(BLACK);
		rectangle(200,60,220,130);

						     }
		stop=30;
	}

	setcolor(BLACK);
	if(level==3 || level==5)
	{       for(i=0;i<=5;i++)
		{delay(1);
		if(level==5 && 330-stop+i>=60)
		rectangle(200,330-stop+i,220,400-stop+i);
		rectangle(300,30+stop-i,320,100+stop-i);
		}

	}



		if(a==300) {
		back_sound();
		setcolor(5);
		rectangle(1,5+a-1,54,100+a-1);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(2,350,5);
		floodfill(50,350,5);
		setcolor(BLACK);
		rectangle(1,5+a-1,54,100+a-1);
		a=0;
		    }





	rectangle(1,5+a-1,10,100+a-1);
	rectangle(11,15+a-1,21,90+a-1);
	rectangle(22,25+a-1,32,80+a-1);
	rectangle(33,35+a-1,43,70+a-1);
	rectangle(44,45+a-1,54,60+a-1);




	setcolor(WHITE);

	if(level==3 || level==5)
	{
	rectangle(300,30+stop,320,100+stop);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(310,99+stop,15);

	}
	if(level==5 && 330-stop>=60)
	{
	rectangle(200,330-stop,220,400-stop);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(210,331-stop,15);
	}

	rectangle(1,5+a,10,100+a);

	setfillstyle(SOLID_FILL,WHITE);
	floodfill(5,99+a,15);

	rectangle(11,15+a,21,90+a);
	setfillstyle(SOLID_FILL,8);
	floodfill(16,89+a,15);

	rectangle(22,25+a,32,80+a);
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(26,79+a,15);

	rectangle(33,35+a,43,70+a);
	setfillstyle(SOLID_FILL,RED);
	floodfill(34,69+a,15);

	rectangle(44,45+a,54,60+a);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(45,59+a,15);

	a++;
	if(level==3 || level==5)
	stop=stop+5;

     }
}
void elements()
{      char str[100];

	 //goal
		setcolor(WHITE);
		outtextxy(90,5,"Target : ");
		setcolor(CYAN);
		outtextxy(160,5,"Score More Than 10 Points");
	//no of asetcolor(CYAN);

		sprintf(str,"No. of Arrows : %d",remain);
		setcolor(WHITE);
		outtextxy(395,35,str);
	//points
	outtextxy(395,20,"Points : ");
	//arrow

		line(450,200,525,200);
		line(450,200,453,203);
		line(450,200,453,197);
	//action
		setcolor(GREEN);
		outtextxy(135,35,"!! Press Space to Shoot !!");
	//wall
	ShowBMP(0,430,"C:\\TURBOC3\\Projects\\Game-M~1\\wall.BMP");
	ShowBMP(256,430,"C:\\TURBOC3\\Projects\\Game-M~1\\wall.BMP");
	//img pillar
	ShowBMP(393,379,"C:\\TURBOC3\\Projects\\Game-M~1\\obj.BMP");

	//img
	ShowBMP(400,143,"C:\\TURBOC3\\Projects\\Game-M~1\\cgg_img2.BMP");
	//img moon
	ShowBMP(570,3,"C:\\TURBOC3\\Projects\\Game-M~1\\moon.BMP");

	setcolor(WHITE);
	rectangle(385,0,535,50);
	rectangle(386,1,536,49);

	rectangle(85,0,534,50);
	rectangle(86,1,535,49);


}
void max1()
{    char str[100];
    if(point>=max)
    {
		setcolor(BLACK);
		sprintf(str,"HIGH SCORE : %d",max);
		outtextxy(393,7,str);
		max=point;

		setcolor(13);
		sprintf(str,"HIGH SCORE : %d",max);
		outtextxy(393,7,str);
    }
    else
    {

		setcolor(13);
		sprintf(str,"HIGH SCORE : %d",max);
		outtextxy(393,7,str);

    }

}
void gameover()
{
	char str[100];
	int i=0;


	cleardevice();
	sprintf(str,"HIGH SCORE : %d",max);
	outtextxy(15,10,str);
	setcolor(RED);
	settextstyle(0,0,5);
	outtextxy(135,160,"GAME OVER");
	settextstyle(0,0,3);



	while(1)
	{       if(kbhit())
		{getch();
		settextstyle(0,0,1);
		break;
		}
	setcolor(WHITE);
	       //	rectangle(235,190,395,290);
		setcolor(YELLOW);
		outtextxy(165,245,"!! YOU WON !!");
		delay(80);
		setcolor(GREEN);
		outtextxy(165,245,"!! YOU WON !!");
		setcolor(GREEN);
	       //	rectangle(245,200,385,280);
		delay(80);

		if(i==0)
		{
			won();
			i++;


		}

	}

}

int main()
{  int gm,gd;
   char str[100];
   gd=DETECT;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	elements();
	outtextxy(90,20,"Info   : ");
	setcolor(YELLOW);
	outtextxy(160,20,"Hit the target");
	max1();
	//level 1
	setcolor(YELLOW);
	outtextxy(550,10,"Level 1");
	//sound
	my_sounds();
	//arrow end
	target(1);
	//end
	if(point>=10)
	result1();
	else{
	result2();
	exit(0);
	}
	//max



	//level 2
	cleardevice();
	max1();
	setcolor(WHITE);
	outtextxy(90,20,"Info   : ");
	setcolor(YELLOW);
	outtextxy(160,20,"Hit the target with 2x speed");

	point=0;
	remain=5;
	a=0;
	elements();
	setcolor(YELLOW);

	outtextxy(550,10,"Level 2");
	//sound
	my_sounds();
	//arrow end
	target(2);
	//end
	if(point>=10)
	result1();
	else{
	result2();
	exit(0);
	}
	//level 3
	cleardevice();
	max1();
	point=0;
	remain=5;
	a=0;
	elements();
	setcolor(WHITE);
	outtextxy(90,20,"Info   : ");
	setcolor(YELLOW);
	outtextxy(160,20,"Avoid the obstacle");
	setcolor(YELLOW);
	outtextxy(550,10,"Level 3");
	//sound
	my_sounds();

	//arrow end
	target(3);
	//end
	if(point>=10)
	result1();
	else{
	result2();
	exit(0);
	}
	//level 4
	cleardevice();
	max1();
	point=0;
	remain=5;
	a=0;

	elements();
	setcolor(YELLOW);
	outtextxy(550,10,"Level 4");
	setcolor(WHITE);
	outtextxy(90,20,"Info   : ");
	setcolor(YELLOW);
	outtextxy(160,20,"Avoid obstacle with 2x speed");
	//sound
	my_sounds();


	//arrow end
	target(4);
	//end
	if(point>=10)
	result1();
	else{
	result2();
	exit(0);
	}
	//level 5
	cleardevice();
	max1();
	point=0;
	remain=5;
	a=0;

	elements();
	setcolor(YELLOW);
	outtextxy(550,10,"Level 5");
	setcolor(WHITE);
	outtextxy(90,20,"Info   : ");
	setcolor(YELLOW);
	outtextxy(160,20,"Avoid two obstacles");
	//sound
	my_sounds();
	//arrow end
	target(5);
	//end
	if(point>=10)
	gameover();
	else{
	result2();
	exit(0);
	}

closegraph();
return 0;
}
