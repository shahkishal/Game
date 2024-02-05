#include <stdio.h>
#include <dos.h>

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