#include<iostream>
#include<graphics.h>

using namespace std;

int main()
{
  	initwindow(500,500,"HELLO");
  
  	int w,x,y,z,t,i=0;

	x=100;	y=200;
	w=100;	z=100;
	
	int arrx[100] ;
	int arry[100];
	arrx[i]=x;
	arry[i]=y;	
	
	int lastx,lasty;
	
	bool game=true;
	
	while(game)
	{		
		if(arrx[0]==w&&arry[0]==z)
		{
			w=(1+rand()%500);
			z=(1+rand()%500);
			i++;
			arrx[i]=lastx;
			arry[i]=lasty;
		}	
		w=w/20;
		w=w*20;
		z=z/20;
		z=z*20;	
		bar(w,z,w+20,z+20);
			
		for(int j=i;j>0;j--) // CHANGING HEAD TO TAIL FOR MOVING
		{
			arrx[j]=arrx[j-1];
			arry[j]=arry[j-1];
		}
		
		lastx=arrx[i];
		lasty=arry[i];
		
		if(GetAsyncKeyState(VK_UP)&&t!=1)
		{
			t=0;
		}
		else if(GetAsyncKeyState(VK_DOWN)&&t!=0)
		{
			t=1;
		}
		else if(GetAsyncKeyState(VK_RIGHT)&&t!=3)
		{
			t=2;
		}
		else if(GetAsyncKeyState(VK_LEFT)&&t!=2)
		{
			t=3;	
		}
		
		switch(t)
		{
			case 0:arry[0]-=20;break;
			case 1:arry[0]+=20;break;
			case 2:arrx[0]+=20;break;
			case 3:arrx[0]-=20;break;
			default:break;
		}
		
		
		for(int j=0;j<=i;j++)
		{	
			rectangle(arrx[j],arry[j],arrx[j]+20,arry[j]+20);
			if(arrx[0]==arrx[j]&&arry[0]==arry[j]&&j!=0 || arrx[0]>500 || arrx[0]<0  || arry[0]>500 || arry[0]<0)
			{
				game=false;
			}
		}
		
	
		delay(100);
		cleardevice();
	}
	getch();
}


