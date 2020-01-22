#include <iostream>
// #include <graphics.h>
 using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{

	if (x0 > x1){
		int temp;
		temp=x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1=temp;
	}
    cout<<"Enter co-ordinates of first point: ";
    cout<<x0<<y0<<x1<<y1;
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<=x1)
	{
        cout<<"\n points: : "<<x<<" "<<y;
		if(p>=0)
		{
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			p=p+2*dy;
		}
		x=x+1;
	}
}
 
int main()
{
	int x0, y0, x1, y1;
 
	cout<<"Enter co-ordinates of first point: ";
	cin>>x0>>y0;
 
	cout<<"Enter co-ordinates of second point: ";
	cin>>x1>>y1;
	drawline(x0, y0, x1, y1);
 
	return 0;
}