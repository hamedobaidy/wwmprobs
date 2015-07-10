/*
 =============================================================
 Name        : sorensen2_4a.cpp
 Author      : Hamed Mohammadi
 Version     :
 Copyright   : GNU General Public License
 Description : Solve Dispersion Relationship for L
 =============================================================
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double t = 7.1, h = 6, g = 9.81, pi = 3.14;

	double l_0 = (g * pow(t, 2)) / (2 * 3.14);
	double l = l_0;

	bool test = true;
	while (test) {
		double k = 2 * pi * h / l;
		double f = l - l_0 * tanh(k);
		double fp = 1 + (g * pow(t, 2) * h / pow(l, 2))
				* pow(1.0 / cosh(k), 2);
		double ln = l - f / fp;
		if (fabs(l - ln) < 0.001)
			test = false;
		l = ln;
	}

	cout << "Wave length = " << l << endl;
	return 0;
}
