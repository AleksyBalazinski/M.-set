#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;
const int max_it = 100;
const int max_x = 300; //this can be changed
const int max_y = 200;

int main()
{
	initwindow(max_x, max_y);
	double cr, ci;
	double scale = max_x / 3;
	double zoom = 1;
	double Re = -1.769383179195515018213;
	double Im = 0.0042368479187367722149;
	for (int i = 0; i < 100; i++)
	{
		for (int y = 0; y < max_y; y++) //coloring every pixel
		{
			for (int x = 0; x < max_x; x++)
			{
				//cr = (static_cast<double>(x) / (scale))  - 2 + Re;
				cr = 1.5 * (x - max_x / 2) / (0.5 * zoom * max_x) + Re;
				ci = (y - max_y / 2) / (0.5 * zoom * max_y) + Im;
				//ci = ((-1) * (static_cast<double>(y) / (scale)))  + 1 + Im;
				double old_zr, old_zi, new_zi, new_zr;
				int n = 0;
				old_zr = 0;
				old_zi = 0;
				new_zr = 0;
				new_zi = 0;
				for (n = 0; n < max_it; n++)
				{
					old_zr = new_zr;
					old_zi = new_zi;
					new_zr = old_zr * old_zr - old_zi * old_zi + cr;
					new_zi = 2 * old_zr * old_zi + ci;
					if ((new_zr * new_zr + new_zi * new_zi) > 4) break;
				}
				if (n == max_it) putpixel(x, y, BLACK);
				else
				{
					double q = sqrt(new_zr * new_zr + new_zi * new_zi);
					int brightness = 256 * log(1.75 + n - log(log(q)));
					putpixel(x, y, COLOR(brightness, brightness, 255));
				}
			}
		}
		std::cout << "zoom = " << zoom << " ";
		std::cout << "iteration = " << i << " ";
		zoom = (zoom+1)*i*0.5;
	}
	getch();
	closegraph();
}
