#include <iostream>

using namespace std;

class Komplex {
	double re, im;
public:
	Komplex(double r = 0, double i = 0) : re(r), im(i) {};

	Komplex operator+(const Komplex& k) const
	{
		Komplex sum(k.re + re, k.im + im);
		return sum;
	}
	Komplex operator+(const double r) const
	{
		return operator+(Komplex(r));
	}
	operator double() const
	{
		return re;
	}
	double getRe() const
	{
		return re;
	}
	double getIm() const
	{
		return im;
	}
};

ostream& operator<< (ostream& os, const Komplex& k)
{
	os << k.getRe() << ',' << k.getIm() << 'j' << endl;
	return os;
}


int main()
{
	Komplex k1(4, 2);
	cout << k1 + 3.14;
}