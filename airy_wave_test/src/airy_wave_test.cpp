/*
 =============================================================
 Name        : airy_wave_test.cpp
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
	double t = 2.8, h = 1.9, g = 9.806, pi = 3.14;

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
