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
	for(int i=0;i<=128;)//------------------------�ɻ�
	{
		x=rand()%16;
		y=rand()%8;
		if(cell[x][y]==false)//���Ϊ����ִ������Ĵ��룬
		{
			sprintf(num,"%d",i);
			outtextxy(x*30,y*30,num);//���Խ�Ҫ����Ĳ�ȷ��������sprintf���棬�����
			cell[x][y]=true;//���Ϊ�ǿգ�
			i++;
		}
		Sleep(1);
		if(kbhit())
			break;
	}
	closegraph();
}
/*�����ע�͵��Ǹ�for�˻��ɣ�
for(int i=0;i<=128;i++)
{
   do
   {
      x=rand()%16;
	  y=rand()%8;
   }while(cell[x][y]==true);//���Ϊtrue����do��ֱ��false
      cell[x][y]=true;
	  sprintf(num,"%d",i);
	  outtextxy(x*30,y*30,num);
	  if(kbhit())
	     break;
}*/
