#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
	int x,y;
	char num[4];
	srand((unsigned)time(NULL));
	initgraph(640,480);
	for(x=0;x<=480;x+=30)
	{
		for(y=0;y<=240;y+=30)
		{
			line(x,0,x,240);
			line(0,y,480,y);
		}
	}
	bool cell[16][8];
	for(x=0;x<16;x++)
	{
		for(y=0;y<8;y++)
		{
			cell[x][y]=false;
		}
	}
	for(int i=0;i<=128;)//------------------------可换
	{
		x=rand()%16;
		y=rand()%8;
		if(cell[x][y]==false)//如果为空则执行里面的代码，
		{
			sprintf(num,"%d",i);
			outtextxy(x*30,y*30,num);//可以将要输出的不确定内容用sprintf储存，在输出
			cell[x][y]=true;//标记为非空，
			i++;
		}
		Sleep(1);
		if(kbhit())
			break;
	}
	closegraph();
}
/*上面的注释的那个for克换成：
for(int i=0;i<=128;i++)
{
   do
   {
      x=rand()%16;
	  y=rand()%8;
   }while(cell[x][y]==true);//如果为true继续do，直到false
      cell[x][y]=true;
	  sprintf(num,"%d",i);
	  outtextxy(x*30,y*30,num);
	  if(kbhit())
	     break;
}*/
