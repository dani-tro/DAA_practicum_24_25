#include <bits/stdc++.h>

using namespace std;

int l, xb, yb, xm, ym;

double area(double ax, double ay, double bx, double by, double cx, double cy)
{
	return fabs((bx - ax) * (cy - by) - (cx - bx) * (by - ay)) / 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> l >> xb >> yb;
	cin >> xm >> ym;
	
	double ax, ay, bx, by, cx, cy;
	ax = ay = 0;
	bx = xb;
	by = yb;
	cx = 0;
	cy = l;
	
	if(area(ax, ay, cx, cy, xm, ym) == 0)
	{
		swap(bx, cx);
		swap(by, cy);
	}
	if(area(cx, cy, bx, by, xm, ym) == 0)
	{
		swap(ax, cx);
		swap(ay, cy);
	}
	
	double acm = area(ax, ay, cx, cy, xm, ym);
	double wh = area(ax, ay, bx, by, cx, cy);
	
	double bcm = wh - acm;
	
	if(acm < bcm)
	{
		swap(bx, ax);
		swap(by, ay);
	}
	
	double left = 0.0, right = 1.0, mid;
	
	//while(abs(area - wh / 2) < eps))
	
	for(int i = 0; i < 128; i++)
	{
		mid = (left + right) / 2;
		double xn = ax + (cx - ax) * mid;
		double yn = ay + (cy - ay) * mid;
		double ar = area(ax, ay, xn, yn, xm, ym);
		
		if(2 * ar > wh)
		{
			right = mid;
		}
		else 
		{
			left = mid;
		}
	}
	
	double xn = ax + (cx - ax) * left;
	double yn = ay + (cy - ay) * left;
	cout << setprecision(10) << xn << " " << yn << endl;	
	
	return 0;
}
