/*
 ===============================================================
 Name        : wave_depth.cpp
 Author      : Hamed Mohammadi
 Version     :
 Copyright   : GNU General Public License
 Description : Wave Heigth on a slope
 ===============================================================
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {
	double t = 2.8, h = 1.9, g = 9.806, pi = 3.14;
	double x = 0;
	double l2 = 10.124;
	double k2 = 2 * pi / 10.124;
	double n2 = 0.5 * (1 + (2 * k2 * h) / sinh(2 * k2 * h));
	double h2 = 0.5;

	cout << fixed << "X\t\th\t\tL\t\tk\t\tn\t\tH\t\tH/h" << endl;

	int i = 1;
	bool not_broken = true;
	while (not_broken) {
		double x = i * 1;
		h = 1.9 - i * 0.05;
		double l_0 = (g * pow(t, 2)) / (2 * 3.14);
		double l = l_0;

		bool test = true;
		while (test) {
			double k = 2 * pi * h / l;
			double f = l - l_0 * tanh(k);
			double fp = 1
					+ (g * pow(t, 2) * h / pow(l, 2))
					* pow(1.0 / cosh(k), 2);
			double ln = l - f / fp;
			if (fabs(l - ln) < 0.001)
				test = false;
			l = ln;
		}

		double k = 2 * pi / l;
		double n = 0.5 * (1 + (2 * k * h) / sinh(2 * k * h));
		double h1 = h2 * sqrt((n2 * l2) / (n * l));

		if(h1/h >= 0.9) {
			not_broken = false;
			break;
		}

		cout << x << "\t" << h << "\t" << l << "\t"
				<< k << "\t" << n << "\t"
				<< h1 << "\t" << h1/h << endl;

		i++;
	}
	return 0;
}
