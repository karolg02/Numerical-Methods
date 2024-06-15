#include <iostream>
double f1(double x) {
	return (pow(x, 3) + pow(x, 2) - 3*x - 3);
}
double f2(double x) {
	return (pow(x, 2) - 2);
}
double f3(double x) {
	return (sin(pow(x, 2)) - pow(x, 2));
}
double f4(double x) {
	return (sin(pow(x, 2)) - pow(x, 2) + 0.5);
}
double bisekcja(double(*func)(double), double x1, double x2) {
	double epsilon = 0.00001;
	double x3 = 0;
	if (func(x1) * func(x2) < 0) {
		while (true) {
			x3 = (x1 + x2) / 2;
			if (fabs(func(x3)) < epsilon) {
				break;
			}
			if (func(x1) * func(x3) < 0) {
				x2 = x3;
			}
			else {
				x1 = x2;
				x2 = x3;
			}
		}
	}
	return x3;
}

double pegaz() {
	return 0;
}
int main() {

	std::cout << "Dla x^3+x^2-3x-3" << std::endl;
	std::cout << bisekcja(f1, -3.0, 3.0) << std::endl;

	std::cout << "Dla x^2 - 2" << std::endl;
	std::cout << bisekcja(f2, 0.0, 3.0) << std::endl;

	std::cout << "Dla sin(x^2)-2" << std::endl;
	std::cout << bisekcja(f3, -100, 100) << std::endl;

	std::cout << "Dla sin(x^2)-x^2+1/2" << std::endl;
	std::cout << bisekcja(f4, -10.0, 10.0) << std::endl;

	return 0;
}