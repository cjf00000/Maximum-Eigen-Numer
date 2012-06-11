#include "Mat.h"
#include <cassert>
using namespace std;

Mat::Mat( int r, int c )
{
	this->r = r;
	this->c = c;
	data = std::vector<std::vector<double> >(r, std::vector<double>(c, 0));
}

Mat operator + (const Mat& a, const Mat& b)
{
	assert(a.r==b.r && a.c==b.c);

	Mat res = a;
	for (int i=0; i<a.r; ++i)
		for (int j=0; j<a.c; ++j)
			res.data[i][j] += b.data[i][j];
	return res;
}

Mat operator - (const Mat& a, const Mat& b)
{
	assert(a.r==b.r && a.c==b.c);

	Mat res = a;
	for (int i=0; i<a.r; ++i)
		for (int j=0; j<a.c; ++j)
			res.data[i][j] -= b.data[i][j];
	return res;
}

Mat operator * (const Mat& a, double b)
{
	Mat res = a;
	for (int i=0; i<a.r; ++i)
		for (int j=0; j<a.c; ++j)
			res.data[i][j] *= b;
	return res;
}

Mat operator * (double a, const Mat& b)
{
	return b*a;
}

Mat operator * (const Mat& a, const Mat& b)
{
	assert(a.c==b.r);

	Mat res(a.r, b.c);
	for (int i=0; i<a.r; ++i)
		for (int j=0; j<b.c; ++j)
			for (int k=0; k<a.c; ++k)
				res.data[i][j] += a.data[i][k] * b.data[k][j];
	return res;
}

std::vector<double>& Mat::operator [] (int index)
{
	return data[index];
}

Mat::~Mat(void)
{
}

Mat Mat::t()
{
	Mat res(c, r);
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			res.data[j][i] = data[i][j];
	return res;
}

double Mat::absmax()
{
	double res = 0;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			if (fabs(data[i][j])>res)
				res = fabs(data[i][j]);
	return res;
}

double Mat::dot( const Mat&a, const Mat& b )
{
	assert(a.r==b.r && a.c==b.c);
	double res = 0;
	for (int i=0; i<a.r; ++i)
		for (int j=0; j<a.c; ++j)
			res += a.data[i][j] * b.data[i][j];
	return res;
}

ostream& operator<<( ostream &out, const Mat& a )
{
	for (int i=0; i<a.r; ++i)
	{
		for (int j=0; j<a.c; ++j){
			out.width(10);
			out << a.data[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
