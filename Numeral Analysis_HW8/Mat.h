#pragma once
#include <iostream>
#include <vector>

class Mat
{
public:
	Mat(int r, int c);
	~Mat(void);

	friend Mat operator + (const Mat& a, const Mat& b);
	friend Mat operator - (const Mat& a, const Mat& b);
	friend Mat operator *(const Mat& a, double b);
	friend Mat operator * (double a, const Mat& b);
	friend Mat operator * (const Mat& a, const Mat& b);

	std::vector<double>& operator [] (int index);

	Mat t();
	static double dot(const Mat&a, const Mat& b);
	double absmax();

	int r, c;
	std::vector<std::vector<double> > data;
};

std::ostream& operator << (std::ostream &out, const Mat& a);