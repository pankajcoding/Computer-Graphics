#include <iostream>
using namespace std;
void setPixel(int x,int y){
    cout<<"\n pixel x: "<<x<<" y: "<<y;
}

void lineBres(int x0, int y0, int xEnd, int yEnd)
{
	int x, y;

	if (x0 > xEnd){
		x = xEnd;
		y = yEnd;
		xEnd = x0;
		yEnd = y0;
	}
	else{
		x = x0;
		y = y0;
	}

	int dx = abs(xEnd - x), dy = yEnd - y, ady = abs(dy);
	double px = 2 * ady - dx;
	double py = 2 * dx - ady;
	double twoDy = 2 * ady, twoDyMinesDx = 2 * (ady - dx);
	double twoDx = 2 * dx, twoDxMinesDy = 2 * (dx - ady);

	setPixel(x, y);

	if (ady < dx){
		while (x < xEnd){
			x += 10;
			if (px < 0)
				px += twoDy;
			else{
				if (dy > 0)
					y += 10;
				else
					y -= 10;
				px += twoDyMinesDx;
			}
			setPixel(x, y);
		}
	}
	else{
		if (dy > 0){
			while (y < yEnd){
				y += 10;
				if (py < 0){
					py += twoDx;
				}
				else{
					x += 10;
					py += twoDxMinesDy;
				}
				setPixel(x, y);
			}
		}
		else{
			while (y > yEnd){
				y -= 10;
				if (py < 0){
					py += twoDx;
				}
				else{
					x += 10;
					py += twoDxMinesDy;
				}
				setPixel(x, y);
			}
		}
	}
}


main()
{
    int x1, y1, x2, y2;
    cout << "Enter Point 1: ";
    cout<<"\n x1 = ";
    cin >> x1 ;
    cout<<"y1 = ";
    cin >> y1;
    cout << "Enter Point 2: ";
    cout<<"\n x2 = ";
    cin >> x2 ;
    cout<<" y2 = ";
    cin >> y2;
    lineBres(x1,y1,x2,y2);
}


