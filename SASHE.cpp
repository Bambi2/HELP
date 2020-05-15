#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void rectangle(int n) {
	double a = 2.0, b = 50.0, h = (b - a) / n, x, sum = 0, answer;
	
	x = a;

	for (int i = 0; i < n; i++) {
		sum += sqrt(1 + 2 * log(x)) / x;
		x += h;
	}
	answer = h * sum;
	
	cout << "Rectangle: (n = " << n << ") " << setprecision(10) << answer <<  endl;
}

void trapeze(int n) {
	double a = 2.0, b = 50.0, h = (b - a) / n, x, sum = 0, answer;

	x = a;

	for (int i = 0; i <= n; i++) {
		if (i == 0 ||i == n) {
			sum += 0.5 * (sqrt(1 + 2 * log(x)) / x);
		}
		else {
			sum += sqrt(1 + 2 * log(x)) / x;
		}

		x += h;
	}

	answer = h * sum;

	cout << "Trapeze: (n = " << n << ") " << setprecision(10) << answer << endl;
}

void simpson(int n) {
	double a = 2.0, b = 50.0, h = (b - a) / (2 * n), x, sum = 0, answer;

	x = a;

	for (int i = 0; i <= 2 * n; i++) {
		

		if (i != 0 && i != (2 * n) && i % 2 == 1) {
			sum += 4 * (sqrt(1 + 2 * log(x)) / x);
		}
		else if (i != 0 && i != (2 * n) && i % 2 == 0) {
			sum += 2 * (sqrt(1 + 2 * log(x)) / x);
		}
		else {
			sum += (sqrt(1 + 2 * log(x)) / x);
		}

		x += h;
	}

	answer = h / 3 * sum;

	cout << "Simpson (n = " << n << ") " << setprecision(10) << answer << endl;
}


	
	


int main()
{
	int n = 10;

	rectangle(n);
	trapeze(n);
	simpson(n);
	cout << endl;

	n = 20;

	rectangle(n);
	trapeze(n);
	simpson(n);
	cout << endl;

	n = 40;

	rectangle(n);
	trapeze(n);
	simpson(n);
	cout << endl;

	n = 80;

	rectangle(n);
	trapeze(n);
	simpson(n);
	cout << endl;

	n = 160;

	rectangle(n);
	trapeze(n);
	simpson(n);
	cout << endl;

	return 0;
}
