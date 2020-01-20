#include <iostream>
using namespace std;
main()
{
    int x1, y1, x2, y2;
    cout << "Enter Point 1: ";
    cin >> x1 >> y1;
    cout << "Enter Point 2: ";
    cin >> x2 >> y2;
    int m;
    m = (y2 - y1) / (x2 - x1);
    int c = y1 - m * x1;
    cout << "m= " << m;
    int x, y;
    for (x = x1; x <= x2; x++)
    {
        y = m * x + c;
        cout << "x = " << x << "y = " << y << " \n";
    }
}
