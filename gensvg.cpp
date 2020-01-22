#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

//Global variables

unsigned int IMG_WIDTH;
unsigned int IMG_HEIGHT;

// Prolog for the SVG image

void header(unsigned int pixel_size) {

  cout << "<svg width=\"" << IMG_WIDTH*pixel_size 
       << "\" height=\"" << IMG_HEIGHT*pixel_size << "\" viewBox = \"0 0 " <<IMG_WIDTH<<" " << IMG_HEIGHT<< "\"  version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
  cout << "<title>Bar</title>" << endl;
}

// Epilog for the SVG image

void footer() {
  cout << "</svg>" << endl;
}

// Generation of margin

void margin(unsigned int margin_width)
{
   
    cout<<  "<rect x=\""<< margin_width <<"\" y=\""<< margin_width <<"\" height=\"" << IMG_WIDTH-2*margin_width << "\" width=\"" << IMG_HEIGHT-2*margin_width << "\" style=\"fill:none;stroke:black;stroke-width:1\"/>" << endl;
    
}
void line(int x1,int y1,int x2, int y2)
{  
    cout<<"here now";
    cout<<"<line x1=\""<< x1 <<"\" y1=\""<< y1 <<"\" x2=\""<< x2 <<"\" y2=\""<< y2 <<"\"  style=\"stroke:rgb(255,0,0);stroke-width:2\"/>" << endl;
    
}

//  <line x1="0" y1="0" x2="200" y2="200" style="stroke:rgb(255,0,0);stroke-width:2" />
// use rectangle element of svg to mark each pixel of the line by using Bresenham Line Drawing Algorithm

void draw_line_bresenham(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1)
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







// Read input and generate SVG image

int main() {
  int x0, y0, x1, y1;
  cout<<"Enter co-ordinates of first point: ";
	cin>>x0>>y0;
 
	cout<<"Enter co-ordinates of second point: ";
	cin>>x1>>y1;
  freopen("output.svg","w",stdout);
  unsigned int pixel_ratio = 10; // add provision to accept as input from user
  unsigned int margin_width = 1; // add provision to accept as input from user
  cout<<"Enter co-ordinates of second point------------------------------: ";
  //Accept user input
  // cin>>IMG_WIDTH>>IMG_HEIGHT;
  IMG_WIDTH=30;
  IMG_HEIGHT=30;
  
  header(pixel_ratio);
  margin(margin_width);
  line(x0,y0,x1,y1);
  // call line drawing function here 

	draw_line_bresenham(x0, y0, x1, y1);

  footer();
  return 0;

}
