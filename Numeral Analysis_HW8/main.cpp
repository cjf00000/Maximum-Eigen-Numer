#include <iostream>
#include "Mat.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

ofstream fout("output.txt");

void powerEigen(Mat a, int Rayleigh = 0)
{
	assert(a.r==a.c);
	Mat v(a.r, 1);
	for (int i=0; i<a.r; ++i)
		v[i][0] = 1;

	Mat u = v;
	double lambda = 1;
	for (int iter=1; ; ++iter)
	{
		v = a*u;
		u = v * (1.0/v.absmax());
		double newLambda = Rayleigh ? Mat::dot(a*u, u)/Mat::dot(u,u) : v.absmax();
		if (fabs(newLambda-lambda)<1e-5)
			break;		
		lambda = newLambda;
		cout << "Iteration #" << iter << " lambda= " << fixed << lambda << endl;
		fout << iter << "\t" << fixed << lambda << "\n" ;
	}
	cout << "Finished." << endl;
}

int main()
{
	cout.precision(7);
	Mat a(3,3);
	a[0][0] = -5;	a[0][1] = -4;	a[0][2] = 1;
	a[1][0] = -4;	a[1][1] = 6;	a[1][2] = -4;
	a[2][0] = 1;	a[2][1] = -4;	a[2][2] = 7;

	Mat b(4,4);
	b[0][0] = 25;	b[0][1] = -41;	b[0][2] = 10;	b[0][3] = -6;
	b[1][0] = -41;	b[1][1] = 68;	b[1][2] =-17;	b[1][3] = 10;
	b[2][0] = 10;	b[2][1] = -17;	b[2][2] = 5;	b[2][3] = -3;
	b[3][0] = -6;	b[3][1] = 10;	b[3][2] = -3;	b[3][3] = 2;

	powerEigen(a);
	powerEigen(a, 1);
	powerEigen(b);
	powerEigen(b, 1);

	system("pause");
}